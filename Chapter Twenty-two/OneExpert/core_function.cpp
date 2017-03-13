#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h>
#include "core_function.h"
#include "database_ADT.h"
#include "structure_support.h"
#include "program_info.h"

void Generate_new_subject(void)
{
	if (Is_database_full())
	{
		Show_program_info(Info_databse_full);
		return;
	}
	char temp[Max_subject_name_length+1];
	printf("Please name the subject:");
	Safe_read_name(temp, Max_subject_name_length);
	Create_new_suject(temp);
	Show_program_info(Info_subject_added_successfully);
	Save_data();
}

void Learning_time(void)
{
	unsigned int ID_range = Get_present_ID_range();
	if (ID_range == 0)
	{
		Show_program_info(Info_database_empty);
		return;
	}
	for (unsigned int i = 1; i <= ID_range; i++)
	{
		Show_subject_info(i);
		Print_small_line();
	}
	unsigned int target_ID;
	bool check;
	do
	{
		check = false;
		printf("Please input your subject ID:");
		if (scanf("%u", &target_ID) == 1)
			if (target_ID >= 1 && target_ID <= ID_range)
				check = true;
		Get_rid_of_RestLine();
	} while (!check);
	printf("Now begins study, but what sad is we have no support timer.\n");
	printf("Press ente to end study:");
	if (getchar() != '\n') Get_rid_of_RestLine();
	unsigned long study_hours;
	do
	{
		check = false;
		printf("Please input your study hours:");
		if (scanf("%lu", &study_hours) == 1)
				check = true;
		Get_rid_of_RestLine();
	} while (!check);
	unsigned int study_minutes;
	do
	{
		check = false;
		printf("Please input your study minutes:");
		if (scanf("%u", &study_minutes) == 1)
			if (study_minutes<=59)
				check = true;
		Get_rid_of_RestLine();
	} while (!check);
	Print_small_line();
	Show_status_brand(target_ID);
	if(Add_subject_time(target_ID, study_hours, study_minutes)) Show_program_info(Info_expert);
	else
		Show_subject_still_need(target_ID);
	Save_data(); 
}

void Change_settings(void)
{
	Show_database_info();
	if (!Is_user_name_set())
	{
		Print_small_line();
		printf("Now only support change user\'s name.\n");
		#define User_name_digit_length 16
		char name_first[User_name_digit_length + 1];
		char name_last[User_name_digit_length + 1];
		printf("Please input user first name:");
		Safe_read_name(name_first, User_name_digit_length);
		printf("Please input user second name:");
		Safe_read_name(name_last, User_name_digit_length);
		Change_user_name(name_first, name_last);
		Save_data();
	}
}