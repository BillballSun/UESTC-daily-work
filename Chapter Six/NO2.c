/*********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
*********************************************************/
/* NO2.c (Chapter 6, page 85) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf*/
#include <stdlib.h> /*system*/
#include <stdbool.h> /*bool true false*/
/*******************
 *#define Bool int *
 *typedef int Bool;*
 *******************/

 int main(void)
 {
	 int a=0,b=0,t;
	 bool checkpoint=false;
	 do
	 {
		 printf("Enter two digits:");
	     scanf("%d%d ",&a,&b);
		 if (a>=1&&b>=1) checkpoint=true; else printf("Input error, please try again with mind.\n");
	 }
	 while (!checkpoint); 
	 if (a<b) {t=a;a=b;b=t;}
	 while (b!=0)
	 {
		 t=a%b;
		 a=b;
		 b=t;
	 }
	 printf("GCD(Greatest common divisor) is %d\n",a);
	 
	 system("pause");
	 return 0;
 }