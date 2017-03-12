/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
/* NO1.c (Chapter 9, page 151) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf getchar putchar*/
#include <stdlib.h> /*system abs(int) srand rand*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper tolower isalpha isupper islower*/
#include <math.h> /*sqrt fabs(double) trunc*/
#include <string.h> /*mencpy*/
#include <time.h> /*time*/
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*********************
 * #define Bool int  *
 * typedef int Bool; *
 *********************/
/********************************************************
 *PC-Lint check                                         *
 *C:/Lint/Lint-nt -i"C:/Lint" -u cmd_std.lnt D:/lint.cpp*
 ********************************************************/
#define Length 10
#define Up 0
#define Right 1
#define Down 2
#define Left 3
void Generate_radom_walk(char walk[Length][Length])
{
	unsigned char ch;
	int x_position,y_position,random_seed,direct,get_random;
	bool checkpoint;
	int possible_direction[4];
	srand((unsigned)time(NULL));
	for(int i=0;i<=Length-1;i++)
		for(int ii=0;ii<=Length-1;ii++)
			walk[i][ii]='.';
	ch='A';
	x_position=0;y_position=0;
	walk[x_position][y_position]=ch;
	checkpoint=false;
	for(ch='B';ch<='Z'&&!checkpoint;ch++)
	{
		for(int i=Up;i<=Left;i++) possible_direction[i]=false;
		if (y_position>=1        && walk[x_position][y_position-1]=='.') possible_direction[Up]=true;
		if (x_position<=Length-2 && walk[x_position+1][y_position]=='.') possible_direction[Right]=true;
		if (y_position<=Length-2 && walk[x_position][y_position+1]=='.') possible_direction[Down]=true;
		if (x_position>=1        && walk[x_position-1][y_position]=='.') possible_direction[Left]=true;
		random_seed=0;
		for(int i=Up;i<=Left;i++) if (possible_direction[i]) random_seed=random_seed+1;
		if (random_seed==0) checkpoint=true;
		else if (random_seed==1) {for(int i=Up;i<=Left;i++) if(possible_direction[i]) direct=i;}
		else
		{
			get_random=rand()%random_seed+1;
			direct=-1;
			do
			{
				direct=direct+1;
				if(possible_direction[direct]) get_random=get_random-1;
			}while(get_random>=1);
		}
		if (!checkpoint)
			switch(direct)
			{
				case Up:
				y_position=y_position-1;walk[x_position][y_position]=ch;break;
				case Right:
				x_position=x_position+1;walk[x_position][y_position]=ch;break;
				case Down:
				y_position=y_position+1;;walk[x_position][y_position]=ch;break;
				case Left:
				x_position=x_position-1;;walk[x_position][y_position]=ch;break;
			}
	}
}
void Print_Length_line(int length)
{
	for(int i=1;i<=length;i++)
		printf("=");
	printf("\n");
}
void Show_walk(char walk[Length][Length])
{
	bool end_z;
	Generate_radom_walk(walk);
	end_z=false;
	for(int i=0;i<=Length-1&&!end_z;i++)
		for(int ii=0;ii<=Length-1&&!end_z;ii++)
			if (walk[i][ii]=='Z') end_z=true;
	printf("Generated a %dx%d board for walking from A to Z randomly.\n",Length,Length);
	Print_Length_line(Length);
	for(int i=0;i<=Length-1;i++)
	    {
		    for(int ii=0;ii<=Length-1;ii++) putchar(walk[ii][i]);
			putchar('\n');
		}
	Print_Length_line(Length);
	if(!end_z) printf("Warning, CAN\'T reach Z due to it trapped by itself.\n");
}
int main(void)
{
	char walk[Length][Length];
	for(int i=0;i<=Length-1;i++)
		for(int ii=0;ii<=Length-1;ii++)
			walk[i][ii]='.';
	Show_walk(walk);
	system("pause");
	return 0;
}