/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/
/* PR1.c (Chapter 13, page 210) */
#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h> /* scanf printf getchar putchar qsort */
/* fopen freopen setvbuf fflush rewind fseek ftell fgetpos fsetpos fclose tmpfile */
/* tmpnam L_tmpnam TMP_MAX _IOFBF _IOLBF _IONBF SEEK_SET SEEK_CUR SEEK_END fpos_t */
/* FILENAME_MAX stdin stdout stderr */
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace size_t */
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* memcpy strcpy(n) strlen strcat(n) strcmp memmove */
#include <time.h> /* time */
#include <stddef.h> /* offsetof */

/* User's header */
#include "core_function.h"
#include "databaseADT.h"

/* Header Macro error check */
#ifndef Decent_match_percentage
#error Decent_match_percentage in core_function.h NOT found
#elif Decent_match_percentage<1||Decent_match_percentage>100
#error Decent_match_percentage beyond range
#endif
#ifndef Sale_could_more_than_store
#error Sale_could_more_than_store in core_function.h NOT found
#elif Sale_could_more_than_store!=1&&Sale_could_more_than_store!=0
#error Sale_could_more_than_store beyond range
#endif

/* Macro for static use */
#define INFO_database_unloaded 1
#define INFO_file_saved_successfully 2
#define INFO_database_creating_successfully 3
#define INFO_Database_empty 4
#define INFO_item_not_existing 5
#define INFO_item_added_successfully 6
#define INFO_item_removed_successfully 7
#define INFO_saled_more_than_store_saling_failed 8
#define INFO_saled_more_than_store_saling_permitted 9
#define INFO_item_name_not_matched_showing_decent_match_result 10
#define INFO_database_loaded_successully 11
#define INFO_item_saled_successfully 12
#define INFO_info_could_not_be_empty 13
#define INFO_info_add_cuccessfully 14
#define INFO_failed_to_combine_files 15
#define INFO_file_combined_successfully 16

#define ERROR_file_access_denied 1
#define ERROR_file_saving_failed 2
#define ERROR_database_failed_by_generating 3
#define ERROR_failed_to_add_item 4
#define ERROR_failed_to_add_info 5

struct date
{
	unsigned int year;
	unsigned char month;
	unsigned char day;
};

/* FILE static variable */
static Data database=NULL;

/* Static function decleration */
static char *Inputing_url(char *enter_message, size_t len, char *buf);
static void Search_database_by_ID(void);
static void Search_database_by_inputing_date(void);
static void Search_database_by_modify_date(void);
static void Search_database_by_stored_amount(void);
static void Search_database_by_saled_amount(void);
static int Compare_two_date(struct date *first, struct date *second);
static void Getting_a_date_from_stdin(char *enter_message, struct  date *date);
static int Check_date_acceptable(struct date *check_date);
static bool Is_leap_year(unsigned int year);
static void Sort_info(char *s, unsigned int length);
static void Show_item_detailed_info(size_t ID);
static void Display_error(int error_code);
static void Display_info(int info_code);
static void Search_database_by_name(void);
static void Change_database_info_process(void);
static void Change_item_info_process(void);

void Show_present_procedure(void)
{
	fprintf(stdout, "==========Inventory info==========\n");
	if(database==NULL)
		Display_info(INFO_database_unloaded);
	else
	{
		char *temp = ALLOCATE_database_create_date(database);
		fprintf(stdout ,"%s\n", temp);
		free(temp);
		#ifdef _WIN32
			fprintf(stdout, "Item amount: %u\n", Get_database_amount(database));
		#elif
			fprintf(stdout, "Item amount: %llu\n", Get_database_amount(database));
		#else
			#error basically ONLY supporting _WIN32 or _WIN64 by size_t type
		#endif
		char *info_temp = Get_database_info(database);
		fprintf(stdout, "INFO:");
		if (info_temp == NULL) fprintf(stdout, "NONE");
		else
		{
			putc('\n', stdout);
			Sort_info(info_temp, Info_display_length);
		}
	}
	Divide_line();
}

