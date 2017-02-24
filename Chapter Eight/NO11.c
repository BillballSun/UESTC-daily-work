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
#include <stdlib.h> /*system abs(int) srand rand*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper tolower*/
#include <math.h> /*sqrt fabs(double) trunc*/
#include <string.h> /*mencpy*/
#include <time.h> /*time*/
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*********************
 * #define Bool int  *
 * typedef int Bool; *
 *********************/
 
 int main(void)
 {
	 unsigned char a[15],ch;
	 unsigned long long int point;
	 printf("Enter your phone number: ");
	 for(point=0ull;((ch=getchar())!='\n')&&point<=14;point++)
		 a[point]=ch;
	 printf("In numberic form: ");
	 for(int i=0;i<point;i++)
		 switch(ch=toupper(a[i]))
		 {
			 case 'A':case 'B':case 'C':
			 printf("2");break;
			 case 'D':case 'E':case 'F':
			 printf("3");break;
			 case 'G':case 'H':case 'I':
			 printf("4");break;
			 case 'J':case 'K':case 'L':
			 printf("5");break;
			 case 'M':case 'N':case 'O':
			 printf("6");break;
			 case 'P':case 'Q':case 'R':case 'S':
			 printf("7");break;
			 case 'T':case 'U':case 'V':
			 printf("8");break;
			 case 'W':case 'X':case 'Y':case 'Z':
			 printf("9");break;
			 default:
			 printf("%c",ch);break;
		 }
	 printf("\n");
	 system("pause");
	 return 0;
 }