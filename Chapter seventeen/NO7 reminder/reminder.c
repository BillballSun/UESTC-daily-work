/*********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
**********************************************************/
/* reminder.c (Chapter 17, page unknown) */
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 
#include <stdlib.h> 

#include "reminder_limit.h"

#include "info.h"
#include "main_program.h"

struct event
{
	unsigned char day; //0-255
	char *message;
}reminder[Max_reminder_event];
//ID range from 1 to present_event_amount

unsigned int present_event_amount;

int main(int argc, char *argv[])
{
	Show_start_info();
	present_event_amount = 0u;
	Main_program();
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}
