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

#define Country_amount 32
#define Max_country_name_length 20 /*Only used in search by name*/

struct dialing_code
{
	char *country;
	unsigned short code;
};

const struct dialing_code country_code[Country_amount]=
{
	{"Argentina",            54},{"Bangladesh",          890},
	{"Brazil",               55},{"Burma (Myanmar)",      95},
	{"China",                86},{"Colombia",             57},
	{"Congo, Dem. Rep. of", 243},{"Egypt",                20},
	{"Ethiopia",            251},{"France",               33},
	{"Germany",              49},{"India",                91},
	{"Indonesia",            62},{"Iran",                 98},
	{"Italy",                39},{"Japan",                81},
	{"Mexico",               52},{"Nigeria",             234},
	{"Pakistan",             92},{"Philippines",          63},
	{"Poland",               48},{"Russia",                7},
	{"South Africa",         27},{"Korea",                82},
	{"Spain",                34},{"Sudan",               249},
	{"Thailand",             66},{"Turkey",               90},
	{"Ukraine",             380},{"United Kingdom",       44},
	{"United States",         1},{"Vietnam",              84}
};

void Show_start_info(void);
void Show_exit_info(void);
void Print_divide_line(void);
void Get_rid_of_RestLine(void);
void Show_st(int);
bool Is_try_again(void);
void Main_program(void);
bool Get_is_by_code(void);
void Search_by_code_process(void);
void Search_by_country_process(void);
void Print_small_line(void);
bool Safe_read_name(char *,int);
bool Rough_whole_name_search(char *,char*);
bool Decent_name_search(const char *, const char *);

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

void Main_program(void)
{
	bool is_by_code=Get_is_by_code();
	switch(is_by_code)
	{
		case true:Search_by_code_process();break;
		case false:Search_by_country_process();break;
	}
	Print_divide_line();
}

bool Get_is_by_code(void)
{
	char ch;
	do
	{
		printf("Search by code--O, by country--C\n");
		printf("Enter your selection: ");
		ch=toupper(getchar());
		if(ch!='\n') Get_rid_of_RestLine();
	}while(ch!='O'&&ch!='C');
	Print_small_line();
	return ch=='O';
}

void Search_by_code_process(void)
{
	int code, scanf_check;
	do
	{
		printf("Please enter your code:");
		scanf_check=scanf("%d",&code);
		Get_rid_of_RestLine();
	}while(scanf_check<1||code<=0);
	Print_small_line();
	bool find_country=false;
	int country_point;
	for(int i=1;i<=Country_amount&&!find_country;i++)
		if(country_code[i-1].code==code)
		{
			country_point=i;
			find_country=true;
		}
	if(find_country)
	{
		printf("Country: %s\n", country_code[country_point-1].country);
		printf("Code: %hu\n", country_code[country_point-1].code);
	}
	else
		printf("Nothing found in our datebase.\n");
}

void Search_by_country_process(void)
{
	char target_name[Max_country_name_length+1];
	bool read_suc;
	do
	{
		printf("Please enter the country name:");
		read_suc=Safe_read_name(target_name, Max_country_name_length);
	}while(!read_suc);
	Print_small_line();
	bool find_target=false;
	for(int i=1;i<=Country_amount;i++)
		if (Rough_whole_name_search(country_code[i-1].country,target_name))
		{
			find_target=true;
			printf("Country:%s\n",country_code[i-1].country);
			printf("With code:%hu\n",country_code[i-1].code);
		}
	if(!find_target)
	{
		printf("No such result matched.\n");
		Print_small_line();
		char ch;
		do
		{
			printf("Do you hope a decent search(Y/N)--");
			ch=toupper(getchar());
			if(ch!='\n') Get_rid_of_RestLine();
		}while(ch!='Y'&&ch!='N');
		if(ch=='Y')
		{
			int no_point=1;
			for(int i=1;i<=Country_amount;i++)
				if(Decent_name_search(country_code[i-1].country,target_name))
				{
					Print_small_line();
					printf("%d",no_point);Show_st(no_point);printf(" result:\n");
					printf("Country: %s\n",country_code[i-1].country);
					printf("With code: %hu\n",country_code[i-1].code);
					no_point++;
				}
		}
	}
}

bool Rough_whole_name_search(char *s1, char *s2)
{
	while(toupper(*s1)==toupper(*s2))
	{
		if(*s1=='\0') return true;
		s1++;s2++;
	}
	return false;
}

bool Decent_name_search(const char *main_string, const char *target)
{
	int len1=strlen(main_string),
	    len2=strlen(target);
	if(len1<len2) return false;
	bool match_suc;
	for(int i=0;i<=len1-len2;i++)
	{
		match_suc=true;
		for(int t=0;t<=len2-1;t++)
			if(toupper(main_string[i+t])!=toupper(target[t])) match_suc=false;
		if(match_suc) return true;
	}
	return false;
}

bool Safe_read_name(char *s, int n)
//if nothing captured return false, else return true
{
	char ch;
	while(isspace(ch=getchar())&&ch!='\n') continue;
	if(ch=='\n')
	{
		*s='\0';
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

void Show_start_info(void)
{
	printf("--------------Amazing CA inc program-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("Program is used to search the phone number code for each country.\n");
	printf("You have two ways to use it.\n");
	printf("By code or by country name.\n");
	Print_divide_line();
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

void Print_small_line(void)
{
	printf("---------------------------\n");
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
