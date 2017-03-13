/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
**********************************************************/
/* NO6.c (Chapter 10, page 171) */
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
**********************/
/************************************************
 *srand((unsigned)time(NULL));                  *
 *rand() to get a 0-maxint number, use %amount. *
*************************************************/
/********************************************************
 *PC-Lint check                                         *
 *C:/Lint/Lint-nt -i"C:/Lint" -u cmd_std.lnt D:/lint.cpp*
*********************************************************/
/*********************************************
 *system("chcp 437>nul.");Show ASCII extended*
**********************************************/

/*
ASCII info

Left_up 218
Left_down 192
Right_up 191
Right_down 217
Vertical 179
Level 196
Space 32
Link_UpDown_right 195
Link_UpDown_left 180
*/

/*One step, modify the whole program*/
#define Max_digits 7

#define Left_up '\xDA'
#define Left_down '\xC0'
#define Right_up '\xBF'
#define Right_down '\xD9'
#define Vertical '\xB3'
#define Level '\xC4'
#define Space '\x20'
#define Link_UpDown_right '\xC3'
#define Link_UpDown_left '\xB4'

const int Digit[10][5][3]=
{
	/*0*/{{Left_up,Level,Right_up},
	      {Vertical,Space,Vertical},
		  {Vertical,Space,Vertical},
		  {Vertical,Space,Vertical},
		  {Left_down,Level,Right_down}},
	/*1*/{{Space,Space,Space},
	      {Space,Space,Vertical},
		  {Space,Space,Vertical},
		  {Space,Space,Vertical},
		  {Space,Space,Space}},
	/*2*/{{Space,Level,Right_up},
	      {Space,Space,Vertical},
		  {Left_up,Level,Right_down},
		  {Vertical,Space,Space},
		  {Left_down,Level,Space}},
	/*3*/{{Space,Level,Right_up},
	      {Space,Space,Vertical},
		  {Space,Level,Link_UpDown_left},
		  {Space,Space,Vertical},
		  {Space,Level,Right_down}},
	/*4*/{{Space,Space,Space},
	      {Vertical,Space,Vertical},
		  {Left_down,Level,Link_UpDown_left},
		  {Space,Space,Vertical},
		  {Space,Space,Space}},
	/*5*/{{Left_up,Level,Space},
	      {Vertical,Space,Space},
		  {Left_down,Level,Right_up},
		  {Space,Space,Vertical},
		  {Space,Level,Right_down}},
	/*6*/{{Left_up,Level,Space},
	      {Vertical,Space,Space},
		  {Link_UpDown_right,Level,Right_up},
		  {Vertical,Space,Vertical},
		  {Left_down,Level,Right_down}},
	/*7*/{{Space,Level,Right_up},
	      {Space,Space,Vertical},
		  {Space,Space,Vertical},
		  {Space,Space,Vertical},
		  {Space,Space,Space}},
	/*8*/{{Left_up,Level,Right_up},
	      {Vertical,Space,Vertical},
		  {Link_UpDown_right,Level,Link_UpDown_left},
		  {Vertical,Space,Vertical},
		  {Left_down,Level,Right_down}},
	/*9*/{{Left_up,Level,Right_up},
	      {Vertical,Space,Vertical},
		  {Left_down,Level,Link_UpDown_left},
		  {Space,Space,Vertical},
		  {Space,Level,Right_down}}
};

int Read_digit(int [],int);
void Show_result(int [],int);
void Print_divide_line(void);
void Show_start_info(void);
void Show_exit_info(void);
void Get_rid_of_RestLine(void);
bool Is_cycle(void);

int main(void)
{
	int Input_number[Max_digits]={0};
	int point=0;
	bool cycle=false;
	system("chcp 437>nul.");
	Show_start_info();
	do
	{
		point=Read_digit(Input_number,point);
	    Show_result(Input_number,point);
		cycle=Is_cycle();
		if(cycle) {printf("\n");point=0;}
	}while(cycle);
	Show_exit_info();
	system("pause");
	return 0;
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

void Show_start_info(void)
{
	printf("---------------Boring digit showing-------------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("Ways To Use:\n");
	printf("Enter some digits, but no more than %d.\n",Max_digits);
	printf("Program will enlarge them.\n");
	Print_divide_line();
}

void Show_exit_info(void)
{
	Print_divide_line();
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}

int Read_digit(int Input_number[],int point)
{
	unsigned char ch;
	printf("Please input something with digits:");
	while((ch=getchar())!='\n'&&point<=Max_digits-1)
		if (ch>='0'&&ch<='9') Input_number[point++]=ch-'0';
	if (ch!='\n') Get_rid_of_RestLine();
	return point;
}

void Show_result(int Input_number[],int point)
{
	unsigned char Line[5][Max_digits*3+Max_digits-1];
	int length=(point*3)+(point-1);
	for(int a=0;a<=4;a++)
	{
		int t=0;
		for(int b=0;b<=point-1;b++)
		{
			for(int c=0;c<=2;c++)
				Line[a][t++]=Digit[Input_number[b]][a][c];
			if (b<point-1) Line[a][t++]=' ';
		}
	}
	printf("The result is shown below:\n");
	for(int i=0;i<=4;i++)
	{
		for(int ii=0;ii<=length-1;ii++)
			printf("%c",Line[i][ii]);
		printf("\n");
	}
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while ((ch=getchar())!='\n') continue;
}

bool Is_cycle(void)
{
	unsigned char get_it;
	get_it='1';
	do
	{
		printf("New converting, shall we try again?(Y/N)---------");
		get_it=toupper(getchar());
		if (get_it!='\n') Get_rid_of_RestLine();
	}while(get_it!='Y'&&get_it!='N');
	return get_it=='Y';
}
