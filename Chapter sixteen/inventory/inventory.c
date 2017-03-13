/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
**********************************************************/
/* inventory.c (Chapter 16, page 277) */
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <ctype.h>

#include "inventory_control.h"
#include "error_info.h"
#include "info.h"
#include "structure_function.h"
#include "inventory_process.h"

struct component
{
	signed short number;
	char name[Max_component_name_length+1];
	unsigned long present_amount;
} inventory[Max_component_amount];

int present_component_amount=0;

int main(int argc, char *argv[])
{
	bool exitpoint=false;
	char command;
	Show_start_info();
	do
	{
		command=Get_command_order();
		switch(command)
		{
			case 'a':
			Add_component_process();break;
			case 'd':
			Delete_component_process();break;
			case 'p':
			Print_component_process();break;
			case 's':
			Search_component_process();break;
			case 'e':
			exitpoint=true;break;
			default:
			Show_error_info(Error_info_illegal_entrance);
		}
		Print_divide_line();
	}while(!exitpoint);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}