void Load_database_procedure(void)
{
	if (database != NULL) Destroy_database(database);
	char url[FILENAME_MAX];
	Inputing_url("Please enter file url", FILENAME_MAX, url);
	if ((database = Loading_database(url)) == NULL)
		Display_error(ERROR_file_access_denied);
	else Display_info(INFO_database_loaded_successully);
}

void Output_databse_procedure(void)
{
	if(database==NULL)
	{
		Display_info(INFO_database_unloaded);
		return;
	}
	char url[FILENAME_MAX];
	Inputing_url("Please enter file url", FILENAME_MAX, url);
	char *temp = url;
	if (strlen(url) == 0) temp == NULL;
	if (Saving_database(database, temp) == EOF)
		Display_error(ERROR_file_saving_failed);
	else
		Display_info(INFO_file_saved_successfully);
}

void Creating_database_procedure(void)
{
	if (database != NULL) Destroy_database(database);
	database = Generate_database();
	if (database == NULL) Display_error(ERROR_database_failed_by_generating);
	else Display_info(INFO_database_creating_successfully);
}

void Search_database_procedure(void)
{
	if (database == NULL)
	{
		Display_info(INFO_database_unloaded);
		return;
	}
	else if (Get_database_amount(database) == 0)
	{
		Display_info(INFO_Database_empty);
		return;
	}
	char order = Get_a_lower_range
		("I--id  N--name  P--inputing_date  M--modfiy_date  S--store_amount  L--saled_amount",
		 "Please enter your choice",
		 "inpmsl");
	Divide_line();
	switch (order)
	{
		case 'i': Search_database_by_ID();break;
		case 'n': Search_database_by_name();break;
		case 'p': Search_database_by_inputing_date();break;
		case 'm': Search_database_by_modify_date();break;
		case 's': Search_database_by_stored_amount();break;
		case 'l': break;
	}
}

static void Search_database_by_ID(void)
{
	int temp;
	size_t ID;
	do
	{
		fprintf(stdout, "Please enter ID:");
		#ifdef _WIN32
			temp=fscanf(stdin, "%u", &ID);
		#elif defined(_WIN64)
			temp=fscanf(stdin, "%llu",&ID);
		#else
			#error basically ONLY supporting _WIN32 or _WIN64 by size_t type
		#endif
		Clean_stdin();
	} while (temp < 1);
	if(Get_database_amount(database)<ID)
	{
		Display_info(INFO_item_not_existing);
		return;
	}
	Show_item_detailed_info(ID);
}

static void Search_database_by_name(void)
{
	char name[Item_name_length + 1];
	Inputing_url("Please input a name:", Item_name_length, name);
	bool find_it = false;
	char *temp;
	for (size_t i = 1; i <= Get_database_amount(database); i++)
	{
		temp=Get_item_name(database, i);
		if (strcmp(temp, name) == 0)
		{
			putc('\n', stdout);
			Show_item_detailed_info(i);
			find_it = true;
		}
	}
	if (!find_it)
	{
		Display_info(INFO_item_name_not_matched_showing_decent_match_result);
		size_t least_letters_to_match, letter_matched_amount, item_name_length;
		char *item_point, *input_name_point, *temp_point;
		for (size_t i = 1; i <= Get_database_amount(database); i++)
		{
			item_point=Get_item_name(database, i);
			input_name_point=name;
			item_name_length=strlen(item_point);
			least_letters_to_match=item_name_length*Decent_match_percentage/100;
			letter_matched_amount=0;
			for(size_t t=1; t<=item_name_length; t++)
			{
				temp_point=input_name_point;
				while(*temp_point!=item_point[t-1]&&*temp_point!='\0')
					temp_point++;
				if(*temp_point==item_point[t-1])
				{
					input_name_point=temp+1;
					letter_matched_amount++;
				}
			}
			if(letter_matched_amount>=least_letters_to_match)
			{
				putc('\n', stdout);
				Show_item_detailed_info(i);
			}
		}
	}
}

