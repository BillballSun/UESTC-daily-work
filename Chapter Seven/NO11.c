/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
/* NO10.c (Chapter 7, page 111) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf getchar putchar*/
#include <stdlib.h> /*system abs*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper*/
#include <math.h> /*sqrt*/
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*********************
 * #define Bool int  *
 * typedef int Bool; *
 *********************/

int main(void)
{
	bool checkpoint;
	unsigned char first_name,ch;
	printf("Enter a first and last name:");
	first_name=getchar();
	while((ch=getchar())!=' ') continue;
    while((ch=getchar())==' ') continue;
	checkpoint=true;
    do
	{
		putchar(ch);
		if ((ch=getchar())=='\n') checkpoint=false;
	}while(checkpoint);
	putchar(',');putchar(' ');putchar(first_name);putchar('\n');
	system("pause");
	return 0;
}