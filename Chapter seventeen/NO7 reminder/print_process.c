#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "error_info.h"

#include "print_process.h"
#include "supporting_function.h"
#include "structure.h"
#include "info.h"

#include "external.h"

void Print_by_ID_process(void)
{
	unsigned int id = Get_a_id();
	Show_id_detailed_info(id);
}

void Print_by_day_process(void)
{
	unsigned char find_day = Get_a_day("Please enter a day:");
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
	if (day_count == 0) printf("No finding for day %d\n", (int)find_day);
	else
		for (unsigned int i = 1; i <= day_count; i++)
		{
			Print_small_line();
			Show_id_detailed_info(store_find_id[i - 1]);
		}
	free(store_find_id);
}

void Print_by_range_process(void)
{
	unsigned char start_day;
	unsigned char end_day;
	start_day = Get_a_day("Please enter the starting day:");
	end_day = Get_a_day("Please enter the ending day:");
	if (start_day>end_day)
	{
		printf("Reverse them automatically...\n");
		int temp = start_day;
		start_day = end_day;
		end_day = temp;
	}
	unsigned int *store_find_id;
	unsigned int day_count = 0;
	if (!(store_find_id = (unsigned int*)malloc(sizeof(unsigned int)*present_event_amount)))
	{
		Show_error_info(Error_info_allocation_failed);
		return;
	}
	for (unsigned int i = 1; i <= present_event_amount; i++)
		if (reminder[i - 1].day <= end_day&&reminder[i - 1].day >= start_day)
		{
		store_find_id[day_count] = i;
		day_count++;
		}
	if (day_count == 0) printf("no finding in the range from %d to %d.\n", (int)start_day, (int)end_day);
	else
		for (unsigned int i = 1; i <= day_count; i++)
		{
			Print_small_line();
			Show_id_detailed_info(store_find_id[i - 1]);
		}
	free(store_find_id);
}

void Print_by_parts_process(void)
{
	bool selected_day[31] = { false };
	unsigned int *store_find_id;
	unsigned int day_count = 0;
	if (!(store_find_id = (unsigned int*)malloc(sizeof(unsigned int)*present_event_amount)))
	{
		Show_error_info(Error_info_allocation_failed);
		return;
	}
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
		if (day_count == 0) printf("no finding in these parts.\n");
		else
			for (unsigned int i = 1; i <= day_count; i++)
			{
				Print_small_line();
				Show_id_detailed_info(store_find_id[i - 1]);
			}
	}
	free(store_find_id);
}
