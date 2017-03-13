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

#define Max_word_length 20

#define Initialized_array_length 20
#define Every_extern_length 10

#define Error_info_alloaction_failed 1

void Main_program(void);
void Sort_words(char **, size_t);
int Compare_word(const void *, const void *);
void Show_start_info(void);
void Show_exit_info(void);
void Print_divide_line(void);
void Print_small_line(void);
void Show_error_info(int);
char *Capture_words(size_t);

int main(int argc, char argv[])
{
	Show_start_info();
	Main_program();
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

void Main_program(void)
{
	char **word_array=(char **)malloc(sizeof(char *)*Initialized_array_length);
	size_t present_word_amount=0;
	size_t present_array_length=Initialized_array_length;
	bool checkpoint=false;
	do
	{
		if(present_word_amount>=present_array_length)
		{
			char **temp=(char **)realloc(word_array,sizeof(char *)*(present_array_length+Every_extern_length));
			if(temp==NULL)
			{
				Show_error_info(Error_info_alloaction_failed);
				break;
			}
			word_array=temp;
			present_array_length=present_array_length+Every_extern_length;
		}
		printf("Enter a word:");
		char *temp=Capture_words(Max_word_length);
		if(temp==NULL) checkpoint=true;
		else
			word_array[present_word_amount++]=temp;
	}while(!checkpoint);
	qsort((void *)word_array, present_word_amount, sizeof(char *), Compare_word);
	printf("\nThe result is shown as below\n");
	Print_small_line();
	if(present_word_amount==0) printf("NONE!");
	int p = 0;
	for (size_t i = 1; i <= present_word_amount; i++)
	{
		printf("%s ", word_array[i - 1]);
		if ((p = (p + 1) % 5) == 0) putchar('\n');
	}
	putchar('\n');
}

int Compare_word(const void *left, const void *right)
{
	char *temp_l = *((char **)left),
	     *temp_r = *((char**)right);
	return strcmp(temp_l,temp_r);
}

/*
int strcmp(const char *s1, const char *s2)
{
	while(*s1==*s2)
	{
		if(*s1=='\0') return 0;
		s1++;s2++;
	}
	return *s1-*s2;
}
*/

char *Capture_words(size_t len)
{
	char *temp=(char *)malloc(len+1);
	if(temp==NULL)
	{
		Show_error_info(Error_info_alloaction_failed);
		return NULL;
	}
	size_t count=0;
	bool check=false;
	char ch;
	while((ch=getchar())!='\n')
		if(count<len)
			if(isspace(ch))
				check=true;
			else if(!check)
				temp[count++]=ch;
	if(count==0)
	{
		free(temp);
		return NULL;
	}
	temp[count]='\0';
	temp=(char *)realloc(temp,count+1);
	return temp;
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

void Show_error_info(int code)
{
	switch (code)
	{
		case Error_info_alloaction_failed:printf("Error, allocation failed.\n");
	}
}
