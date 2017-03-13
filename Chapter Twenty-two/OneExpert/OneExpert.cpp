/*********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
**********************************************************/
#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h> /* scanf printf getchar putchar qsort*/
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace */
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* mencpy strcpy(n) strlen strcat(n) strcmp */
#include <time.h> /* time */
#include <stddef.h> /*offsetof*/

#include "database_ADT.h"
#include "structure_support.h"
#include "program_info.h"
#include "core_function.h"


int main(int argc, char *argv[])
{
	Show_program_info(Info_start_introduction);
	if (Is_data_exist() != 1) Show_program_info(Info_missing_or_damaged_database);
	else Show_program_info(Info_loading_successfully);
	char user_order;
	do
	{
		user_order = Get_a_upper_range("c--Create new subject, l--Learning, s--Settings, e--Exit", "Please input order", "clse");
		if(user_order!='E') Print_small_line();
		switch (user_order)
		{
			case 'C':Generate_new_subject(); break;
			case 'L':Learning_time(); break;
			case 'S':Change_settings(); break;
			case 'E':Save_data(); break;
		}
		Print_divide_line();
	} while (user_order != 'E');
	Show_program_info(Info_exit_goodbye);
	system("pause");
	return EXIT_SUCCESS;
}
















