static void Search_database_by_inputing_date(void)
{
	fprintf(stdout, "Finding item with a range of date.\n");
	struct date start, end;
	Getting_a_date_from_stdin("Please input starting date:", &start);
	Getting_a_date_from_stdin("Please input ending date:", &end);
	if(Compare_two_date(&start, &end)>0)
	{
		struct date temp=start;
		start=end;
		end=temp;
	}
	struct date item;
	int year,month,day;
	bool check=false;
	for(size_t i=1; i<=Get_database_amount(database); i++)
	{
		Get_item_date(database, i, GET_item_date_input, &year, &month, &day, NULL, NULL, NULL);
		item.year=year;
		item.month=month;
		item.day=day;
		if(Compare_two_date(&item, &start)>0&&Compare_two_date(&item, &end)<0)
		{
			if(check) Divide_line();
			check=true;
			Show_item_detailed_info(i);
		}
	}
}

static void Search_database_by_modify_date(void)
{
	fprintf(stdout, "Finding item with a range of date.\n");
	struct date start, end;
	Getting_a_date_from_stdin("Please input starting date:", &start);
	Getting_a_date_from_stdin("Please input ending date:", &end);
	if(Compare_two_date(&start, &end)>0)
	{
		struct date temp=start;
		start=end;
		end=temp;
	}
	struct date item;
	int year,month,day;
	bool check=false;
	for(size_t i=1; i<=Get_database_amount(database); i++)
	{
		Get_item_date(database, i, GET_item_date_modify, &year, &month, &day, NULL, NULL, NULL);
		item.year=year;
		item.month=month;
		item.day=day;
		if(Compare_two_date(&item, &start)>0&&Compare_two_date(&item, &end)<0)
		{
			if(check) Divide_line();
			check=true;
			Show_item_detailed_info(i);
		}
	}
}

static void Search_database_by_stored_amount(void)
{
	unsigned long finding_amount;
	int temp;
	do
	{
		fprintf(stdout, "Please input an amount for search:");
		temp=fscanf(stdin, "%lu", &finding_amount);
		Clean_stdin();
	}while(temp!=1);
	bool check=false;
	for(size_t i=1; i<=Get_database_amount(database); i++)
		if(Get_item_store_amount(database, i)==finding_amount)
		{
			if(check) Divide_line();
			check=true;
			Show_item_detailed_info(i);
		}
}

static void Search_database_by_saled_amount(void)
{
	unsigned long finding_amount;
	int temp;
	do
	{
		fprintf(stdout, "Please input an amount for search:");
		temp=fscanf(stdin, "%lu", &finding_amount);
		Clean_stdin();
	}while(temp!=1);
	bool check=false;
	for(size_t i=1; i<=Get_database_amount(database); i++)
		if(Get_item_saled_amount(database, i)==finding_amount)
		{
			if(check) Divide_line();
			check=true;
			Show_item_detailed_info(i);
		}
}

/******************************************************
 *if first is more than second return positive number(1)
 *else if less return negative(-1)
 *else if accidentally equal return zero(0)
 ******************************************************/
static int Compare_two_date(struct date *first, struct date *second)
{	
	     if(first->year!=second->year)
				if(first->year>second->year) return 1;
				else return -1;
	else if(first->month!=second->month)
				if(first->month>second->month) return 1;
				else return -1;
	else if(first->day!=second->day)
				if(first->day>second->day) return 1;
				else return -1;
	else return 0;
}

static void Getting_a_date_from_stdin(char *enter_message, struct  date *date)
{
	int temp;
	do
	{
		fprintf(stdout, "%s (year/month/day):", enter_message);
		temp=fscanf(stdin, "%u/%hhu/%hhu", &date->year, &date->month, &date->day);
		Clean_stdin();
	} while (temp!=3||Check_date_acceptable(date));
}

static int Check_date_acceptable(struct date *check_date)
{
	if (check_date->month < 1 || check_date->month>12) return EOF;
	unsigned char day_every_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (Is_leap_year(check_date->year))day_every_month[1] += 1;
	if (check_date->day<1 || check_date->day>day_every_month[check_date->month]) return EOF;
	return 0;
}

