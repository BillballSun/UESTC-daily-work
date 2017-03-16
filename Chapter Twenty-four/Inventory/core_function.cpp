/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/

#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <ctype.h>

#include "my_assert.h"
#include "core_function.h"
#include "useful_macro.h"
#include "databaseADT.h"
#include "boolean.h"

/* Case replacement */
#define Insert 'i'
#define Search 's'
#define Update 'u'
#define Print 'p'
#define Exit 'e'
#define Save 's'
#define Load 'l'

jmp_buf environment;

Database data=NULL;
unsigned int error_code=0x00000000;

static void Recovery_process(void);
static void Insert_process(void);
static void Search_process(void);
static void Update_process(void);
static void Print_process(void);
static void Critical_exit_process(void);
static char Get_a_lower_range_from_stdin(char *message, char *range);
static void Divide_action(void);
static void Before_enter_order(void);
static bool Get_a_y_or_n(char *message);
static void Pause_for_a_second(void);
#ifdef Setjmp_action
static void Alarm_process(void);
#endif

void Core_process(void)
{
	char ch;
	bool exit_point;
	switch(setjmp(environment))
	{
		case 1:Recovery_process();
		/* No break fall through */
		case 0:
			while(!exit_point)
			{
				Before_enter_order();
				switch(ch=Get_a_lower_range_from_stdin( "Please input your selection(isupe)",
				"isupe"
				#ifdef Setjmp_action
				"a"
				#endif
				))
				{
					case Insert:Insert_process();break;
					case Search:Search_process();break;
					case Update:Update_process();break;
					case  Print:Print_process();break;
					case   Exit:exit_point=true;break;
					#ifdef Setjmp_action
					case  Alarm:Alarm_process();break;
					#endif
				}
				if(!exit_point) Divide_action();
			}
			break;
		case 2:
			Critical_exit_process();
			break;
	}
}

static void Before_enter_order(void)
{
	fprintf(stdout, "                         Database Info                          \n")
	if(data==NULL) fprintf(stdout, "INFO: database ungenerated, supposing using updating(load form file) or insert function.\n");
	else
	{
		size_t limit;
		char *temp;
		fputs(define Info_for_item_header, stdout);
		for(size_t i=1; i<=limit; i++)
		{
			temp=Allocate_info_for_an_item(data, i);
			assert(temp!=NULL);
			fprintf(stdout, "%s\n", temp);
			free(temp);
		}
	}
	fprintf(stdout, "----------------------------------------------------------------\n");
}

static void Divide_action(void)
{
	system("cls");
}

static void Pause_for_a_second(void)
{
	fprintf(stdout, "Press any key to continue....");
	if(getc(stdin)!='\n') putc('\n', stdout);
}

#ifdef Setjmp_action
static void Alarm_process(void)
{
	static int test=0;
	if(test<=1) test++;
	error_code=0x00000001;
	longjmp(environment, test);
}
#endif

static void Recovery_process(unsigned int code)
{
	fprintf(stderr, "Core_function encountered an unexpected error.\n"
					"Database will be flushed empty automatically.\n");
	fprintf(stderr, "Error code:%#X\n", error_code);
	if(data!=NULL)
	{
		Remove_database(data);
		data=NULL;
	}
}

static void Insert_process(void)
{
	if(data==NULL) if((data=Generate_database())==NULL) 
	{
		error_code=0x00000002;
		longjmp(environment, 1);
		return;
	}
	fprintf(stdout, "Add new item process.\n");
	fprintf(stdout, "Name:");
	char name[Item_name_length_max+1];
	fgets(name, Item_name_length_max+1, stdin);
	if(name[strlen(name)-1]=='\n') Clear_stdin();
	size_t stored_amount, saled_amount;
	int check;
	do
	{
		fprintf(stdout, "Stored amount:");
		check=fscanf(stdin, "%" Size_t_format_replacement, &stored_amount);
		Clear_stdin();
	}while(check!=1);
	do
	{
		fprintf(stdout, "Saled amount:");
		check=fscanf(stdin, "%" Size_t_format_replacement, &saled_amount);
		Clear_stdin();
	}while(check!=1);
	double price;
	do
	{
		fprintf(stdout, "Saled amount:");
		check=fscanf(stdin, "%lf", &price);
		Clear_stdin();
	}while(check!=1);
	fprintf(stdout, "Info:");
	char info[Item_info_length_max+1];
	fgets(info, Item_info_length_max+1, stdin);
	if(info[strlen(info)-1]=='\n') Clear_stdin();
	if(Add_item(data, name, stored_amount, saled_amount, price, info)!=0)
	{
		error_code=0x00000003;
		longjmp(environment, 1);
		return;
	}
}

