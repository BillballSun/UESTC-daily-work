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

int All_character_process(FILE *fp);
int Word_process(FILE *fp);
int Line_process(FILE *fp);
int Get_a_lower_range(char *main_message, char *read_message, char *range);

int main(int argc, char *argv[])
{
	if(argc!=2){fprintf(stderr, "arguments missing.\n");exit(EXIT_FAILURE);}
	FILE *fp;
	if((fp=fopen(argv[1],"r"))==NULL){fprintf(stderr, "can\'t open file %s.\n",argv[1]);exit(EXIT_FAILURE);}
	int order=Get_a_lower_range("a--all characters   w--word amount   l--line amount","Please input your order", "awl");
	switch(order)
	{
		case 'a':All_character_process(fp);break;
		case 'w':Word_process(fp);break;
		case 'l':Line_process(fp);break;
	}
	fclose(fp);
	system("pause");
	return EXIT_SUCCESS;
}

int All_character_process(FILE *fp)
{
	unsigned long long count=0;
	int ch;
	clearerr(fp);
	while((ch=getc(fp))!=EOF) if(isalpha(ch)) count++;
	if(ferror(fp)) return EOF;
	fprintf(stdout, "File has %llu characters.\n", count);
	return 0;
}

int Word_process(FILE *fp)
{
	unsigned long long count=0;
	bool process_one=false;
	int ch;
	clearerr(fp);
	do
	{
		ch=getc(fp);
		if(isalpha(ch)) process_one=true;
		else if(process_one)
		{
			process_one=false;
			count++;
		}
	}while(ch!=EOF);
	if(ferror(fp)) return EOF;
	fprintf(stdout, "File has %llu characters.\n", count);
	return 0;
}

int Line_process(FILE *fp)
{
	unsigned long long count=0;
	bool process_one=false;
	int ch;
	clearerr(fp);
	do
	{
		if(ch=='\n')
		{
			process_one=false;
			count++;
		}
		else if(ch==EOF)
		{
			if(process_one) count++;
		}
		else
			process_one=true;
	}while(ch!=EOF);
	if(ferror(fp)) return EOF;
	fprintf(stdout, "File has %llu characters.\n", count);
	return 0;
}

int Get_a_lower_range(char *main_message, char *read_message, char *range)
{
	fprintf(stdout, "%s\n",main_message);
	int ch;
	bool check;
	char *temp;
	do
	{
		fprintf(stdout, "%s:",read_message);
		ch=tolower(getc(stdin));
		if(ch==EOF) return EOF;
		if(ch!='\n') Clear_stdin();
		temp=range;
		check=false;
		while(*temp++) if(tolower(temp)==ch) check=true;
	}while(!check);
	return ch;
}

void Clear_stdin(void)
{
	while(getc(stdin)!='\n') continue;
}