static bool Is_leap_year(unsigned int year)
{
	if (year % 100 != 0)
		return year % 4 == 0;
	else
		return year % 400 == 0;
}

void Print_database_procedure(void)
{
	if (database == NULL)
	{
		Display_info(INFO_database_unloaded);
		return;
	}
	fprintf(stdout, "Database info:\n");
	char * temp;
	temp=ALLOCATE_database_create_date(database);
	fprintf(stdout, "%s\n", temp);
	free(temp);
	#ifdef _WIN32
		fprintf(stdout, "Item stored amount:%u\n", Get_database_amount(database));
	#elif defined(_WIN64)
		fprintf(stdout, "Item stored amount:%llu\n", Get_database_amount(database));
	#else
		#error basically ONLY supporting _WIN32 or _WIN64 by size_t type
	#endif
	fprintf(stdout, "Info:\n");
	Sort_info(Get_database_info(database), Info_display_length);
	if(Generate_database()==0)
	{
		fprintf(stdout, "Inventory has no item.\n");
		return;
	}
	for(size_t i=1; i<=Get_database_amount(database); i++)
	{
		putc('\n', stdout);
		Show_item_detailed_info(i);
	}
}

static void Sort_info(char *s, unsigned int length)
{
	unsigned int count=0u;
	if (s!=NULL)
		while(*s)
		{
			if(*s=='\n')
				count=0u;
			else if(count==length)
			{
				if (isalpha(*(s - 1)) && isalpha(*s)) putc('-', stdout);
				putc('\n', stdout);
				count=0u;
			}
			putc(*s++, stdout);
			count++;
		}
	else fprintf(stdout, "NONE");
	putc('\n', stdout);
}

void Add_item_procedure(void)
{
	if (database == NULL)
	{
		Display_info(INFO_database_unloaded);
		return;
	}
	char name[Item_name_length+1];
	Inputing_url("Please input Name", Item_name_length, name);
	int temp;
	unsigned long amount;
	do
	{
		fprintf(stdout, "Please input amount:");
		temp=fscanf(stdin, "%lu", &amount);
		Clean_stdin();
	}while(temp!=1);
	double price;
	do
	{
		fprintf(stdout, "Please input price:");
		temp=fscanf(stdin, "%lf", &price);
		Clean_stdin();
	}while(temp!=1);
	if (Adding_item(database, name, amount, price)!=0)
		Display_error(ERROR_failed_to_add_item);
	else
		Display_info(INFO_item_added_successfully);
}

void Delete_item_procedure(void)
{
	if (database == NULL)
	{
		Display_info(INFO_database_unloaded);
		return;
	}
	size_t ID;
	int temp;
	do
	{
		fprintf(stdout, "Please input ID (zero to terminate):");
		#ifdef _WIN32
			temp=fscanf(stdin, "%u", &ID);
		#elif defined(_WIN64)
			temp=fscanf(stdin, "%llu", &ID);
		#else
			#error basically ONLY supporting _WIN32 or _WIN64 by size_t type
		#endif
		Clean_stdin();
	}while(temp!=1);
	if(ID!=0)
		if(ID<=Get_database_amount(database))
		{
			Destory_item(database, ID);
			Display_info(INFO_item_removed_successfully);
		}
		else Display_info(INFO_item_not_existing);
}

void Sale_item_procedure(void)
{
	if (database == NULL)
	{
		Display_info(INFO_database_unloaded);
		return;
	}
	size_t ID;
	int temp;
	do
	{
		fprintf(stdout, "Please input ID (zero to terminate):");
		#ifdef _WIN32
			temp=fscanf(stdin, "%u", &ID);
		#elif defined(_WIN64)
			temp=fscanf(stdin, "%llu", &ID);
		#else
			#error basically ONLY supporting _WIN32 or _WIN64 by size_t type
		#endif
		Clean_stdin();
	}while(temp!=1);
	if(ID!=0)
		if(ID<=Get_database_amount(database))
		{
			unsigned long amount;
			do
			{
				fprintf(stdout, "Please input amount:");
				temp=fscanf(stdin, "%lu", &amount);
				Clean_stdin();
			}while(temp!=1);
			if(Get_item_store_amount(database, ID)<amount)
			{
				#if Sale_could_more_than_store
					Display_info(INFO_saled_more_than_store_saling_failed);
					return;
				#else
					Display_info(INFO_saled_more_than_store_saling_permitted);
				#endif
			}
			Sale_product_by_ID(database, ID, amount);
			Display_info(INFO_item_saled_successfully);
		}
		else Display_info(INFO_item_not_existing);
}

