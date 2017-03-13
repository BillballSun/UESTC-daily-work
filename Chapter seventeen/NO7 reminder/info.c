#include <stdio.h>

#include "error_info.h"
#include "reminder_limit.h"

#include "info.h"
#include "structure.h"

void Show_start_info(void)
{
	printf("--------------Amazing CA inc program-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("A reminder to remind youu some events.\n");
	Print_divide_line();
}

void Show_exit_info(void)
{
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}

void Show_error_info(int code)
{
	switch (code)
	{
	case Error_info_allocation_failed:
		printf("\nWarning, allocation failed.\n\n"); break;
	case Error_info_reminder_full:
		printf("\nWarning, reminder is full, due to maximun is %u.\n\n", (unsigned int)Max_message_length); break;
	case Error_info_reminder_empty:
		printf("\nWarning, reminder is empty.\n\n"); break;
	}
}