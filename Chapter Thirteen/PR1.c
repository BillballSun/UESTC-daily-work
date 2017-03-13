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
#define Max_message_length 64
#define Max_remind_events 90

void Show_start_info(void);
void Show_exit_info(void);
void Print_divide_line(void);
void Get_rid_of_RestLine(void);
void Show_st(int);
void Input_data(char(*)[Max_message_length + 3], unsigned short *);
bool Is_number(unsigned char);
int Signed_char_to_int(char);
char *Safe_gets(char *, int);
void Sort_event(char(*)[Max_message_length + 3], unsigned short);
void Safe_strncpy(char *, const char *, size_t);
void Show_event(char(*)[Max_message_length + 3], unsigned short);

int main(int argc, int argv[])
{
	char reminder[Max_remind_events][Max_message_length + 3];
	unsigned short events_amount;
	Show_start_info();
	Input_data(reminder, &events_amount);
	Sort_event(reminder, events_amount);
	Show_event(reminder, events_amount);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

void Input_data(char(*reminder)[Max_message_length + 3],  unsigned short *events_amount)
{
	int event_no = 0;
	bool exitpoint;
	int day;
	char event[Max_message_length + 3];
	do
	{
		exitpoint = true;
		printf("Pleas enter the %d",event_no+1);
		Show_st(event_no + 1);
		printf(" infomation:");
		Safe_gets(event, Max_message_length + 2);
		if (Is_number(event[0]) && event[0] != '0')
			if (Is_number(event[1]))
			{
			day = Signed_char_to_int(event[0]) * 10 + Signed_char_to_int(event[1]);
			if (day <= 31 && day >= 1)
			{
				char *pointer = &event[2];
				while (*pointer == ' ') pointer++;
				for (int i = 0; i <= 1; i++)
					reminder[event_no][i] = event[i];
				reminder[event_no][2] = ' ';
				reminder[event_no][3] = '\0';
				strcat(reminder[event_no], pointer);
				exitpoint = false;
				event_no++;
			}
			}
			else
			{
				char *pointer = &event[1];
				while (*pointer == ' ') pointer++;
				reminder[event_no][0] = ' ';
				reminder[event_no][1] = event[0];
				reminder[event_no][2] = ' ';
				reminder[event_no][3] = '\0';
				strcat(reminder[event_no], pointer);
				exitpoint = false;
				event_no++;
			}
	} while (!exitpoint&&event_no <= Max_remind_events);
	*events_amount = event_no;
}

void Sort_event(char(*reminder)[Max_message_length + 3], unsigned short events_amount)
{
	int t;
	for (int i = events_amount - 1; i >= 1; i--)
	{
		t = 0;
		for (int point = 1; point <= i; point++)
			if (strcmp(reminder[t], reminder[point])<0) t = point;
		char temp[Max_message_length + 3];
		Safe_strncpy(temp, reminder[t], sizeof(temp));
		Safe_strncpy(reminder[t], reminder[i], sizeof(reminder[t]));
		Safe_strncpy(reminder[i], temp, sizeof(reminder[i]));
	}
}

void Safe_strncpy(char *s1, const char *s2, size_t n)
{
	strncpy(s1, s2, n - 1);
	*(s1 + n - 1) = '\0';
}

void Show_event(char(*reminder)[Max_message_length + 3], unsigned short events_amount)
{
	Print_divide_line();
	printf("Your date arrangement is as below.\n");
	if (events_amount == 0) printf("NONE\n");
	else
	{
		printf("Day Reminder\n");
		for (int i = 0; i <= events_amount - 1; i++)
		{
			putchar(' ');
			puts(*(reminder + i));
		}
	}
}

void Show_start_info(void)
{
	printf("------------Amazing Sring reminder program-----------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("Just enter day and the event\n");
	printf("So simple\n");
	printf("Really simple, I mean the truth.\n");
	Print_divide_line();
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}


void Show_st(int x)
{
	switch (x % 10)
	{
	case 1:printf("st"); break;
	case 2:printf("nd"); break;
	case 3:printf("rd"); break;
	default:printf("th"); break;
	}
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while ((ch = getchar()) != '\n') continue;
}

bool Is_number(unsigned char ch)
{
	return (ch <= '9'&&ch >= '0');
}

int Signed_char_to_int(char ch)
{
	return ch - '0';
}

char *Safe_gets(char *s, int n)
{
	int count = 0;
	char ch;
	while ((ch = getchar()) != '\n')
		if (count<n) s[count++] = ch;
	s[count] = '\0';
	return s;
}

void Show_exit_info(void)
{
	Print_divide_line();
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}
