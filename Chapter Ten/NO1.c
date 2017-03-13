/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
**********************************************************/
/* NO9.c (Chapter 9, page 153) */
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
#define STACK_SIZE 100

unsigned char Stack[STACK_SIZE];
unsigned short point=0;
/*0-100,0 empty,100 full*/

unsigned short Input_stack_data(void);
void Show_result(unsigned short);
void Insert_stack(unsigned char);
unsigned char Pop_stack(void);
bool Is_stack_empty(void);
bool Is_stack_full(void);
void Print_divide_line(void);
void Show_start_info(void);
void Show_exit_info(void);
bool Is_cycle(void);
bool Is_left_right_match(unsigned char left,unsigned char right);
void Get_rid_of_RestLine(void);
void Empty_stack(void);

int main(void)
{
	bool cycle;
	unsigned short warning;
	/*
	 *0 Perfect matched
	 *1 Downflow not matched
	 *2 Overflow unexpected
	 *3 Unkown character
	 *4 Not matched
	 */
	Show_start_info();
	do
	{
		warning=Input_stack_data();
	    Show_result(warning);
		cycle=Is_cycle();
		if (cycle) {Print_divide_line();Empty_stack();}
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
	printf("---------------Matching test program------------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("Ways To Use:\n");
	printf("Input some {, }, (, ) then the program will test match.\n");
	Print_divide_line();
}

void Show_exit_info(void)
{
	Print_divide_line();
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}

unsigned short Input_stack_data(void)
{
	unsigned short warning=0;
	unsigned char ch;
	printf("Input the structure:");
	while(((ch=getchar())!='\n')&&warning==0)
	{
		if (ch=='{'||ch=='(')
			
			if(Is_stack_full()) warning=2u;
			else Insert_stack(ch);
			
		else if(ch=='}'||ch==')')
		    {
			    if(Is_stack_empty()) warning=1u;
		        else if(!Is_left_right_match(Pop_stack(),ch)) warning=4u;
		    }
		else warning=3u;
	}
	if (ch!='\n') Get_rid_of_RestLine();
	if (!Is_stack_empty()&&warning!=3u) warning=4u;
	return warning;
}

void Empty_stack(void)
{
	point=0u;
}

bool Is_stack_empty(void)
{
	return point==0u;
}

bool Is_stack_full(void)
{
	return point==100u;
}

void Insert_stack(unsigned char ch)
{
	Stack[point++]=ch;
}

unsigned char Pop_stack(void)
{
	unsigned char ch;
	ch=Stack[--point];
	return ch;
}

void Show_result(unsigned short warning)
{
	/*
	 *  Warning data
	 *0 Perfect matched
	 *1 Downflow not matched
	 *2 Overflow unexpected
	 *3 Unkown character
	 *4 Not matched
	 */
	 switch(warning)
	 {
		 case 0:printf("Yeah, perfectly matched.");break;
		 case 1:printf("Not matched, right side get something unmatched.");break;
		 case 2:printf("Overflow, result is unclear, due to more 100 characters.");break;
		 case 3:printf("Detected unkown characters.");break;
		 case 4:printf("Not matched, left side get something unmatched.");break;
	 }
	 printf("\n");
}

bool Is_cycle(void)
{
	unsigned char get_it,ch;
	get_it='0';
	do
	{
		printf("Would you like to test again?(Y/N)---------");
		get_it=toupper(getchar());
		if (get_it!='\n') Get_rid_of_RestLine();
	}while(get_it!='Y'&&get_it!='N');
	return get_it=='Y';
}

bool Is_left_right_match(unsigned char left,unsigned char right)
{
	return (left=='{'&&right=='}')||(left=='('&&right==')');
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while ((ch=getchar())!='\n') continue;
}
