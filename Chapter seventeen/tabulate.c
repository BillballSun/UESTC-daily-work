/*********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
**********************************************************/
/* tabulate.c (Chapter 17, page 317) */
#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h> /* scanf printf getchar putchar */
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace */
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* mencpy strcpy(n) strlen strcat(n) strcmp */
#include <time.h> /* time */
//#include <iostream> /* C++ input and output */
//using namespace std; /* C++ cout cin */

void Show_start_info(void);
void Show_exit_info(void);
void Print_divide_line(void);
void Print_small_line(void);
void tabulate(double(*f)(double), double begin, double end, double incr);

int main(int argc, char *argv[])
{
	double final, increment, initial;
	Show_start_info();
	printf("Enter initial number:");
	scanf("%lf",&initial);
	printf("Enter final number:");
	scanf("%lf",&final);
	printf("Enter increment number:");
	scanf("%lf",&increment);
	Print_small_line();
	printf("      x        sin(x)\n");
	printf("   -------   --------\n");
	tabulate(sin, initial, final, increment);
	Print_small_line();
	printf("      x        cos(x)\n");
	printf("   -------   --------\n");
	tabulate(cos, initial, final, increment);
	Print_small_line();
	printf("      x        tan(x)\n");
	printf("   -------   --------\n");
	tabulate(tan, initial, final, increment);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

void tabulate(double (*f)(double), double begin, double end, double incr)
{
	for(double i=begin;i<=end;i=i+incr)
		printf("   %7.2f   %8.2f\n",i,(*f)(i));
}

void Show_start_info(void)
{
	printf("--------------Amazing CA inc program-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("Caculating a sin cos tan table\n");
	Print_divide_line();
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}                              

void Print_small_line(void)
{
	printf("-----------------------\n");
}

void Show_exit_info(void)
{
	Print_divide_line();
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}
