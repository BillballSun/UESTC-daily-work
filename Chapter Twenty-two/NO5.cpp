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
/*fopen freopen setvbuf fflush rewind fseek ftell fgetpos fsetpos fclose tmpfile*/
/*tmpnam L_tmpnam TMP_MAX _IOFBF _IOLBF _IONBF SEEK_SET SEEK_CUR SEEK_END fpos_t stdin stdout stderr*/
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace size_t*/
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* mencpy strcpy(n) strlen strcat(n) strcmp */
#include <time.h> /* time */
#include <stddef.h> /*offsetof*/

int main(int argc, char *argv[])
{
	if(argc!=4) {fprintf(stderr, "arguments error.\n");exit(EXIT_FAILURE);}
	char xor_code=*argv[3];
	FILE *fp_source;
	if((fp_source=fopen(argv[1],"rb"))==NULL)
	{
		fprintf(stderr, "source file %s can\'t be opened.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	FILE *fp_target;
	if((fp_target=fopen(argv[2],"wb"))==NULL)
	{
		fclose(fp_source);
		fprintf(stderr, "target file %s can\'t be created.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	int ch,ch2;
	do
	{
		ch=getc(fp_source);
		putc(ch^xor_code, fp_target);
	}while(ch!=EOF);
	if(ferror(fp_source)) fprintf(stderr, "\nsource file %s occur an error, process can\'t complete.\n", argv[1]);
	else if(ferror(fp_target)) fprintf(stderr, "\ntarget file %s occur an error, process can\'t complete.\n", argv[2]);
	else fprintf(stdout, "process completed.\n");
	fclose(fp_source);
	fclose(fp_target);
	system("pause");
	return EXIT_SUCCESS;
}
