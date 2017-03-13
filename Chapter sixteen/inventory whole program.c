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
#define Max_component_name_length 20
#define Max_component_amount 64
#define Max_component_store_amount 10086

#define Error_info_replacement
#
#if defined Error_info_replacement
#define Error_info_store_amount_overflow 1
#define Error_info_component_amount_overflow 2
#define Error_info_no_match_component 3
#define Error_info_illegal_entrance 4
#define Error_info_store_amount_downflow 5
#endif

#define Find_info_replacement
#
#if defined Find_info_replacement
#define Find_by_ID 1
#define Find_by_number 2
#define Find_by_name 3
#define Find_by_amount 4
#endif

void Show_start_info(void);
void Show_exit_info(void);
void Show_error_info(int error_code);

void Print_divide_line(void);
void Get_rid_of_RestLine(void);

char Get_command_order(void);
void Show_command_info(void);
void Add_component_process(void);
void Delete_component_process(void);
void Print_component_process(void);
void Search_component_process(void);
void Find_by_ID_process(void);
void Find_by_number_process(void);
void Find_by_name_process(void);
bool Decent_find_match(const char *s1,const char *s2);
void Find_by_amount_process(void);
int Find_id(signed short number, bool *check);
bool Safe_read_name(char *s,int n);

struct component
{
	signed short number;
	char name[Max_component_name_length+1];
	unsigned long present_amount;
} inventory[Max_component_amount];

int present_component_amount=0;

