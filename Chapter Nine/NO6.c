/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
/* NO9.c (Chapter 9, page 153) */
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

long long int Power(long long int,int);

long long int Function_y(long long int);

int main(void)
{
	long long int x,y;
	printf("Please input x:");
	scanf("%lld",&x);
	y=Function_y(x);
	printf("y is %lld\n",y);
	system("pause");
	return 0;
}

long long int Power(long long int x,int n)
{
	long long int result,div_x;
	if (n==1) result=x;
	else if (n%2==0)
	    {
	    	div_x=Power(x,n/2);
	    	result=div_x*div_x;
    	}
    else result=Power(x,n-1)*x;
	return result;
}

long long int Function_y(long long int x)
{
	return 3*Power(x,5)+2*Power(x,4)-5*Power(x,3)-Power(x,2)+7*Power(x,1)-6;
}
