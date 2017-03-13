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
#define Max_word_length 256

void Input_data(unsigned char *, short *);
void Get_rid_of_RestLine(void);
void Show_result(unsigned char *, short);
bool Is_continue(void);
void Show_start_info(void);
void Show_exit_info(void);
void Print_divide_line(void);

int main(void)
{
	unsigned char word[Max_word_length];
	short length;
	bool continue_point;
	Show_start_info();
	do
	{
		Input_data(word,&length);
	    Show_result(word,length);
		if (continue_point=Is_continue()) putchar('\n');
	}while(continue_point);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

void Input_data(unsigned char *word, short *length)
{
	unsigned char ch;
	printf("Enter a message:");
	*length=0;
	while(((ch=getchar())!='\n')&&*length<Max_word_length)
		*(word+(*length)++)=ch;
	if (ch!='\n') Get_rid_of_RestLine();
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while ((ch=getchar())!='\n') continue;
}

void Show_result(unsigned char *word, short length)
{
	printf("In reversed sentense, it is:");
	for(int i=length-1;i>=0;i--)
		putchar(*(word+i));
	printf("\n\n");
}

bool Is_continue(void)
{
	unsigned char ch;
	do
	{
		printf("Shall we try again(Y/N)-----");
	    ch=toupper(getchar());
		if (ch!='\n') Get_rid_of_RestLine();
	}while(!(ch=='Y'||ch=='N'));
	return ch=='Y';
}

void Show_start_info(void)
{
	printf("------------Amazing Reversing program---------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("Enter a sentense.\n");
	printf("Then this boring program will reverse it automatically.\n");
	printf("WARNING: no more than 256 words.\n");
	Print_divide_line();
}

void Show_exit_info(void)
{
	Print_divide_line();
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}
