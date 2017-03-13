/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
*********************************************************/
/* NO3.c (Chapter 6, page 85) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf*/
#include <stdlib.h> /*system abs*/
#include <stdbool.h> /*bool true false*/
/*******************
 *#define Bool int *
 *typedef int Bool;*
 *******************/

 int main(void)
 {
	 int a=0,b=0,t,point=0,former_a,former_b;
	 bool checkpoint=false;
	 do
	 {
		 printf("Enter a fraction:");
	     scanf("%d/%d",&a,&b);
		 if (b!=0) checkpoint=true; else printf("Input error, please try again with mind.\n");
	 }
	 while (!checkpoint); 
	      if (a==0) point=1;
	 else switch ((a<0)+(b<0))
	      {
			   case 1:point=2; /*NO break*/
			  default:a=abs(a);b=abs(b);
		  }
	 printf("In lowest terms: ");
	 switch (point)
	 {
		 case 1:/*a==0*/
		 printf("0\n");break;
		 case 2:/*negative*/
		 printf("-");
		 case 0:
		 former_a=a;
		 former_b=b;
		 if (a<b) {t=a;a=b;b=t;}
	     while (b!=0)
	     {
		     t=a%b;
	    	 a=b;
		     b=t;
    	 }
		 former_a=former_a/a;
		 former_b=former_b/a;
		 printf("%d",former_a);
		 if (former_b!=1) printf("/%d",former_b);
		 printf("\n");
		 break;/*useless*/
	 }

	 system("pause");
	 return 0;
 }