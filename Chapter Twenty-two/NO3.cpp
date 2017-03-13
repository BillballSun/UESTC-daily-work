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
	if(argc<=1) {fprintf(stderr, "failed to detect file from command.\n");exit(EXIT_FAILURE);}
	FILE *fp;
	int ch;
	bool check=false;
	for(int i=1;i<argc;i++)
		if((fp=fopen(argv[i],"r"))!=NULL)
		{
			while((ch=getc(fp))!=EOF) putc(ch,stdout);
			check=true;
			fclose(fp);
		}
	if(!check) fprintf(stderr, "WARNING: nothing could be opened.\n");
	system("pause");
	return EXIT_SUCCESS;
}
