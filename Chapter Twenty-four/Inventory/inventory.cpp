/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/
/* NO1.cpp (Chapter 24, page unkown) */

#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>  /* SIGABRT SIGFPE SIGILL SIGINT SIGSEGV SIGTERM signal SIG_DEF SIG_IGN raise */
#include <errno.h>

#include "inventory_control.h"
#include "core_function.h"

static void Show_start_info(void);
static void Show_end_info(void);
static void Signal_call(int code);

int main(int argc, char *argv[])
{
	#if !Signal_all_to_default
	signal(SIGABRT, SIGABRT_control?Signal_call:SIG_IGN);
	signal(SIGFPE, SIGFPE_control?Signal_call:SIG_IGN);
	signal(SIGILL, SIGILL_control?Signal_call:SIG_IGN);
	signal(SIGSEGV, SIGSEGV_control?Signal_call:SIG_IGN);
	signal(SIGINT, SIGINT_control?Signal_call:SIG_IGN);
	signal(SIGTERM, SIGTERM_control?Signal_call:SIG_IGN);
	#endif
	Show_start_info();
	Core_process();
	Show_end_info();
	system("pause");
	return EXIT_SUCCESS;
}

static void Show_start_info(void)
{
	printf("--------------Amazing CA inc program-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("It is a new made inventory program.\n");
	printf("With ADT database using single line linked structure. ( ADT, abstract data type )\n");
	printf("And you can save the database by using the least space at C, byte, uncomposed level.\n");
	printf("------------------------------------------------------\n");
}

static void Show_end_info(void)
{
	printf("------------------------------------------------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}


static void Signal_call(int code)
{
	switch(code)
	{
		case SIGABRT:
			fprintf(stderr, "Abort called by function " __function__ ".\n");
			abort();
			break;
		case SIGFPE:
			fprintf(stderr, "Float point exception.\n");
			exit();
			break;
		case SIGILL:
			fprintf(stderr, "Signal illegal instruction called.\n");
			exit();
			break;
		case SIGSEGV:
			fprintf(stderr, "Signal segmentation violation called.\n");
			exit();
			break;
		case SIGTERM:
			fprintf(stderr, "Signal terminate called.\n");
			exit();
			break;
		case SIGINT:
			fprintf(stderr, "Signal int called.\n");
			system("pause");
			break;
		default:
	}
	signal(code, Signal_call);
}
