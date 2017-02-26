/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
**********************************************************/
/* PR1.c (Chapter 13, page 210) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf getchar putchar*/
#include <stdlib.h> /*system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper tolower isalpha isupper islower isspace*/
#include <math.h> /*sqrt fabs(double) trunc*/
#include <string.h> /*mencpy strcpy(n) strlen strcat(n) strcmp*/
#include <time.h> /*time*/
//#include <iostream> /*C++ input and output*/
//using namespace std; /*C++ cout cin*/
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
/****************************
 *#define					*
 *#if defined				*
 *#ifdef					*
 *#ifndef					*
 *#endif					*
 *							*
 *#if						*
 *#elif						*
 *#else						*
 *#endif					*
 *							*
 *#error					*
 *#line						*
 *#pragma					*
 *_Pragma(...)		 		*
 *#pragma warning disable	*
 *#pragma warning restore	*
 *							*
 *__LINE__					*
 *__FILE__					*
 *__DATE__					*
 *__TIME__					*
 *__STDC__				    *
 *__STDC_HOSTED__           *
 *__STDC_VERSION__          *
 *__STDC_IEC_599__          *
 *__STDC_IEC_599_COMPLEX__  *
 *__STDC_ISO_10646__        *
 *__func___                 *
 *__VA_ARGS__				*
 *variadic argument symbol  *
*****************************/
/***********useful Macro decleration start****************
#define Pascal true
#define DEBUG_mode true

#define Sample_structure_use true
#if Pascal
	#define begin {
	#define end }
#endif

#if 0
====DUBUG macro decleration====
#Test_divisor(x) if(x==0) do { printf("Error, divide zero\n");system("pause");} while(false)
#endif

#define Show_st(x) do switch(x%10) \
       {case 1:printf("st");break; \
	    case 2:printf("nd");break; \
		case 3:printf("rd");break; \
		default:printf("th");break;} while(false)

#define Print_divide_line() rintf("------------------------------------------------------\n")

#define Show_start_info() \
    do { \
	printf("--------------Amazing CA inc program-----------------\n"); \
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n"); \
	printf("Ways To Use:\n"); \
	printf("Please enter what to say\n"); \
	printf("Please enter what to say\n"); \
	printf("Please enter what to say\n"); \
	Print_divide_line(); \
	} while(false)
		
#define Get_rid_of_RestLine() \
do { \
	unsigned char ch; \
	while((ch=getchar())!='\n') continue; \
} while(false)

#define Safe_read_line(s,n) \
do { \
	char ch; \
	char *s_temp=s; \
	int n_temp=n; \
	while(((ch=getchar())!='\n')&&n>0) \
	{
		*s_temp++=ch;
		n_temp--;
	}
	if(ch!='\n') Get_rid_of_RestLine();
	*s_temp='\0';
} while(false)
	
bool Is_try_again(void)
{
	unsigned char ch;
	do
	{
		printf("Another chance(Y/N)?-------");
	    ch=toupper(getchar());
		if (ch!='\n') Get_rid_of_RestLine();
	}while(!(ch=='Y'||ch=='N'));
	return ch=='Y';
}

#define Is_try_again() \
(printf("Another chance(Y/N)?----"),toupper(getchar())=='Y')?,true \
:false

#define My_printf_without_escpe_sequence(x,...) printf(#x,__VA_ARGS__)
************useful Macro decleration end*****************/
/*****************Sample structure start*****************
void Show_start_info(void);
void Show_exit_info(void);
void Print_divide_line(void);
bool Safe_read_word(char *,int);
void Get_rid_of_RestLine(void);
void Show_st(int);
bool Is_try_again(void);
void Safe_read_line(char *, int);
======Modify indicator======
void Main_program(void);

int main(int argc, int argv[])
{
	bool cycle;
	Show_start_info();
	do
	{
		Main_program();
		cycle=Is_try_again();
	}while(cycle);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

======Modify indicator======
void Main_program(void)
{
	
}

void Show_start_info(void)
{
	printf("--------------Amazing CA inc program-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("Please enter what to say\n");
	printf("Please enter what to say\n");
	printf("Please enter what to say\n");
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

bool Is_try_again(void)
{
	unsigned char ch;
	do
	{
		printf("Another chance(Y/N)?-------");
	    ch=toupper(getchar());
		if (ch!='\n') Get_rid_of_RestLine();
	}while(!(ch=='Y'||ch=='N'));
	return ch=='Y';
}

bool Safe_read_word(char *s,int n)
//Empty word return false, true means at least one letter read.
{
	char ch;
    while(isspace(ch=getchar())&&ch!='\n') continue;
	if(ch=='\n') 
	{
		s='\0';
		return false;
	}
	do
	{
		*s++=ch;
		n--;
		ch=getchar();
	}while(!isspace(ch)&&n>0);
	if(ch!='\n') Get_rid_of_RestLine();
	*s='\0';
	return true;
}

void Safe_read_line(char *s, int n)
{
	char ch;
	while(((ch=getchar())!='\n')&&n>0)
	{
		*s++=ch;
		n--;
	}
	if(ch!='\n') Get_rid_of_RestLine();
	*s='\0';
}
*****************Sample structure end*******************/
#include "word.h"
#include "line.h"
#include "max_limit.h"
void Main_program(void);

int main(int argc,char *argv[])
{
	Main_program();
	system("pause");
	return EXIT_SUCCESS;
}

void Main_program(void)
{
	bool exitpoint=false;
	char present_word[Max_word_length+2]="",present_line[Max_line_length+1]="";
	int word_length,line_length=0,word_amount=0;
	while(!exitpoint)
	{
		word_length=read_word(present_word);
		if(word_length==0)
		{
			Flush_line(present_line,line_length,word_amount);
			exitpoint=true;
		}
		else if(word_length+line_length+1<=Max_line_length)
		{
			if (word_amount == 0)
			{
				strcpy(present_line, present_word);
				line_length = word_length;
			}
			else
			{
				present_line[line_length] = ' ';
				present_line[line_length + 1] = '\0';
				strcat(present_line, present_word);
				line_length = line_length + word_length + 1;
			}
			word_amount++;
		}
		else
		{
			Flush_line(present_line,line_length,word_amount);
			strcpy(present_line,present_word);
			line_length = word_length;
			word_amount=1;
		}
	}
}