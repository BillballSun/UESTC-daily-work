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

int main(int argc, char *argv[])
{
	if(argc!=3) {fprintf(stdout, "Argumets missing.\n");exit(EXIT_FAILURE);}
	FILE *fp_source;
	if((fp_source=fopen(argv[1],"rb"))==NULL)
	{
		fprintf(stdout, "File %s can\'t be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	FILE *fp_target;
	if((fp_target==fopen(argv[2],"wb")==NULL)
	{
		fprintf(stdout, "File %s can\'t be created\n", argv[2]);
		fclose(fp_source);
		exit(EXIT_FAILURE);
	}
	int ch=getc(fp_source);
	if(ch==EOF)
	{
		fprintf(stderr, "Info: Can not find any data from the file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
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
	system("pause");
	return EXIT_SUCCESS;
}
