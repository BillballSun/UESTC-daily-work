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
#define Stack_size 100

int Stack[Stack_size];
int point=0;

void Show_start_info(void);
bool Caculation_RPN(void);
void Show_exit_info(void);
void Print_divide_line(void);
void Insert_stack(int);
int Pop_stack(void);
int Char_to_int(unsigned char);
void Show_result(unsigned short);
void Show_near_data(void);
bool Is_stack_full(void);
void Get_rid_of_RestLine(void);
void Empty_stack(void);

int main(void)
{
	bool stop_point;
	Show_start_info();
	do
	{	
		stop_point=Caculation_RPN();
	if (!stop_point) {printf("\n");Empty_stack();}
	}while(!stop_point);
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
	printf("--------------Reverse Polish Notation----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("Ways To Use:\n");
	printf("Enter some words with operators.\n");
	printf("Program will caculate one by one.\n");
	Print_divide_line();
}

bool Caculation_RPN(void)
{
	unsigned short warning;
	unsigned char ch;
	int left,right;
	warning=0u;
	/*
	 *0 default, continue to insert number until \n
	 *1 overflow, not enough space to store digits
	 *2 downflow, not enough digits to caculate
	 *3 divide zero
	 *4 = detected show result right now
	 *5 exit symbol detected
	 */
	printf("Enter a RPN expression:");
	while((ch=getchar())!='\n'&&warning==0u)
		if (ch>='0'&&ch<='9')
			if(Is_stack_full()) warning=1u;
		    else Insert_stack(Char_to_int(ch));
		else if (ch=='+'||ch=='-'||ch=='*'||ch=='/')
			if (point>=2)
			{
			    right=Pop_stack();
				left=Pop_stack();
				switch(ch)
		        {
			    	case '+':Insert_stack(left+right);break;
					case '-':Insert_stack(left-right);break;
					case '*':Insert_stack(left-right);break;
					case '/':if(right==0) warning=3u; else Insert_stack(left/right);break;
		        }
		    }
			else warning=2u;
		else if (ch=='=') warning=4u;
		else if (ch!=' ') warning=5u;
	if (ch!='\n') Get_rid_of_RestLine();
	Show_result(warning);
	return warning==5u;
}
void Show_exit_info(void)
{
	Print_divide_line();
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}

void Insert_stack(int x)
{
	/*Allready make sure won't overflow*/
	Stack[point++]=x;
}

int Pop_stack(void)
{
	/*Allready make sure won't downflow*/
	return Stack[--point];
}

int Char_to_int(unsigned char ch)
{
	int result;
	result=ch-'0';
	return result;
}

void Show_result(unsigned short warning)
{
	/*
	 *0 default, continue to insert number until \n
	 *1 overflow, not enough space to store digits
	 *2 downflow, not enough digits to caculate
	 *3 divide zero
	 *4 = detected show result right now
	 *5 exit symbol detected
	 */
	switch(warning)
	{
		case 1:printf("Error, not enough space to store digits.");break;
		case 2:printf("Error, not enough digits to caculate.");break;
		case 3:printf("Error, divide zero.");break;
		case 5:printf("Special symbol detected, default to exit.");break;
		case 4:
		printf("= detected, show result right now.\n");
		/*NO break*/
		case 0:
		Show_near_data();
		break;
	}
	printf("\n");
}

void Show_near_data(void)
{
	if (point==0) printf("Warning, stack empty.");
	else printf("Now the top stack result is %d.",Stack[point-1]);
}

bool Is_stack_full(void)
{
	return point>=100;
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while ((ch=getchar())!='\n') continue;
}

void Empty_stack(void)
{
	point=0;
}
