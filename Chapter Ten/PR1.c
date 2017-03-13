/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
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
 *********************/
/************************************************
 *srand((unsigned)time(NULL));                  *
 *rand() to get a 0-maxint number, use %amount. *
 ************************************************/
/********************************************************
 *PC-Lint check                                         *
 *C:/Lint/Lint-nt -i"C:/Lint" -u cmd_std.lnt D:/lint.cpp*
 ********************************************************/

#define STACK_SIZE 100
int stack[STACK_SIZE];
int point=0;

void Stack_overflow(void);

void Stack_downflow(void);

void Empty_stack(void)
{
	point=0;
}

bool Is_empty(void)
{
	return point==0;
}

bool Is_full(void)
{
	return point==STACK_SIZE;
}

void push(int i)
{
	if (Is_full) Stack_overflow();
	else stack[point++]=i;
}

int pop(void)
{
	if(Is_empty) Stack_downflow();
	else return stack[--point];
}

void Stack_overflow(void)
{
	printf("Stack overflow.\n");
	system("pause");
	exit(EXIT_FAILURE);
}

void Stack_downflow(void)
{
	printf("Stack downflow.\n");
	system("pause");
	exit(EXIT_FAILURE);
}

int main(void)
{
	return 0;
}






