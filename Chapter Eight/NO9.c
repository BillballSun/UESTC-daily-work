/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
/* NO10.c (Chapter 7, page 111) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf getchar putchar*/
#include <stdlib.h> /*system abs(int) srand rand*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper tolower*/
#include <math.h> /*sqrt fabs(double) trunc*/
#include <string.h> /*mencpy*/
#include <time.h> /*time*/
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*********************
 * #define Bool int  *
 * typedef int Bool; *
 *********************/
 #define side_length 10
 #define up 0
 #define right 1
 #define down 2
 #define left 3

 int main(void)
 {
	 unsigned char board[10][10];
	 bool direct[4],checkpoint;
	 unsigned short int i,ii,t,x,y,amount_random,seed;
	 short int find_direct;
	 unsigned char ch;
	 srand((unsigned)time(NULL));
	 printf("Generating a 10x10 board to do things.\n");
	 for(i=0;i<=side_length-1;i++)
		 for(ii=0;ii<=side_length-1;ii++)
			 board[i][ii]='.';
	 checkpoint=false;
	 x=0;y=0;board[x][y]='A';
	 for(ch='B';ch<='Z'&&(!checkpoint);ch++)
	 {
		 if (x>=1&&board[x-1][y]=='.') direct[up]=true; else direct[up]=false;
		 if (y<=9&&board[x][y+1]=='.') direct[right]=true; else direct[right]=false;
		 if (x<=9&&board[x+1][y]=='.') direct[down]=true; else direct[down]=false;
		 if (y>=1&&board[x][y-1]=='.') direct[left]=true; else direct[left]=false;
		 amount_random=0;
		 for(t=0;t<=3;t++)
			 if (direct[t]) amount_random=amount_random+1;
		 if (amount_random==0) checkpoint=true;
		 else
		 {
			 if (amount_random==1) {for(t=0;t<=3;t++) if (direct[t]) find_direct=t;}
			 else
		     {
			     seed=rand()%amount_random;
			     seed=seed+1;
			     find_direct=-1;
			     while(seed>0)
			     {
			    	 find_direct++;
				     if (direct[find_direct]) seed=seed-1;
			     }
		     }
			 switch(find_direct)
			 {
				 case    up:x=x-1;board[x][y]=ch;break;
				 case right:y=y+1;board[x][y]=ch;break;
				 case  down:x=x+1;board[x][y]=ch;break;
				 case  left:y=y-1;board[x][y]=ch;break;
			 }
		 }
		 
	 }
	 if (checkpoint) printf("WARNING, It trapped by self. How silly it randomly is.\n");
	 printf("The result is showing as below.\n");
	 printf("-------------------------------\n");
	 for(i=0;i<=side_length-1;i++)
	 {
		 for(ii=0;ii<=side_length-1;ii++)
			 putchar(board[i][ii]);
		 putchar('\n');
	 }
	 printf("-------------------------------\n");
	 printf("The result is showing as above.\n");
	 if (checkpoint) printf("A-Z line is not acomplished due to the control.\n");
	 system("pause");
	 return 0;
 }