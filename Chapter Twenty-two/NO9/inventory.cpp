/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
********************************************************/
/* PR1.c (Chapter 13, page 210) */
#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h> /* scanf printf getchar putchar qsort */
/* fopen freopen setvbuf fflush rewind fseek ftell fgetpos fsetpos fclose tmpfile */
/* tmpnam L_tmpnam TMP_MAX _IOFBF _IOLBF _IONBF SEEK_SET SEEK_CUR SEEK_END fpos_t */
/* FILENAME_MAX stdin stdout stderr*/
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace size_t */
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* memcpy strcpy(n) strlen strcat(n) strcmp */
#include <time.h> /* time */
#include <stddef.h> /* offsetof */

#include "core_function.h"


void Program_start(void);
void Main_function(void);
void Program_end(void);
void Show_program_intro(void);

int main(int argc, char *argv[])
{
	Program_start();
	Main_function();
	Program_end();
	return EXIT_SUCCESS;
}

void Program_start(void)
{
	//system("chcp 437>nul.");
}

void Show_program_intro(void)
{

}

void Main_function(void)
{
	char order;
	do
	{
		Show_program_intro();
		Show_present_procedure();
		order=Get_a_lower_range("(L/O)--load/output  C--create  S--search  J--sale\n"
								"P--print  A--add  D--delete  N--info\n"
								"B--combine  E--exit", "Please enter your selection", "locsjpadnbe");
		Divide_line();
		switch(order)
		{
			case 'l':Load_database_procedure();break;
			case 'o':Output_databse_procedure();break;
			case 'c':Creating_database_procedure();break;
			case 's':Search_database_procedure();break;
			case 'j':Sale_item_procedure();break;
			case 'p':Print_database_procedure();break;
			case 'a':Add_item_procedure(); break;
			case 'n':Change_info_procedure();break;
			case 'b':Combining_files_procedure();break;
			case 'd':Delete_item_procedure(); break;
		}
		if (order != 'e')
		{
			system("pause");
			system("cls");
		}
	}while(order!='e');
}

void Program_end(void)
{
	
}