static void Search_process(void)
{
	fprintf(stdout, "Search item process.\n");
	size_t count;
	char name[Item_name_length_max+1], info[Item_info_length_max+1];
	size_t stored_amount, saled_amount;
	double price;
	int check;
	unsigned char search_mode=0x00;
	#define Able_help(x) bool search_##x=Get_a_y_or_n("search "#x); \
						 if(search_##x)
	Able_help(name)
	{
		fprintf(stdout, "Name:");
		fgets(name, Item_name_length_max+1, stdin);
		if(name[strlen(name)-1]=='\n') Clear_stdin();
		search_mode|=Search_mode_name;
	}
	Able_help(stored_amount)
	{
		do
		{
			fprintf(stdout, "Stored amount:");
			check=fscanf(stdin, "%" Size_t_format_replacement, &stored_amount);
			Clear_stdin();
		}while(check!=1);
		search_mode|=Search_mode_store_amount;
	}
	Able_help(saled_amount)
	{
		do
		{
			fprintf(stdout, "Saled amount:");
			check=fscanf(stdin, "%" Size_t_format_replacement, &saled_amount);
			Clear_stdin();
		}while(check!=1);
		search_mode|=Search_mode_saled_amount;
	}
	Able_help(price)
	{
		do
		{
			fprintf(stdout, "Price:");
			check=fscanf(stdin, "%lf", &price);
			Clear_stdin();
		}while(check!=1);
		search_mode|=Search_mode_price;
	}
	Able_help(info)
	{
		fprintf(stdout, "Info:");
		fgets(info, Item_info_length_max+1, stdin);
		if(info[strlen(info)-1]=='\n') Clear_stdin();
		search_mode|=Search_mode_info;
	}
	size_t ID=Search_item(data, 1, name, stored_amount, saled_amount, price, info, search_mode);
	char *temp;
	if(ID==0)
		fprintf(stdout, "None found.\n");
	else
	{
		fputs(define Info_for_item_header, stdout);
		temp=Allocate_info_for_an_item(data, ID);
		assert(temp!=NULL);
		fprintf(stdout, "%s\n", temp);
		free(temp);
		while((ID=Search_item(data, ID+1, name, stored_amount, saled_amount, price, info, search_mode))!=0)
		{
			temp=Allocate_info_for_an_item(data, ID);
			assert(temp!=NULL);
			fprintf(stdout, "%s\n", temp);
			free(temp);
		}
	}
	Pause_for_a_second();
}

static bool Get_a_y_or_n(char *message)
{
	int ch;
	do
	{
		fprintf(stout, "%s(Y/N):", message);
		if((ch=tolower(getc(stdin)))!='\n') Clear_stdin();
	}while(ch!='y'&&ch!='n');
	return ch=='y';
}

static void Update_process(void)
{
	fprintf(stdout, "Do you wanna load or save database?\n");
	char order=Get_a_lower_range_from_stdin("Please enter selection(sl)", "sl");
	assert(order=='s'||order=='l');
	char url[FILENAME_MAX];
	switch(order)
	{
		case Save:
			if(data==NULL) fprintf(stdout, "Database missing? You can generate one by insert function...\n");
			else
			{
				fprintf(stdout, "Please enter the url:");
				fgets(url, FILENAME_MAX, stdin);
				if(url[strlen(url)-1]!='\n') Clear_stdin();
				#define File_already_exist 1
				#define File_canbe_created 0
				#define File_access_denied -1
				int Is_url_accepted(char *url);
				if(Is_url_accepted(url)==File_access_denied)
					fprintf(stdout, "Url is not accepted by computer.\n");
				else if(Is_url_accepted(url)==File_canbe_created||Get_a_y_or_n("File already exist, do you wanna rewrite it?"))
					Save_database(p, url);
			}
			break;
		case Load:
			if(data==NULL||Get_a_y_or_n("Database already exist, do you wanna replace it?"))
			{
				fprintf(stdout, "Please enter database url:");
				fgets(url, FILENAME_MAX, stdin);
				if(url[strlen(url)-1]!='\n') Clear_stdin();
				if(Is_url_accepted(url)!=File_already_exist)
					fprintf(stdout, "Url is not accepted by computer or file dosen\'t exist.\n");
				else
				{
					Database temp=Load_database(url);
					if(temp==NULL)
						fprintf(stdout, "File maybe damaged, loading failed.\n");
					else
					{
						if(data!=NULL) Remove_database(data);
						data=temp;
					}
				}
			}
			break;	
	}
	Pause_for_a_second();
}

static void Print_process(void)
{
	size_t limit;
	char *temp;
	if((limit=Get_database_item_amount(data))==0)
	{
		fprintf(stdout, "None found.\n");
	}
	else
	{
		fputs(define Info_for_item_header, stdout);
		for(size_t i=1; i<=limit; i++)
		{
			temp=Allocate_info_for_an_item(data, i);
			assert(temp!=NULL);
			fprintf(stdout, "%s\n", temp);
			free(temp);
		}
	}
	Pause_for_a_second();
}

static void Critical_exit_process(void)
{
	fprintf(stderr, "Critical threat, exit FAILURE.\n");
	fprintf(stderr, "Error code:%#X\n", error_code);
	system("pause");
	exit(EXIT_FAILURE);
}

static char Get_a_lower_range_from_stdin(char *message, char *range)
{
	char ch, *temp;
	bool check=false;
	do
	{
		fprintf(stdout, "%s: ", message);
		if((ch=tolower(getc(stdin)))!='\n')Clear_stdin();
		temp=range;
		while(*temp)
			if(tolower(*temp++)==ch) check=true;
	}while(!check);
	return ch;
}
