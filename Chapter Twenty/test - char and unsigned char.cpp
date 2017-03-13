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
#include <stdio.h> /* scanf printf getchar putchar */
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace */
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* mencpy strcpy(n) strlen strcat(n) strcmp */
#include <time.h> /* time */

int main(void)
{
	char ch=-128;
	while (ch <= 127)
	{
		printf("NO.%-4d character is (%c)\n", (int)ch, ch);
		if (ch != 127) ch++;
		else break;
	}
	unsigned char ch_t=128;
	while (ch_t <= 255)
	{
		printf("NO.%-4d character is (%c)\n", (int)ch_t, ch_t);
		isprint(ch);
		if (ch_t != 255) ch_t++;
		else break;
	}
	system("pause");
	return EXIT_SUCCESS;
}

