/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
*********************************************************/
/* NO4.c (Chapter 6, page 85) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf*/
#include <stdlib.h> /*system abs*/
#include <stdbool.h> /*bool true false*/
/*******************
*#define Bool int *
*typedef int Bool;*
*******************/

int main(void)
{
	long long unsigned int data;
	int t;
	printf("Please input a positive number:");
	scanf("%llu", &data);
	printf("In revised it is ");
	if (data == 0);
	while (data>0)
	{
		t = (int)(data % 10);
		data = data / 10ull;
		printf("%-1.1d", t);
	}
	printf("\n");

	system("pause");
	return 0;
}