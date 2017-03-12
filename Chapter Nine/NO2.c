/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
/* NO1.c (Chapter 9, page 151) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf getchar putchar*/
#include <stdlib.h> /*system abs(int) srand rand*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper tolower isalpha isupper islower*/
#include <math.h> /*sqrt fabs(double) trunc*/
#include <string.h> /*mencpy*/
#include <time.h> /*time*/
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*********************
 * #define Bool int  *
 * typedef int Bool; *
 *********************/
/********************************************************
 *PC-Lint check                                         *
 *C:/Lint/Lint-nt -i"C:/Lint" -u cmd_std.lnt D:/lint.cpp*
 ********************************************************/
double Tax(double income)
{
	double result;
	     if (income<=750)  result=income*0.01;
	else if (income<=2250) result=(income-750)*0.02+7.50;
	else if (income<=3750) result=(income-2250)*0.03+37.50;
	else if (income<=5250) result=(income-3750)*0.04+82.50;
	else if (income<=7000) result=(income-5250)*0.05+142.50;
	else                   result=(income-7000)*0.06+230.0;
	return result;
}
int main(void)
{
	double income,result;
	printf("Input your income:");
	scanf("%lf",&income);
	result=Tax(income);
	printf("Your tax is %f",result);
	(void) system("pause");
	return 0;
}