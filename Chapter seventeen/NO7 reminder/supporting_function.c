#define _CRT_SECURE_NO_DEPRECATE
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "supporting_function.h"

#include "reminder_limit.h"
#include "structure.h"

#include "external.h"

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

void Free_event_by_ID(unsigned int id)
{
	free(reminder[id - 1].message);
	//free the allocation storage
	for (unsigned int i = id; i <= present_event_amount - 1; i++)
		reminder[i - 1] = reminder[i];
	present_event_amount--;
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

char Get_a_upper_letter(void)
{
	char ch;
	if ((ch = toupper(getchar())) != '\n') Get_rid_of_RestLine();
	return ch;
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

char Get_a_range(char begin, char end, char *message,char *option)
{
	char ch;
	do
	{
		printf("%s\n",option);
		printf("%s",message);
		ch = Get_a_upper_letter();
		Print_small_line();
	} while (ch<begin || ch>end);
}