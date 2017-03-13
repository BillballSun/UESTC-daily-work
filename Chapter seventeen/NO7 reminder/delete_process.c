#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "error_info.h"
#include "reminder_limit.h"

#include "delete_process.h"
#include "supporting_function.h"
#include "structure.h"
#include "info.h"

#include "external.h"

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
	char ch = Get_a_range('1', '3', "Please enter your way:", "1--an exact day  2--range  3--some parts");

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