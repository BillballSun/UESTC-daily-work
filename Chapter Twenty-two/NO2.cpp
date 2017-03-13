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
#include <stdio.h> /* scanf printf getchar putchar qsort fopen freopen setvbuf fflush rewind fseek ftell fgetpos fsetpos fclose tmpfile tmpnam*/
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace */
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* mencpy strcpy(n) strlen strcat(n) strcmp */
#include <time.h> /* time */
#include <stddef.h> /*offsetof*/

int main(int argc, char *argv[])
{
	if(argc!=2){fprintf(stderr, "arguments missing.\n");exit(EXIT_FAILURE);}
	FILE *fp;
	if((fp=fopen(argv[1], "r"))==NULL){fprintf(stderr, "can\'t open file.\n");exit(EXIT_FAILURE);}
	int ch;
	while((ch=getc(fp))!=EOF) putc(toupper(ch),stdout);
	system("pause");
	return EXIT_SUCCESS;
}
