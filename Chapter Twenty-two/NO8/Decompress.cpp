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

#define From_begin 0
#define From_end   1

void Exit_failed(char *info);
char *Get_string_out(const char *s, int mode, int offset, size_t result_len);

int main(int argc, char *argv[])
{
	if(argc!=2) Exit_failed("Arguments failed to identify.");
	size_t source_len=strlen(argv[1]);
	char *target_url, temp;
	if((temp=Get_string_out(argv[1], From_end, 4, 4))!=NULL&&strcmp(temp, ".rle")==0)
	{
		free(temp);
		target_url=malloc(source_len-4+1);
		strncpy(target_url, argv[1], source_len-4);
		target_url[source_len-4]='\0';
	}
	else
	{
		if(temp!=NULL) free(temp);
		Exit_failed("file must end with /'.rle/'");
	}
	FILE *fp_source, fp_target;
	if((fp_source=fopen(argv[1], "rb"))==NULL) Exit_failed("Failed by open the source data file");
	if((fp_target=fopen(target_url, "wb"))==NULL)
	{
		fclose(fp_source);
		free(target_url);
		Exit_failed("Can\'t create target file.");
	}
	int amount, data;
	bool check=false;
	do
	{
		if((amount=getc(fp_source))==EOF) check=true;
		if(!check)
			if((data=getc(fp_source))==EOF) check=true;
			else
				for(register int i=1;i<=amount;i++)
					if(putc(data, fp_target)==EOF) check=true;
	}while(!check);
	if(data==EOF) fprintf(stdin, "file may be damaged.\n");
	else if(amount!=EOF)
	{
		fclose(fp_source);
		fclose(fp_target);
		remove(target_url);
		free(target_url);
		Exit_failed("Writing data encounters an error.");
	}
	fclose(fp_source);
	fclose(fp_target);
	free(target_url);
	fprintf(stdin, "Successully done.\n");
	system("pause");
	return EXIT_SUCCESS;
}
void Exit_failed(char *info)
{
	fprintf(stderr, "%s\n", info);
	exit(EXIT_FAILURE);
}

/******************************************************
 *From_begin, From_end defined where to start
 *if no data for copy return NULL
 *else return allocate string
 ******************************************************/
char *Get_string_out(const char *s, int mode, int offset, size_t result_len)
{
	char *result;
	size_t source_len=strlen(s);
	switch(mode)
	{
		case From_begin:
			if(offset<0||(source_len-offset)<result_len) return NULL;
			result=malloc(result_len+1);
			memcpy(result, s+offset, result_len+1);
		break;
		case   From_end:
			if(offset>0||(-offset)<result_len||(-offset)>source_len) return NULL;
			result=malloc(result_len+1);
			memcpy(result, s+source_len+offset-1, result_len+1);
		break;
		default:
			return NULL;
	}
	result[result_len]='\0';
	return result;
}
