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
/*tmpnam L_tmpnam TMP_MAX _IOFBF _IOLBF _IONBF SEEK_SET SEEK_CUR SEEK_END fpos_t */
/*FILENAME_MAX stdin stdout stderr*/
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace size_t*/
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* mencpy strcpy(n) strlen strcat(n) strcmp */
#include <time.h> /* time */
#include <stddef.h> /*offsetof*/

#define Info_output_fp stdout
#define Url_input_fp stdin
#define Data_output_fp stdout
#define Max_bytes_output 999999

static char *safe_fgets(char *s, size_t n, FILE *stream);

int main(void)
{
	fprintf(Info_output_fp, "File bytes showing program\n");
	char locate_url[FILENAME_MAX+1];
	FILE *fp;
	do
	{
		fprintf(Info_output_fp, "Please input file url:");
		safe_fgets(locate_url, sizeof(locate_url), Url_input_fp);
		if((fp=fopen(locate_url, "rb"))==NULL) fprintf(Info_output_fp, "File failed by opening.\n");
	}while(fp==NULL);
	fprintf(Info_output_fp, "\n\n");
	fprintf(Data_output_fp, "Offset                Bytes              Characters\n");
	fprintf(Data_output_fp, "------   -----------------------------   ----------\n");
	int ch, n;
	unsigned int offset=0;
	bool exitpoint=false;
	char storage[10];
	do
	{
		n=1;
		while(n<=10&&((ch=getc(fp))!=EOF))
		{
			if(n==1) fprintf(Data_output_fp, "%6u   ", (offset++*10));
			fprintf(Data_output_fp, "%2.2x ", ch);
			storage[n-1]=ch;
			n++;
		}
		for(int i=n;i<=10;i++)
			fprintf(Data_output_fp, "   ");
		fprintf(Data_output_fp, "  ");
		for(int i=1;i<n;i++)
			if(isprint(storage[i-1])) putc(storage[i-1], Data_output_fp);
			else putc('.', Data_output_fp);
		putc('\n', Data_output_fp);
		if(n<=10||(offset*10)>Max_bytes_output)
			exitpoint=true;
		else if(offset%10==1&&offset!=1) system("pause");
	}while(!exitpoint);
	system("pause");
	fclose(fp);
	return EXIT_SUCCESS;
}

/******************************************************
 *Work as fgets but especially for stdin
 *so it will check EOF and ferror
 *I will clean the rest of input and WON'T save \n
 *Please consider carefully with your silly head
 ******************************************************/
char *safe_fgets(char *s, size_t n, FILE *stream)
{
	int ch;
	size_t i=0;
	while((ch=fgetc(stream))!='\n')
		if(i<=n-2) s[i++]=ch;
	s[i]='\0';
	if(i==0) return NULL;
	else return s;
}
