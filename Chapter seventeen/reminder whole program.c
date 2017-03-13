/*********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
**********************************************************/
/* PR1.c (Chapter 13, page 210) */
#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h> /* scanf printf getchar putchar */
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace */
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* mencpy strcpy(n) strlen strcat(n) strcmp */
#include <time.h> /* time */
//#include <iostream> /* C++ input and output */
//using namespace std; /* C++ cout cin */
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
*  ===Macro difination===  *
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
/*
========limit.h========
#define CHAR_BIT      8                            // number of bits in a char
#define SCHAR_MIN   (-128)                         // minimum signed char value
#define SCHAR_MAX     127                          // maximum signed char value
#define UCHAR_MAX     0xff                         // maximum unsigned char value
#ifndef _CHAR_UNSIGNED
#define CHAR_MIN    SCHAR_MIN                  // mimimum char value
#define CHAR_MAX    SCHAR_MAX                  // maximum char value
#else
#define CHAR_MIN      0
#define CHAR_MAX    UCHAR_MAX
#endif
#define MB_LEN_MAX    5                            // max. # bytes in multibyte char
#define SHRT_MIN    (-32768)                       // minimum (signed) short value
#define SHRT_MAX      32767                        // maximum (signed) short value
#define USHRT_MAX     0xffff                       // maximum unsigned short value
#define INT_MIN     (-2147483647 - 1)              // minimum (signed) int value
#define INT_MAX       2147483647                   // maximum (signed) int value
#define UINT_MAX      0xffffffff                   // maximum unsigned int value
#define LONG_MIN    (-2147483647L - 1)             // minimum (signed) long value
#define LONG_MAX      2147483647L                  // maximum (signed) long value
#define ULONG_MAX     0xffffffffUL                 // maximum unsigned long value
#define LLONG_MAX     9223372036854775807i64       // maximum signed long long int value
#define LLONG_MIN   (-9223372036854775807i64 - 1)  // minimum signed long long int value
#define ULLONG_MAX    0xffffffffffffffffui64       // maximum unsigned long long int value
#define _I8_MIN     (-127i8 - 1)                   // minimum signed 8 bit value
#define _I8_MAX       127i8                        // maximum signed 8 bit value
#define _UI8_MAX      0xffui8                      // maximum unsigned 8 bit value
#define _I16_MIN    (-32767i16 - 1)                // minimum signed 16 bit value
#define _I16_MAX      32767i16                     // maximum signed 16 bit value
#define _UI16_MAX     0xffffui16                   // maximum unsigned 16 bit value
#define _I32_MIN    (-2147483647i32 - 1)           // minimum signed 32 bit value
#define _I32_MAX      2147483647i32                // maximum signed 32 bit value
#define _UI32_MAX     0xffffffffui32               // maximum unsigned 32 bit value
#define _I64_MIN    (-9223372036854775807i64 - 1)  // minimum signed 64 bit value
#define _I64_MAX      9223372036854775807i64       // maximum signed 64 bit value
#define _UI64_MAX     0xffffffffffffffffui64       // maximum unsigned 64 bit value
#ifndef SIZE_MAX                                   //SIZE_MAX size_t max defination
#ifdef _WIN64
#define SIZE_MAX _UI64_MAX
#else
#define SIZE_MAX UINT_MAX
#endif
#endif
*/
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
void Print_small_line(void);
bool Safe_read_name(char *,int);
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
void Print_small_line(void)
{
printf("-----------------------\n");
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
bool Safe_read_name(char *s,int n)
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
#define Max_reminder_event 64u     //max to unsigned int
#define Max_message_length 100
#define Max_message_list_length 30

#ifndef HEAD_error_info
#define HEAD_error_info
#define Error_info_allocation_failed 1
#define Error_info_reminder_full 2
#define Error_info_reminder_empty 3
#endif

struct event
{
	unsigned char day; //0-255
	char *message;
}reminder[Max_reminder_event];
//ID range from 1 to present_event_amount

unsigned int present_event_amount;

void Show_start_info(void);
void Show_exit_info(void);
void Show_error_info(int);

void Print_divide_line(void);
void Print_small_line(void);
void Get_rid_of_RestLine(void);

void Main_program(void);

char Get_command_order(void);
void Add_process(void);
void Delete_process(void);
void Search_process(void);
void Print_process(void);

void Delete_by_day_process(void);
void Delete_by_id_process(void);
void Delete_by_message_process(void);
void Search_by_day_process(void);
void Search_by_message_process(void);
void Print_by_ID_process(void);
void Print_by_day_process(void);
void Print_by_range_process(void);
void Print_by_parts_process(void);

bool Is_number(char);
int Get_a_day(char *);
unsigned int Get_a_id(void);
bool Get_Y_or_N(char *);
char Get_a_upper_letter(void);
void Show_id_detailed_info(unsigned int);

bool Safe_read_name(char *, int);
char *Read_message(unsigned int);
void Free_event_by_ID(int);
void Clean_stored_id(unsigned int *, unsigned int day_count);
int Get_some_days_selected(bool *);
bool Decent_match(char *s1, char *s2);


int main(int argc, char *argv[])
{
	Show_start_info();
	present_event_amount = 0u;
	Main_program();
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

void Show_error_info(int code)
{
	switch (code)
	{
	case Error_info_allocation_failed:
		printf("\nWarning, allocation failed.\n\n"); break;
	case Error_info_reminder_full:
		printf("\nWarning, reminder is full, due to maximun is %u.\n\n", (unsigned int)Max_message_length); break;
	case Error_info_reminder_empty:
		printf("\nWarning, reminder is empty.\n\n"); break;
	}
}

void Main_program(void)
{
	char ch;
	bool exitpoint = false;
	do
	{
		ch = Get_command_order();
		if (ch!='E') Print_small_line();
		switch (ch)
		{
		case 'A':Add_process(); break;
		case 'D':Delete_process(); break;
		case 'S':Search_process(); break;
		case 'P':Print_process(); break;
		case 'E':exitpoint = true; break;
		}
		Print_divide_line();
	} while (!exitpoint);
}

void Add_process(void)
{
	printf("====Add an event====\n");
	if (present_event_amount == Max_reminder_event)
	{
		Show_error_info(Error_info_reminder_full);
		return;
	}
	bool check;
	int day;
	do
	{
		check = false;
		printf("Please enter the reminder:");
		if (scanf("%2d", &day) == 1)
			if (day <= 31 && day >= 1)
				check = true;
		if (!check) Get_rid_of_RestLine();
	} while (!check);
	//at least \n remained
	char *point = Read_message(Max_message_length);
	if (point == NULL)
	{
		Show_error_info(Error_info_allocation_failed);
		return;
	}
	struct event temp;
	temp.day = day; temp.message = point;
	unsigned int plug = present_event_amount;
	check = false;
	//re using check
	for (unsigned int i = 0; !check&&i <= present_event_amount - 1; i++)
		if (temp.day > reminder[i].day)
		{
			plug = i;
			check = true;
		}
	if (present_event_amount>0)
		for (long i = present_event_amount - 1; i >= plug; i--)
			reminder[i + 1] = reminder[i];
	reminder[plug] = temp;
	present_event_amount++;
	printf("Your event added to reminder successfully.\n");
}

char *Read_message(unsigned int length_limit)
//if allocation failed return NULL
{
	char *p;
	if (!(p = (char *)malloc(length_limit + 1)))
	{
		Get_rid_of_RestLine();
		return NULL;
	}
	char ch;
	unsigned int counter = 0;
	while (isspace(ch = getchar()) && ch != '\n') continue;
	if (ch != '\n')
		do
		{
		if (counter<length_limit)
		{
			p[counter] = ch;
			counter++;
		}
		ch = getchar();
		} while (ch != '\n');
	p[counter] = '\0';
	p = (char *)realloc(p, counter + 1);
	//smaller, no check for return NULL
	return p;
}

void Delete_process(void)
{
	printf("====Delete an event====\n");
	if (present_event_amount == 0u)
	{
		Show_error_info(Error_info_reminder_empty);
		return;
	}
	char ch;
	//id range from 1 to present_event_amount
	do
	{
		printf("1--ID  2--day  3--message\n");
		printf("Please enter your way:");
		ch = Get_a_upper_letter();
		Print_small_line();
	} while (ch<'1' || ch>'3');
	switch (ch)
	{
	case '1':Delete_by_id_process(); break;
	case '2':Delete_by_day_process(); break;
	case '3':Delete_by_message_process(); break;
	}
}

void Free_event_by_ID(unsigned int id)
{
	free(reminder[id - 1].message);
	//free the allocation storage
	for (unsigned int i = id; i <= present_event_amount - 1; i++)
		reminder[i - 1] = reminder[i];
	present_event_amount--;
}

void Delete_by_id_process(void)
{
	unsigned int id = Get_a_id();
	Print_small_line();
	Show_id_detailed_info(id);
	if (Get_Y_or_N("Sure to delete this event"))
	{
		Free_event_by_ID(id);
		printf("Event removed from reminder successfully.\n");
	}
	else
		printf("process cancel by user.\n");
}

unsigned int Get_a_id(void)
{
	unsigned int id;
	bool check;
	do
	{
		check = false;
		printf("Please enter your ID:");
		if (scanf("%u", &id)<1) check = true;
		else if (id == 0 || id>present_event_amount)
		{
			printf("Info, now ID range from 1 to %u.\n", present_event_amount);
			check = true;
		}
		Get_rid_of_RestLine();
	} while (check);
	return id;
}

void Delete_by_day_process(void)
{
	char ch;
	do
	{
		printf("1--an exact day  2--range  3--some parts\n");
		printf("Please enter your way:");
		ch = Get_a_upper_letter();
		Print_small_line();
	} while (ch<'1' || ch>'3');

	int find_day;
	int start_day, end_day;

	unsigned int *store_find_id;
	unsigned int day_count = 0;

	bool selected_day[31] = { false };

	if (!(store_find_id = (unsigned int *)malloc(sizeof(unsigned int)*present_event_amount)))
	{
		Show_error_info(Error_info_allocation_failed);
		return;
	}
	switch (ch)
	{
	case '1':
		find_day = Get_a_day("Please enter a day:");
		for (unsigned int i = 1; i <= present_event_amount; i++)
			if (reminder[i - 1].day == find_day)
			{
			store_find_id[day_count] = i;
			day_count++;
			}
		Clean_stored_id(store_find_id, day_count);
		break;
	case '2':
		start_day = Get_a_day("Please enter the starting day:");
		end_day = Get_a_day("Please enter the ending day:");
		if (start_day>end_day)
		{
			printf("Reverse them automatically...\n");
			int temp = start_day;
			start_day = end_day;
			end_day = temp;
		}
		for (unsigned int i = 1; i <= present_event_amount; i++)
			if (reminder[i - 1].day <= end_day&&reminder[i - 1].day >= start_day)
			{
			store_find_id[day_count] = i;
			day_count++;
			}
		Clean_stored_id(store_find_id, day_count);
		break;
	case '3':
		printf("Please enter some days:");
		if (Get_some_days_selected(selected_day) == 0) printf("User haven\'t entered anything...\n");
		else
		{
			for (unsigned int i = 1; i <= present_event_amount; i++)
				if (selected_day[reminder[i - 1].day - 1])
				{
				store_find_id[day_count] = i;
				day_count++;
				}
			Clean_stored_id(store_find_id, day_count);
		}
		break;
	}
	//Free store find...
	free(store_find_id);
}

int Get_some_days_selected(bool *selected_day)
//bool selected_day[31]={false};only called by Delete_by_day_process function
//return how many selected
{
	int counter = 0;
	int first = 0,second = 0;
	signed char p = 0;
	bool check = false;
	char ch;
	do
	{
		ch = getchar();
		if (Is_number(ch))
		{
			if (p == 0)
			{
				first = ch - '0';
				p++;
			}
			else if (p == 1)
			{
				second = ch - '0';
				p++;
			}
		}
		else
		{
			if (p == 1)
			{
				if (first >= 1) selected_day[first - 1] = true;
				p = 0; counter++;
			}
			else if (p == 2)
			{
				int temp = first * 10 + second;
				if (temp >= 1 && temp <= 31) selected_day[temp - 1] = true;
				p = 0; counter++;
			}
			if (!isspace(ch) || ch == '\n') check = true;
		}
	} while (!check);
	if (ch != '\n') Get_rid_of_RestLine();
	return counter;
}

bool Is_number(char ch)
{
	return ch <= '9'&&ch >= '0';
}

void Clean_stored_id(unsigned int *store_find_id, unsigned int day_count)
{
	if (day_count == 0u)
		printf("No finding in reminder.\n");
	else if (day_count == 1u)
	{
		Show_id_detailed_info(*store_find_id);
		Print_small_line();
		if (Get_Y_or_N("Sure to delete this day"))
			Free_event_by_ID(*store_find_id);
		else printf("Process cancel by user\n");

	}
	else
	{
		for (unsigned int i = 1; i <= day_count; i++)
		{
			Show_id_detailed_info(store_find_id[i - 1]);
			Print_small_line();
		}
		if (Get_Y_or_N("Sure to delete these days"))
			for (unsigned int i = day_count; i >= 1; i--)
				Free_event_by_ID(store_find_id[i - 1]);
		//ID changed but decrease will not menance
		else printf("Process cancel by user\n");
	}
}

int Get_a_day(char *message)
{
	bool check;
	int find_day;
	do
	{
		check = false;
		printf("%s", message);
		if (scanf("%d", &find_day) == 1)
			if (find_day <= 31 && find_day >= 1)
				check = true;
		Get_rid_of_RestLine();
	} while (!check);
	return find_day;
}

bool Get_Y_or_N(char *info)
{
	char ch;
	do
	{
		printf("%s(Y/N)--", info);
		ch = Get_a_upper_letter();
	} while (ch != 'Y'&&ch != 'N');
	return ch == 'Y';
}

void Show_id_detailed_info(unsigned int id)
{
	printf("ID:%u\n", id);
	printf("Day:%d\n", (int)reminder[id - 1].day);
	printf("Event:%s\n", reminder[id - 1].message);
}

void Delete_by_message_process(void)
{
	char *find_text;
	if (!(find_text = (char *)malloc(Max_message_length + 1)))
	{
		Show_error_info(Error_info_allocation_failed);
		return;
	}
	bool check;
	do
	{
		printf("Please enter delete message:");
		check = Safe_read_name(find_text, Max_message_length);
		Print_small_line();
	} while (!check);
	unsigned int *store_find_id;
	unsigned int day_count = 0;
	if (!(store_find_id = (unsigned int*)malloc(sizeof(unsigned int)*present_event_amount)))
	{
		Show_error_info(Error_info_allocation_failed);
		return;
	}
	for (unsigned int i = 1; i <= present_event_amount; i++)
		if (strcmp(reminder[i - 1].message, find_text) == 0)
		{
		store_find_id[day_count] = i;
		day_count++;
		}
	if (day_count>0)
	{
		for (unsigned int i = 1; i <= day_count; i++)
		{
			Show_id_detailed_info(store_find_id[i - 1]);
			Print_small_line();
		}
		Clean_stored_id(store_find_id, day_count);
	}
	else if (Get_Y_or_N("No finding do you wish a decent finding"))
	{
		for (unsigned int i = 1; i <= present_event_amount; i++)
			if (Decent_match(reminder[i - 1].message, find_text))
			{
			store_find_id[day_count] = i;
			day_count++;
			}
		Clean_stored_id(store_find_id, day_count);
	}
	free(find_text);
	free(store_find_id);
}

bool Decent_match(char *s1, char *s2)
{
	int len1 = strlen(s1), len2 = strlen(s2);
	if (len1<len2) return false;
	bool result = false;
	bool temp;
	for (int i = 1; !result && (i <= len1 - len2 + 1); i++)
	{
		temp = true;
		for (int t = 1; temp&&t <= len2; t++)
			if (toupper(s1[i + t - 2]) != toupper(s2[t - 1])) temp = false;
		result = temp;
	}
	return result;
}

void Search_process(void)
{
	char ch;
	printf("====Search an event====\n");
	do
	{
		printf("1--by day  2--by message\n");
		printf("Enter your selection:");
		ch = Get_a_upper_letter();
	} while (ch<'1' || ch>'2');
	switch (ch)
	{
	case '1':Search_by_day_process(); break;
	case '2':Search_by_message_process(); break;
	}
}

void Search_by_day_process(void)
{
	int find_day;
	find_day = Get_a_day("Please enter a day:");
	unsigned int *store_find_id;
	unsigned int day_count = 0;
	if (!(store_find_id = (unsigned int*)malloc(sizeof(unsigned int)*present_event_amount)))
	{
		Show_error_info(Error_info_allocation_failed);
		return;
	}
	for (unsigned int i = 1; i <= present_event_amount; i++)
		if (reminder[i - 1].day == find_day)
		{
		store_find_id[day_count] = i;
		day_count++;
		}
	if (day_count == 0) printf("No result.\n");
	else
	{
		for (unsigned int i = 1; i <= day_count; i++)
		{
			Print_small_line();
			Show_id_detailed_info(store_find_id[i - 1]);
		}
	}
	free(store_find_id);
}

void Search_by_message_process(void)
{
	char *find_text;
	if (!(find_text = (char *)malloc(Max_message_length + 1)))
	{
		Show_error_info(Error_info_allocation_failed);
		return;
	}
	bool check;
	do
	{
		printf("Please enter find message:");
		check = Safe_read_name(find_text, Max_message_length);
		Print_small_line();
	} while (!check);
	unsigned int *store_find_id;
	unsigned int day_count = 0;
	if (!(store_find_id = (unsigned int*)malloc(sizeof(unsigned int)*present_event_amount)))
	{
		Show_error_info(Error_info_allocation_failed);
		return;
	}
	for (unsigned int i = 1; i <= present_event_amount; i++)
		if (strcmp(reminder[i - 1].message, find_text) == 0)
		{
		store_find_id[day_count] = i;
		day_count++;
		}
	if (day_count>0)
	{
		for (unsigned int i = 1; i <= day_count; i++)
		{
			Print_small_line();
			Show_id_detailed_info(store_find_id[i - 1]);
		}
	}
	else if (Get_Y_or_N("No finding do you wish a decent finding"))
	{
		for (unsigned int i = 1; i <= present_event_amount; i++)
			if (Decent_match(reminder[i - 1].message, find_text))
			{
			store_find_id[day_count] = i;
			day_count++;
			}
		if (day_count>0)
		{
			for (unsigned int i = 1; i <= day_count; i++)
			{
				Print_small_line();
				Show_id_detailed_info(store_find_id[i - 1]);
			}
		}
		else
		{
			printf("No decent finding result.\n");
		}
	}
	free(find_text);
	free(store_find_id);
}

void Print_process(void)
{
	printf("====Print event info====\n");
	if (present_event_amount == 0)
	{
		Show_error_info(Error_info_reminder_empty);
		return;
	}
	char ch;
	do
	{
		printf("1--ID  2--day  3--range  4--some parts\n");
		printf("Enter your selection:");
		ch = Get_a_upper_letter();
		Print_small_line();
	} while (ch<'1' || ch>'4');
	switch (ch)
	{
	case '1':Print_by_ID_process(); break;
	case '2':Print_by_day_process(); break;
	case '3':Print_by_range_process(); break;
	case '4':Print_by_parts_process(); break;
	}
}

void Print_by_ID_process(void)
{
	unsigned int id = Get_a_id();
	Show_id_detailed_info(id);
}

void Print_by_day_process(void)
{
	unsigned char find_day = Get_a_day("Please enter a day:");
	unsigned int *store_find_id;
	unsigned int day_count = 0;
	if (!(store_find_id = (unsigned int*)malloc(sizeof(unsigned int)*present_event_amount)))
	{
		Show_error_info(Error_info_allocation_failed);
		return;
	}
	for (unsigned int i = 1; i <= present_event_amount; i++)
		if (reminder[i - 1].day == find_day)
		{
		store_find_id[day_count] = i;
		day_count++;
		}
	if (day_count == 0) printf("No finding for day %d\n", (int)find_day);
	else
		for (unsigned int i = 1; i <= day_count; i++)
			Show_id_detailed_info(store_find_id[i - 1]);
	free(store_find_id);
}

void Print_by_range_process(void)
{
	unsigned char start_day;
	unsigned char end_day;
	start_day = Get_a_day("Please enter the starting day:");
	end_day = Get_a_day("Please enter the ending day:");
	if (start_day>end_day)
	{
		printf("Reverse them automatically...\n");
		int temp = start_day;
		start_day = end_day;
		end_day = temp;
	}
	unsigned int *store_find_id;
	unsigned int day_count = 0;
	if (!(store_find_id = (unsigned int*)malloc(sizeof(unsigned int)*present_event_amount)))
	{
		Show_error_info(Error_info_allocation_failed);
		return;
	}
	for (unsigned int i = 1; i <= present_event_amount; i++)
		if (reminder[i - 1].day <= end_day&&reminder[i - 1].day >= start_day)
		{
		store_find_id[day_count] = i;
		day_count++;
		}
	if (day_count == 0) printf("no finding in the range from %d to %d.\n", (int)start_day, (int)end_day);
	else
		for (unsigned int i = 1; i <= day_count; i++)
			Show_id_detailed_info(store_find_id[i - 1]);
	free(store_find_id);
}

void Print_by_parts_process(void)
{
	bool selected_day[31] = { false };
	unsigned int *store_find_id;
	unsigned int day_count = 0;
	if (!(store_find_id = (unsigned int*)malloc(sizeof(unsigned int)*present_event_amount)))
	{
		Show_error_info(Error_info_allocation_failed);
		return;
	}
	printf("Please enter some days:");
	if (Get_some_days_selected(selected_day) == 0) printf("User haven\'t entered anything...\n");
	else
	{
		for (unsigned int i = 1; i <= present_event_amount; i++)
			if (selected_day[reminder[i - 1].day - 1])
			{
			store_find_id[day_count] = i;
			day_count++;
			}
		if (day_count == 0) printf("no finding in these parts.\n");
		else
			for (unsigned int i = 1; i <= day_count; i++)
			{
				Print_small_line();
				Show_id_detailed_info(store_find_id[i - 1]);
			}
	}
	free(store_find_id);
}

char Get_command_order(void)
{
	char ch;
	do
	{
		printf("A--add  D--delete  S--search  P--print  E--exit\n");
		printf("Please enter your selection:");
		ch = Get_a_upper_letter();
	} while (ch != 'A'&&ch != 'D'&&ch != 'S'&&ch != 'P'&&ch != 'E');
	return ch;
}

char Get_a_upper_letter(void)
{
	char ch;
	if ((ch = toupper(getchar())) != '\n') Get_rid_of_RestLine();
	return ch;
}

void Show_start_info(void)
{
	printf("--------------Amazing CA inc program-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("A reminder to remind youu some events.\n");
	Print_divide_line();
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

void Print_small_line(void)
{
	printf("--------------------------\n");
}

void Show_exit_info(void)
{
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while ((ch = getchar()) != '\n') continue;
}

bool Safe_read_name(char *s, int n)
//Empty word return false, true means at least one letter read.
{
	char ch;
	while (isspace(ch = getchar()) && ch != '\n') continue;
	if (ch == '\n')
	{
		s = '\0';
		return false;
	}
	do
	{
		*s++ = ch;
		n--;
		ch = getchar();
	} while (ch != '\n'&&n>0);
	if (ch != '\n') Get_rid_of_RestLine();
	*s = '\0';
	return true;
}
