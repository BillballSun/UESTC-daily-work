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
#include <stdio.h> /* scanf printf getchar putchar */
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace */
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* mencpy strcpy(n) strlen strcat(n) strcmp */
#include <time.h> /* time */

typedef unsigned char Byte;


int main(void)
{
	unsigned int addr;
	int i,n;
	Byte *ptr,ch;
	
	system("chcp 437>nul.");
	printf("--------------Amazing CA inc program-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Both int and pointer has 32 to stored\n\n");
	
	printf("Address of main function: %8.8X\n", (unsigned int)main);
	printf("Address of the vibriable addr: %8.8X\n\n", (unsigned int)&addr);
	
	printf("Please enter a(hex) address:");
	scanf("%x", &addr);
	
	printf("Enter number of bytes to view:");
	scanf("%d", &n);
	
	printf("\n");
	printf("Address                Bytes             Characters\n");
	printf("--------  -----------------------------  ----------\n");
	
	ptr=(Byte *) addr;
	
	while(n>0)
	{
		printf("%8.8X  ",(unsigned int) ptr);
		for(i=0;i<10&&i<n;i++)
			printf("%2.2X ", *(ptr+i));
		for(;i<10;i++)
			printf("   ");
		printf(" ");
		for(i=0;i<10&&i<n;i++)
		{
			ch=*(ptr+i);
			if(!isprint(ch)) ch='.';
			printf("%c",ch);
		}
		printf("\n");
		n=n-10;
		ptr=ptr+10;
	}
	printf("\n");
	system("pause");
	return EXIT_SUCCESS;
}

