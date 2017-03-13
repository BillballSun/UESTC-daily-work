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
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define USHRT_MAX     0xffff

/* Macro function defination */
#define Clear_stdin() while(getc(stdin)!='\n')

/* main switch code */
#define Encrypt 'e'
#define Decrypt 'd'

/* Translate_string function mode */
#define Clock_wise 1
#define Anti_clock_wise -1

/* Encrypt, Decrypt process return value */
#define Critical_error_file_access_denied -1
#define Critical_error_new_file_creation_failed -2
#define Critical_error_file_writing_failed -3
#define Interesting_failed_by_allocate_target_string_space 1
#define File_not_end_with_enc 2

/* language change */
#define LOOP for(;;)

/* Program control value */
#define Buffer_block_size 512 /* 1-SIZE_MAX */

char Get_a_lower_range_from_stdin(char *range);
int Encrypt_procedure(void);
int Decrypt_procedure(void);
FILE *Open_file(void);
void Safe_read_line(char *s, size_t len);
void Translate_string(char *string, unsigned short offset, int mode, size_t count);

int main(int argc, char *argv[])
{
	fprintf(stdout, "Encrypt or Decrypt file(E or D)---");
	char order=Get_a_lower_range_from_stdin("ed");
	int result_code;
	switch(order)
	{
		case Encrypt:result_code=Encrypt_procedure();break;
		case Decrypt:result_code=Decrypt_procedure();break;
	}
	if(result_code==0) return EXIT_SUCCESS;
	else return EXIT_FAILURE;
}

int Encrypt_procedure(void)
{
	fprintf(stdout, "Please enter the file url:");
	char url[FILENAME_MAX];
	Safe_read_line(url, FILENAME_MAX-1);
	FILE *fp;
	if((fp=fopen(url, "rb"))==NULL) return Critical_error_file_access_denied;
	unsigned short encrypt_code;
	int check;
	do
	{
		fprintf(stdout, "Please enter the encrypt code(1-25):");
		check=fscanf(stdin, "%hu", &encrypt_code);
		Clear_stdin();
	}while(check!=1&&(encrypt_code<1||encrypt_code>25));
	char *target_url;
	if((target_url=(char *)malloc(strlen(url)+5))==NULL)
	{
		fclose(fp);
		return Interesting_failed_by_allocate_target_string_space;
	}
	strcpy(target_url, url);
	strcat(target_url, ".enc");
	FILE *target_fp;
	if((target_fp=fopen(target_url, "wb"))==NULL)
	{
		fclose(fp);
		free(target_url);
		return Critical_error_new_file_creation_failed;
	}
	free(target_url);
	char temp[Buffer_block_size];
	size_t count;
	LOOP
	{
		count=0;
		/*
		while(count<Buffer_block_size&&((ch=getc(fp))!=EOF))
			temp[count++]=ch;
		*/
		count=fread(temp, sizeof(unsigned char), Buffer_block_size, fp);
		if(count==0) break;
		Translate_string(temp, encrypt_code, Clock_wise, count);
		if(fwrite(temp, sizeof(unsigned char), count, target_fp)<count)
		{
			fclose(fp);
			fclose(target_fp);
			return Critical_error_file_writing_failed;
		}
	}
	fclose(fp);
	fclose(target_fp);
	return EXIT_SUCCESS;
}

void Translate_string(char *string, unsigned short offset, int mode, size_t count)
{
	int offset_value, ch;
	switch(mode)
	{
		case Clock_wise:offset_value=offset;break;
		case Anti_clock_wise:offset_value=offset*(-1);break;
	}
	while(count-->0)
	{
		ch=((int)(unsigned char)*string+offset_value+(USHRT_MAX+1))%(USHRT_MAX+1);
		*string++=ch;
	}
}

int Decrypt_procedure(void)
{
	fprintf(stdout, "Please enter the encrypted file url:");
	char url[FILENAME_MAX];
	Safe_read_line(url, FILENAME_MAX-1);
	if(strlen(url)<5||strcmp(url+strlen(url)-4, ".enc")!=0) return File_not_end_with_enc;
	FILE *fp;
	if((fp=fopen(url, "rb"))==NULL) return Critical_error_file_access_denied;
	unsigned short encrypt_code;
	int check;
	do
	{
		fprintf(stdout, "Please enter the code used to encrypt this file(1-25):");
		check=fscanf(stdin, "%hu", &encrypt_code);
		Clear_stdin();
	}while(check!=1);
	char *target_url;
	if((target_url=(char *)malloc(strlen(url)-3))==NULL)
	{
		fclose(fp);
		return Interesting_failed_by_allocate_target_string_space;
	}
	strncpy(target_url, url, strlen(url)-4);
	target_url[strlen(url)-4]='\0';
	FILE *target_fp;
	if((target_fp=fopen(target_url, "wb"))==NULL)
	{
		fclose(fp);
		free(target_url);
		return Critical_error_new_file_creation_failed;
	}
	free(target_url);
	char temp[Buffer_block_size+1];
	size_t count;
	int ch;
	LOOP
	{
		count=0;
		/*
		while(count<Buffer_block_size&&((ch=getc(fp))!=EOF))
			temp[count++]=ch;
		*/
		count=fread(temp, sizeof(unsigned char), Buffer_block_size, fp);
		if(count==0) break;
		temp[count]='\0';
		Translate_string(temp, encrypt_code, Anti_clock_wise, count);
		if(fwrite(temp, sizeof(unsigned char), count, target_fp)<count)
		{
			fclose(fp);
			fclose(target_fp);
			return Critical_error_file_writing_failed;
		}
	}
	fclose(fp);
	fclose(target_fp);
	return EXIT_SUCCESS;
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

char Get_a_lower_range_from_stdin(char *range)
{
	char ch, *temp;
	bool check=false;
	do
	{
		ch=tolower(getc(stdin));
		if(ch!='\n') Clear_stdin();
		for(temp=range; *temp; temp++)
			if(tolower(*temp)==ch) check=true;
	}while(!check);
	return ch;
}
