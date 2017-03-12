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

#include "queueADT.h"

#define Initialized_queue_length 64

int main(int argc, const char *argv[])
{
	char ch,compare_ch;
	int check = 0;

	Queue q=Create_queue(sizeof(char), Initialized_queue_length);
	if (q == NULL) return (EXIT_FAILURE);

	printf("Please enter some pragmas:");
	while (check == 0 && ((ch = getchar()) != '\n'))
		if (ch == '(' || ch == '{' || ch == '<' || ch == '[')
		{
			if (Is_queue_full(q)) 
				if(!Enlarge_queue(q, Initialized_queue_length)) check=1;
			    else Insert_back_queue(q, &ch);
			else Insert_back_queue(q, &ch);
		}
		else if (ch == ')' || ch == '}' || ch == '>' || ch == ']')
		{
			if (Is_queue_empty(q)) check = 2;
			else
			{
				Pop_from_the_back(q, &compare_ch);
				switch (ch)
				{
					case ')':if (compare_ch != '(') check = 2; break;
					case '}':if (compare_ch != '{') check = 2; break;
					case '>':if (compare_ch != '<') check = 2; break;
					case ']':if (compare_ch != '[') check = 2; break;
				}
			}
		}
		else check = 2;
	if (ch != '\n') while ((ch = getchar()) != '\n') continue;

	switch (check)
	{
		case 0:printf("Match successfully done.\n"); break;
		case 1:printf("Info, allocation failed, due to too much pragmas.\n"); break;
		case 2:printf("Match wrong.\n"); break;
	}
	system("pause");
	return EXIT_SUCCESS;
}
















































