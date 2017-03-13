/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
*********************************************************/
/* NO8.c (Chapter 6, page 86) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf getchar putchar*/
#include <stdlib.h> /*system abs*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper*/
#include <math.h> /*sqrt*/
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*******************
*#define Bool int *
*typedef int Bool;*
*******************/

int main(void)
{
	int m,d,y;
	printf("Enter a date (mm/dd/yyyy):");
	scanf("%d/%d/%d",&m,&d,&y);
	printf("\nYou entered the date %4.4d%2.2d%2.2d",y,m,d);
	system("pause");
	return 0;
}