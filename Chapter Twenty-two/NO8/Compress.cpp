/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
********************************************************/
/* PR1.c (Chapter 13, page 210) */
#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h> /* scanf printf getchar putchar qsort */
/* fopen freopen setvbuf fflush rewind fseek ftell fgetpos fsetpos fclose tmpfile */
/* tmpnam L_tmpnam TMP_MAX _IOFBF _IOLBF _IONBF SEEK_SET SEEK_CUR SEEK_END fpos_t */
/* FILENAME_MAX stdin stdout stderr*/
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace size_t */
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* mencpy strcpy(n) strlen strcat(n) strcmp */
#include <time.h> /* time */
#include <stddef.h> /* offsetof */

void Exit_failed(char *info);

int main(int argc, char *argv[])
{
	if(argc!=2) Exit_failed("Arguments failed to identify.");
	FILE *fp_source, fp_target;
	if((fp_source=fopen(argv[1], "rb"))==NULL) Exit_failed("Failed by open the source data file");
	size_t source_len=strlen(argv[1]);
	char *target_url;
	if((target_url=malloc(source_len+5))==NULL) Exit_failed("Failed by allocate.");
	strcpy(target_url, argv[1]);
	strcat(target_url, ".rle");
	if((fp_target=fopen(target_url, "wb"))==NULL) 
	{
		fclose(fp_source);
		free(target_url);
		Exit_failed("Creating new file failed.");
	}
	int ch=getc(fp_source);
	if(ch==EOF)
	{
		fclose(fp_source);
		fclose(fp_target);
		remove(target_url);
		free(target_url);
		Exit_failed("Can't read any data from source file.");
	}
	free(target_url);
	int char_storge=ch;
	unsigned char amount=1;
	/*from 1 to 255, ignore the 0 storage for clear reading*/
	while((ch=getc(fp_source))!=EOF)
		if(ch==char_storge&&amount<UCHAR_MAX) amount++;
		else
		{
			putc(amount, fp_target);
			putc(char_storge, fp_target);
			char_storge=ch;
			amount=1;
		}
	putc(amount, fp_target);
	putc(char_storge, fp_target);
	fclose(fp_source);
	fclose(fp_target);
	fprintf(stdin, "Successully done.\n");
	system("pause");
	return EXIT_SUCCESS;
}

void Exit_failed(char *info)
{
	fprintf(stderr, "%s\n", info);
	exit(EXIT_FAILURE);
}
