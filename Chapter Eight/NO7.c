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

 int main(void)
 {
	 typedef unsigned short int StudentScore_array_ContentType;
	 unsigned short int cycle_control_1,cycle_control_2;
	 StudentScore_array_ContentType score[5][5]={0};
	 unsigned long long int total;
	 for(cycle_control_1=1;cycle_control_1<=5;cycle_control_1++)
	 {
		 printf("Enter row %hu:",cycle_control_1);
		 for(cycle_control_2=1;cycle_control_2<=5;cycle_control_2++)
			 scanf("%hu",&score[cycle_control_1-1][cycle_control_2-1]);
	 }
	 printf("Row totals:");
	 for(cycle_control_1=1;cycle_control_1<=5;cycle_control_1++)
	 {
		 total=0;
		 for(cycle_control_2=1;cycle_control_2<=5;cycle_control_2++)
			 total=total+score[cycle_control_1-1][cycle_control_2-1];
		 printf("%4llu",total);
     }
	 printf("\n");
	 printf("Column totals:");
	 for(cycle_control_1=1;cycle_control_1<=5;cycle_control_1++)
	 {
		 total=0;
		 for(cycle_control_2=1;cycle_control_2<=5;cycle_control_2++)
			 total=total+score[cycle_control_2-1][cycle_control_1-1];
		 printf("%4llu",total);
     }
	 printf("\n");
	 system("pause");
	 return 0;
 }