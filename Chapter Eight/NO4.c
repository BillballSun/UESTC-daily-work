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
	 long long int input_number,number_test;
	 bool checkpoint;
	 unsigned short int bit;
	 do
	 {
		 checkpoint=false;
		 printf("Enter a number:");
	     input_number=-1ll;
	     scanf("%lld",&input_number);
	     if (input_number<0) {printf("Error, please input a positive number.\n");checkpoint=true;}
	 }while(checkpoint);
	 number_test=input_number;
	 for(bit=0;number_test>0;bit++)
		 number_test=number_test/10;
	 number_test=input_number;
	 unsigned short int digit_every_bit[bit];
	 //in C++ not supported
	 for(int i=0;i<=(bit-1);i++)
		 digit_every_bit[i]=number_test%10,number_test=number_test/10;
	 printf("In reverse it is: ");
	 for(int i=0;i<=(bit-1);i++)
		 printf("%hu",digit_every_bit[i]);
	 printf("\n");
	 system("pause");
	 return 0;
 }