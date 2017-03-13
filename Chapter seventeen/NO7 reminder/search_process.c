#define _CRT_SECURE_NO_DEPRECATE
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "error_info.h"
#include "reminder_limit.h"

#include "search_process.h"
#include "supporting_function.h"
#include "structure.h"
#include "info.h"

#include "external.h"

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