void Divide_line(void)
{
	fprintf(stdout, "-----------------------------------\n");
}

void Clean_stdin(void)
{
	while(getchar()!='\n') continue;
}

/******************************************************
 *Show_item_detailed_info
 *BY CALLING
 *Get_item_info
 *Get_item_name
 *Get_item_store_amount
 *Get_item_saled_amount
 *Get_item_price
 *If displace sucessfully return zero else return EOF
 ******************************************************/
static void Show_item_detailed_info(size_t ID)
{
	char *temp;
	if (database == NULL || ID > Get_database_amount(database)) return;
	#ifdef _WIN32
		fprintf(stdout, "Item ID:%u\n", ID);
	#elif defined(_WIN64)
		fprintf(stdout, "Item ID:%llu\n", ID);
	#else
		#error basically ONLY supporting _WIN32 or _WIN64 by size_t type
	#endif
	fprintf(stdout, "Name:%s\n", Get_item_name(database, ID));
	temp=ALLOCATE_item_input_date(database, ID);
	fprintf(stdout, "Input %s\n", temp);
	free(temp);
	temp=ALLOCATE_item_modify_date(database, ID);
	fprintf(stdout, "Modify %s\n", temp);
	free(temp);
	fprintf(stdout, "Stored amount:%lu\n", Get_item_store_amount(database, ID));
	fprintf(stdout, "Saled amount:%lu\n", Get_item_saled_amount(database, ID));
	fprintf(stdout, "Price:%g\n", Get_item_price(database, ID));
	fprintf(stdout, "Info:\n");
	Sort_info(Get_database_info(database), Info_display_length);
}

static char *Inputing_url(char *enter_message, size_t len, char *buf)
{
	fprintf(stdout, "%s:", enter_message);
	int ch;
	char *temp = buf;
	while ((ch = getchar())!='\n')
		if (len > 0)
		{
			*temp++ = ch;
			len--;
		}
	*temp = '\0';
	return buf;
}

void Change_info_procedure(void)
{
	if (database == NULL)
	{
		Display_info(INFO_database_unloaded);
		return;
	}
	char order=Get_a_lower_range("change info D--database  E--item", "Please enter your selection", "de");
	switch(order)
	{
		case 'd':Change_database_info_process();break;
		case 'e':Change_item_info_process();break;
	}
}

static void Change_database_info_process(void)
{
	char info[Info_length+1];
	Inputing_url("Please enter your info", Info_length, info);
	if(strlen(info)==0) Display_info(INFO_info_could_not_be_empty);
	else if(Adding_info_to_database(database, info)!=0) Display_error(ERROR_failed_to_add_info);
	else Display_info(INFO_info_add_cuccessfully);
}

static void Change_item_info_process(void)
{
	size_t ID;
	int temp;
	do
	{
		fprintf(stdout, "Please input ID (zero to terminate):");
		#ifdef _WIN32
			temp=fscanf(stdin, "%u", &ID);
		#elif defined(_WIN64)
			temp=fscanf(stdin, "%llu", &ID);
		#else
			#error basically ONLY supporting _WIN32 or _WIN64 by size_t type
		#endif
		Clean_stdin();
	}while(temp!=1);
	if(ID!=0)
		if (ID <= Get_database_amount(database))
		{
			char info[Info_length+1];
			Inputing_url("Please enter your info", Info_length, info);
			if(strlen(info)==0) 
			{
				Display_info(INFO_info_could_not_be_empty);
				return;
			}
			if (Adding_info_to_item(database, ID, info) != 0) Display_error(ERROR_failed_to_add_info);
			else Display_info(INFO_info_add_cuccessfully);
		}
		else Display_info(INFO_item_not_existing);
}

