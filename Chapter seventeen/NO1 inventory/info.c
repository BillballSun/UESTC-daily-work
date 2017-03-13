#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#include "info.h"
#include "structure_function.h"
#include "error_info.h"
#include "inventory_control.h"

void Show_command_info(void)
{
	printf("a--Add  d--Delete  p--Print info  s--Search  e--Exit\n");
}

void Show_start_info(void)
{
	printf("------------Inventory management program--------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("Add/Delete some content\n");
	printf("Print the whole inventory info\n");
	printf("Search for exact item\n");
	Print_divide_line();
}

void Show_exit_info(void)
{
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}

void Show_error_info(int error_code)
{
	switch(error_code)
	{
		case Error_info_component_amount_overflow:
		printf("Error, inventory storage is full, due to max amount %lu.\n",(unsigned long)Max_component_amount);break;
		case Error_info_no_match_component:
		printf("Error,can\'t find such item in inventory.\n");break;
		case Error_info_illegal_entrance:
		printf("Error, unexpected entrance.\n");break;
		case Error_info_store_amount_downflow:
		printf("Error, storage number can\'t be negative.\n");break;
		case Error_info_allocation_failed:
		printf("Error, allocation failed.\n");
		case Error_info_initialization_failed:
		printf("ERROR, INITIALIZATION FAILED!\n");
	}
}
