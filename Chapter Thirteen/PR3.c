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
*****************Sample structure end*******************/

void read_line(char *s, int n)
{
	while(isspace(ch=getchar())&&ch!='\n') continue;
	/*
	bool exitpoint=false;
	while(!exitpoint)
	{
		ch=getchar();
		exitpoint=!isspace(ch);
		exitpoint=(ch=='\n');
	}
	*/
	if(ch!='\n')
		do
		{
			*s++=ch;
			ch=getchar();
		}while(!isspace(ch));
	if(ch=='\n') *s++=ch;
	*s='\0';
}

void capitalize(char *s)
{
	while(s)
	{
		*s=toupper(*s);
		s++;
	}
}

void censor(char *s)
{
	char *point;
	while((point=Str_find(s,"foo"))!=NULL)
		s=Str_replace(s,"xxx");
}

char *Str_find(char *s1,const char *s2)
{
	len1=strlen(s1);
	len2=strlen(s2);
	char *point=NULL;
	for(int i=0;(i<=len1-len2)&&point==NULL;i++)
	{
		bool temp=true;
		for(int t=0;t<=len2-1,t++)
			if(s1[i+t]!=s2[t]) temp=false;
		if(temp) point=s1+i;
	}
	return point;
}

char *Str_replace(char *s1,const char *s2)
{
	len=strlen(s2);
	for(int i=0;i<=len-1;i++)
		*s1++=*s2++;
	return s1;
}

int strcmp(char *s,char *t)
{
	/*
	while(*s==*t++)
		if(*s++=='\0') return 0;
	return (*--s)-(*--t);
	*/
	while(*s==*t)
	{
		if(s=='\0') return 0;
		s++;t++;
	}
	return (int)(*s-*t);
}

void Get_extension(const char *const file_name,char *const extension)
{
	int len=strlen(file_name),point=len;
	for(int i=1;i<=len;i++)
		if(file_name[i-1]=='.') point=i;
	strcpy(extension,file_name+point);
}

void Build_index_url(const char *domain, char *index_url)
{
	strcpy(index_url,"http://www."domain"/index.html");
}

bool Test_extension(const char *file_name, const char *extension)
{
	int len=strlen(file_name),point=len;
	for(int i=1;i<=len;i++)
		if(file_name[i-1]=='.') point=i;
	if(strcmp(file_name+point,extension)==0) return true;
	else return false;
}

void Remove_filename(char *url)
{
	char *point;
	while(url)
	{
		if(*url=='/') point=url;
		url++;
	}
	*point='\0';
}