void Combining_files_procedure(void)
{
	char url_1[FILENAME_MAX+1], url_2[FILENAME_MAX+1];
	Inputing_url("Please enter the first url:", FILENAME_MAX, url_1);
	Inputing_url("Please enter the first url:", FILENAME_MAX, url_2);
	Data temp;
	if((temp=Combine_two_file(url_1, url_2))==NULL)
		Display_info(INFO_failed_to_combine_files);
	else
	{
		if(database!=NULL) Destroy_database(database);
		database=temp;
		Display_info(INFO_file_combined_successfully);
	}
}

char Get_a_lower_range(char *main_info, char *enter_info, char *range)
{
	char ch;
	bool check=false;
	fprintf(stdout, "%s\n", main_info);
	do
	{
		fprintf(stdout, "%s:", enter_info);
		ch=tolower(getc(stdin));
		if(ch!='\n') Clean_stdin();
		for(char *temp=range; *temp; temp++)
			if(tolower(*temp)==ch) check=true;
	}while(!check);
	return ch;
}

static void Display_error(int error_code)
{
	switch(error_code)
	{
		case ERROR_file_access_denied:
			fprintf(stdout, "ERROR:file can\'t be accessed.\n");
		break;
		case ERROR_file_saving_failed:
			fprintf(stdout, "ERROR:file can\'t be saved.\n");
		break;
		case ERROR_database_failed_by_generating:
			fprintf(stdout, "ERROR:failed to generate database.\n");
		break;
		case ERROR_failed_to_add_item:
			fprintf(stdout, "ERROR:failed to add new item.\n");
		break;
		case ERROR_failed_to_add_info:
			fprintf(stdout, "ERROR:failed to add info.\n");
		break;
	}
}

static void Display_info(int info_code)
{
	switch(info_code)
	{
		case INFO_database_unloaded:
			fprintf(stdout, "INFO:database is unloaded.\nPlease load with file or generate new one.\n");
		break;
		case INFO_file_saved_successfully:
			fprintf(stdout, "INFO:file saved successfully.\n");
		break;
		case INFO_database_creating_successfully:
			fprintf(stdout, "INFO:database created successfully.\n");
		break;
		case INFO_Database_empty:
			fprintf(stdout, "INFO:database has no items at present.\n");
		break;
		case INFO_item_not_existing:
			fprintf(stdout, "INFO:item is not existing\n");
		break;
		case INFO_item_added_successfully:
			fprintf(stdout, "INFO:item added successfully.\n");
		break;
		case INFO_item_removed_successfully:
			fprintf(stdout, "INFO:item removed successfully.\n");
		break;
		case INFO_saled_more_than_store_saling_failed:
			fprintf(stdout, "INFO:saled amount could not more than stored.\n");
		break;
		case INFO_saled_more_than_store_saling_permitted:
			fprintf(stdout, "INFO:saled more than stored, but accepted.\n");
		break;
		case INFO_item_name_not_matched_showing_decent_match_result:
			fprintf(stdout, "INFO:item name not found, displace decent seraching result.\n");
		break;
		case INFO_database_loaded_successully:
			fprintf(stdout, "INFO:database loaded successfully.\n");
		break;
		case INFO_item_saled_successfully:
			fprintf(stdout, "INFO:item saled successfully.\n");
		break;
		case INFO_info_could_not_be_empty:
			fprintf(stdout, "INFO:info must at least have one character.\n");
		break;
		case INFO_info_add_cuccessfully:
			fprintf(stdout, "INFO:information added successfully.\n");
		break;
		case INFO_failed_to_combine_files:
			fprintf(stdout, "INFO:failed to combine files.\n");
		break;
		case INFO_file_combined_successfully:
			fprintf(stdout, "INFO:files combined successfully.\n");
		break;
	}
}
