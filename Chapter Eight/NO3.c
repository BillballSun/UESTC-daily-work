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
	 long long int digit;
	 unsigned short number;
	 unsigned long long int digit_no;
	 unsigned char ch;
	 bool repeat,nothing_point;
	 digit_no=1;
	 printf("Caculate repeated digits,please enter zero or negative number to terminate.\n");
	 do
	 {
		 repeat=true;digit=0;
		 printf("Enter the %llu",digit_no);
		 switch (digit_no%10)
		 {
		     case 1:printf("st");break;
			 case 2:printf("nd");break;
			 case 3:printf("rd");break;
			 default:printf("th");break;
		 }
		 printf(" number:");
		 scanf("%d",&digit);
		 if (digit<=0) {printf("Comes to a terminal.\n");repeat=false;}
		 else while (digit>0)
		    	 {
					 number=digit%10;
					 digit=digit/10;
					 digit_repeat_times[number]=digit_repeat_times[number]+1;
		     	 }
		 while((ch=getchar())!='\n') continue;
		 digit_no=digit_no+1;
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