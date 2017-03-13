//standard function call include
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
//local function call include
#include "search.h"
#include "adjust.h"
#include "structure.h"
//database include
#include "data.h"

bool Get_is_by_code(void);
void Search_by_code_process(void);
void Search_by_country_process(void);
bool Safe_read_name(char *,int);
bool Rough_whole_name_search(char *,char*);
bool Decent_name_search(const char *, const char *);

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
