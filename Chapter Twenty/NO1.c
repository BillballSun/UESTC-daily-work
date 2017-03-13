/*********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
**********************************************************/
/* PR1.c (Chapter 13, page 210) */
#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h> /* scanf printf getchar putchar qsort*/
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace */
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* mencpy strcpy(n) strlen strcat(n) strcmp */
#include <time.h> /* time */

union float_view
{
	struct
	{
		unsigned int little_digits:23;
		unsigned int upper_digits:8;
		unsigned int fuhao:1;
	}float_digits;
	float float_all;
}

int main(int argc, char *argv[])
{
	union float_view f;
	f.float_digits.fuhao=1;
	f.float_digits.upper_digits=128;
	f.float_digits.little_digits=0;
	printf("%f\n",f.float_all);
	system("pause");
	return EXIT_SUCCESS;
}
