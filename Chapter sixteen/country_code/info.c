#include <stdio.h>
#include "info.h"
#include "structure.h"

void Show_start_info(void)
{
	printf("--------------Amazing CA inc program-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("Program is used to search the phone number code for each country.\n");
	printf("You have two ways to use it.\n");
	printf("By code or by country name.\n");
	Print_divide_line();
}

void Show_exit_info(void)
{
	Print_divide_line();
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}
