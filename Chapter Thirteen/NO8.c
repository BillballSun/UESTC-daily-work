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
#include <ctype.h> /*toupper tolower isalpha isupper islower*/
#include <math.h> /*sqrt fabs(double) trunc*/
#include <string.h> /*mencpy strcpy(n) strlen strcat(n) strcmp*/
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
/*****************Sample structure start*****************
void Show_start_info(void);
void Show_exit_info(void);
void Print_divide_line(void);
bool Safe_read_word(char *,int);
void Get_rid_of_RestLine(void);
void Show_st(int);
bool Is_try_again(void);
======Modify indicator======
void main_program(void);

int main(int argc, int argv[])
{
	bool cycle;
	Show_start_info();
	do
	{
		main_program();
		cycle=Is_try_again();
	}while(cycle);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

======Modify indicator======
void main_program(void)
{
	
}

void Show_start_info(void)
{
	printf("------------Amazing Splitting program---------------\n");
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
		printf("Another game(Y/N)?-------");
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
*****************Sample structure end*******************/
#define Max_sentence_length 60

void Show_start_info(void);
void Show_exit_info(void);
void Print_divide_line(void);
bool Safe_read_word(char *,int);
void Get_rid_of_RestLine(void);
bool Is_try_again(void);
int Compute_average_word_length(const char *);

int main(int argc, int argv[])
{
	bool cycle;
	char sentence[Max_sentence_length+1];
	int result;
	Show_start_info();
	do
	{
		while(!Safe_read_word(sentence,Max_sentence_length+1)) continue;
		result=Compute_average_word_length(sentence);
		printf("It\'s boring value is %d.\n",result);
		cycle=Is_try_again();
	}while(cycle);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

int Compute_average_word_length(const char *sentence)
{
	int total;
	unsigned char h;
	total=0;
	while((h=*sentence++)!='\0')
	{
		h=toupper(h);/*if (h<='z') h=h-'a'+'A';*/
		switch (h)
		{
			case 'A':case 'E':case 'I':case 'L':case 'N':case 'O':case 'R':case 'S':case 'T':case 'U':
			total=total+1;break;
			case 'D':case 'G':
			total=total+2;break;
			case 'B':case 'C':case 'M':case 'P':
			total=total+3;break;
			case 'F':case 'H':case 'V':case 'W':case 'Y':
			total=total+4;break;
			case 'K':
			total=total+5;break;
			case 'J':case 'X':
			total=total+8;break;
			case 'Q':case 'Z':
			total=total+10;break;
		}
	}
	return total;
}

void Show_start_info(void)
{
	printf("------------Amazing Splitting program---------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("Caculating the value of a word.\n");
	printf("A E I L N O R S T U got 1 score.\n");
	printf("D G got 2.\n");
	printf("B C M P got 3.\n");
	printf("F H V W Y got 4.\n");
	printf("K got 5.\n");
	printf("J X got 8.\n");
	printf("Q Z got 10.\n");
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
		printf("New chance, another try(Y/N)?-------");
	    ch=toupper(getchar());
		if (ch!='\n') Get_rid_of_RestLine();
	}while(!(ch=='Y'||ch=='N'));
	return ch=='Y';
}

bool Safe_read_word(char *s,int n)
//Empty word return false, true means at least one letter read.
{
	char ch;
	printf("Please enter a word:");
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
