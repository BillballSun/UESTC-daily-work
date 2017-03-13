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
#define Max_test_stack_size 256

void Print_divide_line(void);
void Show_start_info(void);
void Show_exit_info(void);
void Get_rid_of_RestLine(void);
bool Stack_track();
void Show_result(bool);
bool Is_cycle(void);

int main(void)
{
	bool cycle, result;
	Show_start_info();
	do
	{
		result=Stack_track();
		Show_result(result);
		if (cycle=Is_cycle()) putchar('\n');
	}while(cycle);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

void Print_divide_line(void)
{
	printf("----------------------------------------------------\n");
}

void Show_start_info(void)
{
	printf("----------------Captain Allred Program--------------\n");
	printf("Copyright from 1998 to 2016, All rights reserved.\n");
	printf("Way to use:\n");
	printf("Enter a sentense, program will tell if it is palindrome.\n");
	printf("Less than %d characters, the rest will be ignored.\n",Max_test_stack_size);
	Print_divide_line();
}

void Show_exit_info(void)
{
	Print_divide_line();
	printf("Copyright from 1998 to 2016, All rights reserved.\n");
	printf("The way it is meant to be used.\n");
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while((ch=getchar())!='\n') continue;
}

bool Stack_track(void)
{
	unsigned char stack[Max_test_stack_size],ch;
	int length=0;
	printf("Please now enter a sentense:");
	while(((ch=getchar())!='\n')&&length<Max_test_stack_size)
		if (isalpha(ch)) *(stack+length++)=tolower(ch);
	if (ch!='\n') Get_rid_of_RestLine();
	bool result=true;
	if (length==0) printf("Why you did\'t enter characters?\n");
	else if (length%2!=0) result=false;
	else
	{
		unsigned char *top=stack+length-1,*bot=stack;
		while(top>bot&&result)
			if ((*top--)!=(*bot++)) result=false;
	}
	return result;
}

void Show_result(bool result)
{
	if (result) printf("Is is palindrome.\n");
	else printf("It is not palindrome.\n");
	putchar('\n');
}

bool Is_cycle(void)
{
	unsigned char ch;
	do
	{
		printf("Another test(Y/N)?-------");
	    ch=toupper(getchar());
		if (ch!='\n') Get_rid_of_RestLine();
	}while(!(ch=='Y'||ch=='N'));
	return ch=='Y';
}
