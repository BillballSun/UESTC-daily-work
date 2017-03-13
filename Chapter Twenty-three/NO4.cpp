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

#define Clear_stdin() while(getc(stdin)!='\n')
#define Max_input_length 10086
#define Initialized_size 64 /*No less than 1*/

int main(int argc, char *argv[])
{
	fprintf(stdout, "Please input a sequnce of words seperated by blanck:");
	char input[Max_input_length+1];
	fgets(input, Max_input_length+1, stdin);
	if(input[strlen(input)]!='\0') Clear_stdin();
	struct database
	{
		char **point;
		size_t present_amount, stack_size;
	}saving;
	if((saving.point=(char **)malloc(sizeof(char *)*Initialized_size))==NULL) Allocation_failed();
	saving.present_amount=0;
	saving.stack_size=Initialized_size;
	char *temp;
	if((temp=strtok(input, "\t"))!=NULL)
	{
		saving.point[saving.present_amount++]=temp;
		while((temp=strtok(NULL, "\t"))!=NULL)
		{
			if(saving.present_amount==saving.stack_size)
			{
				char **t;
				if((t=(char **)malloc(sizeof(char *)*(stack_size+Initialized_size)))==NULL)
				{
					free(saving.point);
					Allocation_failed();
				}
				saving.point=t;
				stack_size+=Initialized_size;
			}
			saving.point[saving.present_amount++]=temp;
		}
	}
	if(saving.present_amount==0)
		fprintf(stdout, "INFO: nothing detected.\n");
	else
		for(size_t i=present_amount;i>=1;i--)
			fprintf(stdout, "%s ", saving.point[i-1]);
	system("pause");
	return EXIT_SUCCESS;
}

void Allocation_failed(void)
{
	fprintf(stderr, "ERROR:allocation failed.\n");
	system("pause");
	exit(EXIT_FAILURE);
}
