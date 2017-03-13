/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/

#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h>

/* Macro function defination */
#define Clear_stdin() while(getc(stdin)!='\n')

/* Length defination */
#define One_line_capture_length 64

struct phone_number
{
	unsigned int country_code, main_code, sub_code;
};

void Safe_read_line(char *s, size_t len);
int Capture_one_line(FILE *fp, char *storage, size_t len);
int Interpret_data(char *string, struct phone_number *storage);
void Display_phone_number(struct phone_number *storage);

int main(int argc, char *argv[])
{
	fprintf(stdout, "Please input the file url:");
	char url[FILENAME_MAX];
	Safe_read_line(url, FILENAME_MAX-1);
	FILE *fp;
	if((fp=fopen(url, "r"))==NULL)
	{
		fprintf(stderr, "ERROR: file opened failed.\n");
		system("pause");
		return EXIT_FAILURE;
	}
	char data[One_line_capture_length+1];
	struct phone_number pn;
	while(Capture_one_line(fp, data, One_line_capture_length)==EXIT_SUCCESS)
		if(Interpret_data(data, &pn)==EXIT_SUCCESS)
			Display_phone_number(&pn);
	fclose(fp);
	system("pause");
	return EXIT_SUCCESS;
}

int Capture_one_line(FILE *fp, char *storage, size_t len)
{
	int ch;
	size_t count=0;
	do
	{
		ch=getc(fp);
		if(ch!=EOF&&ch!='\n'&&count<len)
			storage[count++];
	}while(ch!=EOF&&ch!='\n');
	storage[count]='\0';
	if(ch==EOF&&count==0) return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

int Interpret_data(char *string, struct phone_number *storage)
{
	unsigned int first, second, third;
	if(sscanf(string, "%*[^0123456789]%3u%*[^0123456789]%3u%*[^0123456789]%4u", &first, &second, &third)<3)
		return EXIT_FAILURE;
	storage->country_code=first;
	storage->main_code=second;
	storage->sub_code=third;
	return EXIT_SUCCESS;
}

void Display_phone_number(struct phone_number *storage)
{
	fprintf(stdout, "(%u) %u-%u\n", storage->country_code, storage->main_code, storage->sub_code);
}

void Safe_read_line(char *s, size_t len)
{
	char ch;
	while(((ch=getchar())!='\n')&&len>0)
	{
		*s++=ch;
		len--;
	}
	if(ch!='\n') Clear_stdin();
	*s='\0';
}
