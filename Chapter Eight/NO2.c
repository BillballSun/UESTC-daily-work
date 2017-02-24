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
#include <stdlib.h> /*system abs(int)*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper*/
#include <math.h> /*sqrt fabs(double)*/
#include <string.h> /*mencpy*/
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*********************
 * #define Bool int  *
 * typedef int Bool; *
 *********************/
 #define Length_array (sizeof(digit_repeat_times)/sizeof(digit_repeat_times[0]))
 
 int main(void)
 {
	 typedef unsigned long long int digit_existance;
	 digit_existance digit_repeat_times[10]={0};
	 unsigned char ch;
	 bool checkpoint,repeat,nothing_point;
	 do
	 {
		 checkpoint=false;repeat=false;
		 printf("Enter a number:");
		 for (int i=0;i<=Length_array-1;i++)
			 digit_repeat_times[i]=0;
	     while (!checkpoint)
		 {
			 if ((ch=getchar())=='\n') checkpoint=true;
			 else if (ch<'9'&&ch>'0') digit_repeat_times[ch-'0']=digit_repeat_times[ch-'0']+1;
			 else
			 {
				 checkpoint=true;
				 repeat=true;
				 while ((ch=getchar())!='\n') continue;
				 printf("Error, digit not detected.\n");
				 printf("Please try again.\n");
			 }
		 }
	 }while(repeat);
	 printf("Digit:      ");
	 for (unsigned long long int i=0;i<=Length_array-1;i++)
		 printf("  %llu",i);
	 printf("\n");
	 printf("Occurrences:");
	 for (unsigned long long int i=0;i<=Length_array-1;i++)
		 printf("%3llu",digit_repeat_times[i]);
	 printf("\n");
	 system("pause");
	 return 0;
 }