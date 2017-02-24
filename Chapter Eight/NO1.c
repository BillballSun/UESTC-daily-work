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
 #define Length_array (sizeof(number_existance)/sizeof(number_existance[0]))
 
 int main(void)
 {
	 bool number_existance[10]={false},
	       number_repeated[10]={false},
		   checkpoint,nothing_point;
	 unsigned char ch;
	 do
	 {
		 printf("Enter a number:");
		 checkpoint=false;
		 for (int i=0;i<=Length_array-1;i++)
		     number_existance[i]=false,number_repeated[i]=false;
	     while((!checkpoint)&&((ch=getchar())!='\n'))
             if (ch<'9'&&ch>'0')
				 if (!number_existance[ch-'0']) number_existance[ch-'0']=true;
			     else number_repeated[ch-'0']=true;
	         else 
			 {
				 checkpoint=true;
				 printf("Error, digit not detected.\n");
				 printf("Please try again.\n");
				 while((ch=getchar())!='\n') continue;
		     }
	 }while(checkpoint);
	 nothing_point=true;
	 for (int i=0;i<=(Length_array-1);i++)
		 if (number_repeated[i]) nothing_point=false;
	 printf("Repeated digit(s):");
	 if (nothing_point) printf(" NONE");
	 else for (int i=0;i<=(Length_array-1);i++)
	          if (number_repeated[i]) printf(" %d",i);
	 printf("\n");
	 system("pause");
	 return 0;
 }