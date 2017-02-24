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
	 typedef unsigned char name_array_content_type;
	 name_array_content_type name[21];
	 unsigned char ch;
	 unsigned long long int point;
	 int find;
	 printf("Enter a first and last name: ");
	 for(point=0ull;((ch=getchar())!='\n')&&point<=20;point++)
		 name[point]=ch;
	 find=-1;
	 for(int i=0;(i<=(point-1))&&find<0;i++)
		 if (name[i]==' ') find=i;
	 printf("You entered the name: ");
	 for(int i=find+1;i<=(point-1);i++)
		 printf("%c",name[i]);
	 printf(", %c.\n",toupper(name[0]));
	 system("pause");
	 return 0;
 }