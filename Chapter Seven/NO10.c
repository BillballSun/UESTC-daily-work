/********************************************************
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
/*******************
 *#define Bool int *
 *typedef int Bool;*
 *******************/

int main(void)
{
	int total=0,yuan=0;
	unsigned char ch;
	printf("Enter a sentense:");
	while((ch=getchar(),ch=toupper(ch))!='\n')
		switch(ch)
		{
			case 'A':case 'E':case 'I':case 'O':case 'U':
			yuan=yuan+1;/*No break*/
			default:total=total+1;break;
		}
	printf("Your sentence is %d words long.\nAnd it contains %d vowels.\n",total,yuan);
	system("pause");
	return 0;
}