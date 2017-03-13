#include <stdio.h>
#include "program_info.h"
#include "structure_support.h"

static void Show_start_info(void);
static void Show_exit_info(void);

void Show_program_info(int code)
{
	switch (code)
	{
		case Info_missing_or_damaged_database:printf("Database is missing or damaged, program generated empty new one.\n");break;
		case Info_loading_successfully:printf("Loading data successfully.\n");break;
		case Info_start_introduction:Show_start_info(); break;
		case Info_exit_goodbye:Show_exit_info(); break;
		case Info_databse_full:printf("Database is full.\n");break;
		case Info_subject_added_successfully:printf("Subject added.\n");break;
		case Info_database_empty:printf("Database is empty.\n");break;
		case Info_expert:printf("Congratulations, becoming an expert.\n");break;
	}
}

static void Show_start_info(void)
{
	printf("----------------------OneExpert----------------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	Print_divide_line();
}

static void Show_exit_info(void)
{
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}