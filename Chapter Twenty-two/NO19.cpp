/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/* Macro procedure replacement */
#define Clear_stdin while(getc(stdin)!='\n')
#define Windows_style 'w'
#define Macintosh_style 'm'
#deifne Enter_end '\x0D'
#define Line_end '\x0A'

void Open_a_file(FILE **fp, FILE **target_fp, char mode);
void Safe_read_line(char *storage, size_t len);
char Get_a_lower_range_from_stdin(char *range);
void Translate_to_windows(FILE *fp, FILE *target_fp);
void Translate_to_macintosh(FILE *fp, FILE *target_fp);

int main(int argc, char *argv[])
{
	char order=Get_a_lower_range_from_stdin("Translate to Windows or Macintosh (W or M)---", "wm");
	FILE *fp, target_fp;
	Open_a_file(&fp, &target_fp, order);
	switch(ch)
	{
		case Windows_style:Translate_to_windows(fp, target_fp);
		case Macintosh_style:Translate_to_macintosh(fp, target_fp);
	}
	fclose(fp);
	fclose(target_fp);
	return EXIT_SUCCESS;
}

void Translate_to_windows(FILE *fp, FILE *target_fp)
{
	int ch;
	while((ch=getc(fp))!=EOF)
		if(ch==Line_end)
		{
			/* fputs("\x0D" "\x0A", target_fp) */
			putc(Enter_end, target_fp);
			putc(Line_end, target_fp);
		}
		else putc(ch, target_fp);
}

void Translate_to_macintosh(FILE *fp, FILE *target_fp)
{
	int ch, temp;
	while((ch=getc(fp))!=EOF)
		if(ch==Enter_end)
			if((temp=getc(fp))==Line_end)
				putc(Line_end, target_fp);
			else
			{
				putc(ch, target_fp);
				if(temp!=EOF) putc(temp, target_fp);
			}
		else putc(ch, target_fp);
}

void Open_a_file(FILE **fp, FILE *target_fp, char mode)
{
	char url[FILENAME_MAX];
	FILE *open, target;
	do
	{
		fprintf(stdout, "Please enter the file url:");
		Safe_read_line(url, FILENAME_MAX-1);
		if((open=fopen(url, "rb"))==NULL) fprintf(stdout, "INFO: file access denied.\n");
	}while(open==NULL);
	char *target_url=(char *)malloc(strlen(url)+12);
	if(target_url==NULL)
	{
		fprintf(stdout, "ERROR: allocation failed.\n");
		system("pause");
		fclose(open);
		exit(EXIT_FAILURE);
	}
	strcpy(target_url, url);
	switch(mode)
	{
		case Windows_style:strcat(target_url, ".Mac_to_Win");break;
		case Macintosh_style:strcat(target_url, ".Win_to_Mac");break;
	}
	if((target=fopen(target_url, "wb"))==NULL)
	{
		fprintf(stdout, "ERROR: new file creation failed.\n");
		system("pause");
		free(target_url);
		fclose(open);
		exit(EXIT_FAILURE);
	}
	free(target_url);
	*fp=open;
	*target_fp=target;
}

void Safe_read_line(char *storage, size_t len)
{
	char ch;
	size_t count=0;
	while((ch=getc(stdin))!='\n')
		if(count<len)
			storage[count++]=ch;
	storage[count]='\0';
}

char Get_a_lower_range_from_stdin(char *message, char *range)
{
	char ch;
	bool check=false;
	char *temp;
	do
	{
		fprintf(stdout, "%s", message);
		ch=tolower(getc(stdin));
		for(temp=range, *temp, temp++)
			if(tolower(*temp)==ch) check=true;
	}while(!check);
	return ch;
}
