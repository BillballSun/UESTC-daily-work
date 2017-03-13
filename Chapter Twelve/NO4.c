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
/*********************************************
 *system("chcp 437>nul.");Show ASCII extended*
**********************************************/
#define Max_array_length 100

void Input_data(int *,short *);
void Split(int *,short);
void Show_start_info(void);
void Show_st(int);
void Get_rid_of_RestLine(void);
void Show_result(int *,short);
void Print_divide_line(void);
void Show_exit_info(void);

int main(void)
{
	int a[Max_array_length];
	short length;
	Input_data(a,&length);
	Split(a,length);
	Show_result(a,length);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

void Input_data(int *a,short *length)
{
	Show_start_info();
	bool cycle;
	do
	{
		cycle=false;
		printf("Please choose how many numbers for sort:");
		*length=0;
		scanf("%hd",length);
		if(*length>Max_array_length)
		{
			printf("too many numbers, please make sure less than %d.\n",Max_array_length);
			cycle=true;
		}
		else if(*length==1)
		{
			printf("No need to sort just one number.\n");
			cycle=true;
		}
		else if(*length<=0)
		{
			printf("How do you think...\n");
			cycle=true;
		}
	    Get_rid_of_RestLine();
	}while(cycle);
	for(int i=1;i<=*length;i++)
	{
		printf("Please input the %d",i);
		Show_st(i);
		printf(" number:");
		*(a+i-1)=0;
		scanf("%d",a+i-1);
		Get_rid_of_RestLine();
	}
}

void Split(int *a,short length)
{
	int *top=a+length-1,*bot=a;
	int temp=*a;
	while(top>bot)
	{
		while((top>bot)&&(*top>=temp)) top--;
		if(top>bot) {*bot++=*top;if (top<=bot) *top=temp;} else *bot=temp;
		if(top>bot)
		{
			while((top>bot)&&(*bot<=temp)) bot++;
			if(top>bot) {*top--=*bot;if (top<=bot) *bot=temp;} else *top=temp;
		}
	}
}

void Show_st(int x)
{
	switch(x%10)
	{
		case 1:printf("st");break;
		case 2:printf("nd");break;
		case 3:printf("rd");break;
		default:printf("th");break;
	}
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while((ch=getchar())!='\n') continue;
}

void Show_result(int *a,short length)
{
	printf("By split, the array is ");
	for(int i=0;i<=length-1;i++)
		printf("%d ",*(a+i));
	printf("\n");
}

void Show_start_info(void)
{
	printf("------------Amazing Splitting program---------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("Split the array by the first number.\n");
	printf("Please make sure no more than %d numbers.\n",Max_array_length);
	printf("If what you entered is not begin with numbers, it means zero.\n");
	Print_divide_line();
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

void Show_exit_info(void)
{
	Print_divide_line();
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}
