#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdbool.h>

#include "error_info.h"
#include "reminder_limit.h"

#include "main_program.h"
#include "delete_process.h"
#include "search_process.h"
#include "print_process.h"
#include "structure.h"
#include "supporting_function.h"
#include "info.h"

char Get_command_order(void);
void Add_process(void);
void Delete_process(void);
void Search_process(void);
void Print_process(void);

#include "external.h"

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
		Get_rid_of_RestLine();
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

void Delete_process(void)
{
	printf("====Delete an event====\n");
	if (present_event_amount == 0u)
	{
		Show_error_info(Error_info_reminder_empty);
		return;
	}
	char ch = Get_a_range('1', '3', "Please enter your way:","1--ID  2--day  3--message");
	switch (ch)
	{
	case '1':Delete_by_id_process(); break;
	case '2':Delete_by_day_process(); break;
	case '3':Delete_by_message_process(); break;
	}
}

void Search_process(void)
{
	printf("====Search an event====\n");
	char ch = Get_a_range('1', '2', "Enter your selection:", "1--by day  2--by message");
	switch (ch)
	{
	case '1':Search_by_day_process(); break;
	case '2':Search_by_message_process(); break;
	}
}

void Print_process(void)
{
	printf("====Print event info====\n");
	if (present_event_amount == 0)
	{
		Show_error_info(Error_info_reminder_empty);
		return;
	}
	char ch = Get_a_range('1', '4', "Enter your selection:", "1--ID  2--day  3--range  4--some parts");
	switch (ch)
	{
	case '1':Print_by_ID_process(); break;
	case '2':Print_by_day_process(); break;
	case '3':Print_by_range_process(); break;
	case '4':Print_by_parts_process(); break;
	}
}