int main(int argc, char *argv[])
{
	bool exitpoint=false;
	char command;
	Show_start_info();
	do
	{
		command=Get_command_order();
		switch(command)
		{
			case 'a':
			Add_component_process();break;
			case 'd':
			Delete_component_process();break;
			case 'p':
			Print_component_process();break;
			case 's':
			Search_component_process();break;
			case 'e':
			exitpoint=true;break;
			default:
			Show_error_info(Error_info_illegal_entrance);
		}
		Print_divide_line();
	}while(!exitpoint);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

void Show_command_info(void)
{
	printf("a--Add  d--Delete  p--Print info  s--Search  e--Exit\n");
}

void Show_start_info(void)
{
	printf("------------Inventory management program--------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("Add/Delete some content\n");
	printf("Print the whole inventory info\n");
	printf("Search for exact item\n");
	Print_divide_line();
}

void Show_exit_info(void)
{
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}

void Show_error_info(int error_code)
{
	switch(error_code)
	{
		case Error_info_store_amount_overflow:
		printf("Error, can\'t store such amount, due to max amount %lu.\n",(unsigned long)Max_component_store_amount);break;
		case Error_info_component_amount_overflow:
		printf("Error, inventory storage is full, due to max amount %lu.\n",(unsigned long)Max_component_amount);break;
		case Error_info_no_match_component:
		printf("Error,can\'t find such item in inventory.\n");break;
		case Error_info_illegal_entrance:
		printf("Error, unexpected entrance.\n");break;
		case Error_info_store_amount_downflow:
		printf("Error, storage number can\'t be negative.\n");break;
	}
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

char Get_command_order(void)
{
	char ch;
	Show_command_info();
	do
	{
		printf("Enter your command:");
		if((ch=getchar())!='\n') Get_rid_of_RestLine();
	}while(isspace(ch));
	return tolower(ch);
}

void Add_component_process(void)
{
	printf("======Add component======\n");
	signed short number;
	signed char check;
	bool find_check;
	do
	{
		printf("Please enter the component number:");
		check=scanf("%hd",&number);
		Get_rid_of_RestLine();
	}while(check<1);
	int id=Find_id(number,&find_check);
	/*find_check means find it already existing*/
	if(find_check)
	{
		printf("----------------------------------------\n");
		printf("Component already existing in inventory.\n");
		printf("Component info:\n");
		printf("ID: %d\n",id);
		printf("Number: %hd\n",inventory[id-1].number);
		printf("Name: %s\n",inventory[id-1].name);
		printf("Amount: %lu\n",inventory[id-1].present_amount);
		printf("----------------------------------------\n");
		long add_amount_temp;
		int scanf_check;
		do
		{
			add_amount_temp=-1l;
			printf("Please enter add amount:");
			scanf_check=scanf("%ld",&add_amount_temp);
			Get_rid_of_RestLine();
		}while(scanf_check<1||add_amount_temp<=0);
		if((unsigned long)add_amount_temp+inventory[id-1].present_amount<=Max_component_store_amount)
		{
			inventory[id-1].present_amount+=add_amount_temp;
			printf("Add succussfully done.\n");
		}
		else Show_error_info(Error_info_store_amount_overflow);
	}
	else if(id<=Max_component_amount)
	{
		bool length_check_temp;
		struct component new_component;
		new_component.number=number;
		do
		{
			printf("Please name this new item:");
			length_check_temp=Safe_read_name(new_component.name,Max_component_name_length);
		}while(!length_check_temp);
		long add_amount_temp;
		int scanf_check;
		do
		{
			add_amount_temp=-1l;
			printf("Please enter the amount:");
			scanf_check=scanf("%ld",&add_amount_temp);
			Get_rid_of_RestLine();
			if(add_amount_temp>Max_component_store_amount&&scanf_check>0) Show_error_info(Error_info_store_amount_overflow);
		}while(scanf_check<1||add_amount_temp<=0||add_amount_temp>Max_component_store_amount);
		new_component.present_amount=add_amount_temp;
		inventory[id-1]=new_component;
		present_component_amount++;
		printf("New item store in inventory successfully.\n");
	}
	else Show_error_info(Error_info_component_amount_overflow);
}

void Delete_component_process(void)
{
	printf("=====Delete component====\n");
	signed short number;
	signed char check;
	bool find_check;
	do
	{
		printf("Please enter the component number:");
		check=scanf("%hd",&number);
		Get_rid_of_RestLine();
	}while(check<1);
	int id=Find_id(number,&find_check);
	/*find_check means find it already existing*/
	if(find_check)
	{
		printf("----------------------------------------\n");
		printf("Component found in inventory.\n");
		printf("Component info:\n");
		printf("ID: %d\n",id);
		printf("Number: %hd\n",inventory[id-1].number);
		printf("Name: %s\n",inventory[id-1].name);
		printf("Amount: %lu\n",inventory[id-1].present_amount);
		printf("----------------------------------------\n");
		long delete_amount_temp;
		int scanf_check;
		do
		{
			delete_amount_temp=-1l;
			printf("Please enter delete amount:");
			scanf_check=scanf("%ld",&delete_amount_temp);
			Get_rid_of_RestLine();
		}while(scanf_check<1||delete_amount_temp<=0);
		long long then_amount=(long long)inventory[id-1].present_amount-(long long)delete_amount_temp;
		if(then_amount>0)
		{
			inventory[id-1].present_amount=(unsigned long)then_amount;
			printf("Delete succussfully done.\n");
		}
		else if(then_amount==0)
		{
			for(int i=id-1;i<=present_component_amount-2;i++)
				inventory[i]=inventory[i+1];
			present_component_amount--;
			printf("Remove Item from the inventory successfully.\n");
		}
		else Show_error_info(Error_info_store_amount_downflow);
	}
	else Show_error_info(Error_info_no_match_component);
}

void Print_component_process(void)
{
	printf("======Show inventory info=====\n");
	printf("Now it got %d items exactly.\n",present_component_amount);
	printf("For detailed one info, please use search mode.\n");
}

void Search_component_process(void)
{
	printf("======Find component=====\n");
	char ch;
	do
	{
		printf("Please select how to find your component.\n");
		printf("1--ID  2--number  3--name  4--amount\n");
		printf("Enter your selecting:");
		if((ch=getchar())!='\n') Get_rid_of_RestLine();
	}while(ch<='0'||ch>='5');
	
	switch(ch-'0')
	{
		case Find_by_ID:Find_by_ID_process();break;
		case Find_by_number:Find_by_number_process();break;
		case Find_by_name:Find_by_name_process();break;
		case Find_by_amount:Find_by_amount_process();break;
	}
}

void Find_by_ID_process(void)
{
	int id;
	signed char check;
	do
	{
		printf("Please enter the finding ID:");
		check=scanf("%d",&id);
		Get_rid_of_RestLine();
	}while(check<1);
	if(id<=present_component_amount)
	{
		printf("----------------------------------------\n");
		printf("Component found in inventory.\n");
		printf("Component info:\n");
		printf("ID: %d\n",id);
		printf("Number: %hd\n",inventory[id-1].number);
		printf("Name: %s\n",inventory[id-1].name);
		printf("Amount: %lu\n",inventory[id-1].present_amount);
		printf("----------------------------------------\n");
	}
	else Show_error_info(Error_info_no_match_component);
}

void Find_by_number_process(void)
{
	signed short number;
	signed char check;
	bool find_check;
	do
	{
		printf("Please enter the finding number:");
		check=scanf("%hd",&number);
		Get_rid_of_RestLine();
	}while(check<1);
	int id=Find_id(number,&find_check);
	/*find_check means find it already existing*/
	if(find_check)
	{
		printf("----------------------------------------\n");
		printf("Component already existing in inventory.\n");
		printf("Component info:\n");
		printf("ID: %d\n",id);
		printf("Number: %hd\n",inventory[id-1].number);
		printf("Name: %s\n",inventory[id-1].name);
		printf("Amount: %lu\n",inventory[id-1].present_amount);
		printf("----------------------------------------\n");
	}
	else Show_error_info(Error_info_no_match_component);
}

void Find_by_name_process(void)
{
	char find_target_name[Max_component_name_length+1];
	bool enter_check;
	do
	{
		printf("Please enter the finding name:");
		enter_check=Safe_read_name(find_target_name,Max_component_name_length);
	}while(!enter_check);
	bool find_check=false;
	printf("----------------------------------------\n");
	for(int i=0;i<=present_component_amount-1;i++)
		if(strcmp(inventory[i].name,find_target_name)==0)
		{
			find_check=true;
			printf("ID: %d\n",i+1);
			printf("Number: %hd\n",inventory[i].number);
			printf("Name: %s\n",inventory[i].name);
			printf("Amount: %lu\n",inventory[i].present_amount);
			printf("----------------------------------------\n");
		}
	if(!find_check)
	{
		printf("No finding for name \"%s\"\n",find_target_name);
		char ch;
		do
		{
			printf("Do you hope a decent search result(Y/N)---");
			if((ch=toupper(getchar()))!='\n') Get_rid_of_RestLine();
		}while(ch!='Y'&&ch!='N');
		if(ch=='Y')
		{
			bool decent_find_result=false;
			printf("----------------------------------------\n");
			for(int i=0;i<=present_component_amount-1;i++)
			if(Decent_find_match(inventory[i].name,find_target_name))
			{
				decent_find_result=true;
				printf("ID: %d\n",i+1);
				printf("Name: %s\n",inventory[i].name);
				printf("----------------------------------------\n");
			}
			if(!decent_find_result) printf("No decent result\n");
		}
	}
}

bool Decent_find_match(const char *s1,const char *s2)
{
	int len1=strlen(s1),len2=strlen(s2);
	if(len1<len2) return false;
	else
	{
		for(int i=0;i<=len1-len2;i++)(toupper(s1[i+temp])!=toupper(s2[temp]))
		{
			bool check=true;
			for(int temp=0;temp<=len2-1;temp++)
				if(toupper(s1[i+temp])!=toupper(s2[temp])) check=false;
			if (check) return true;
		}
	}
	return false;
}

void Find_by_amount_process(void)
{
	long find_target_amount;
	signed char check;
	do
	{
		printf("Please enter the finding amount:");
		check=scanf("%ld",&find_target_amount);
		Get_rid_of_RestLine();
	}while(check<1&&find_target_amount<=0);
	printf("----------------------------------------\n");
	bool find_check=false;
	for(int i=0;i<=present_component_amount-1;i++)
		if((unsigned long)find_target_amount==inventory[i].present_amount)
		{
			find_check=true;
			printf("ID: %d\n",i);
			printf("Number: %hd\n",inventory[i].number);
			printf("Name: %s\n",inventory[i].name);
			printf("----------------------------------------\n");
		}
	if(!find_check) Show_error_info(Error_info_no_match_component);
}

int Find_id(signed short number, bool *check)
/*Return ID range from i-Max_component_amount*/
{
	*check=false;
	int i;
	for(i=0;i<present_component_amount;i++)
		if(inventory[i].number==number) {*check=true;break;}
	if(*check) return i+1;
	else return present_component_amount+1;
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
	}while(ch!='\n'&&n>0);
	if(ch!='\n') Get_rid_of_RestLine();
	*s='\0';
	return true;
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while((ch=getchar())!='\n') continue;
}
