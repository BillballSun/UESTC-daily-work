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
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*********************
 * #define Bool int  *
 * typedef int Bool; *
 *********************/
 
 int main(void)
 {
	 unsigned long long int total_characters=0ull;
	 unsigned long int words_in_sentense=0uL;
	 long double average=0.0l;
	 bool end_word=true;
	 unsigned char ch,continue_point='Y';
	 while (continue_point=='Y')
	 {
		 printf("Enter a sentence:");
	     while((ch=getchar())!='\n')
	    	 if ((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
	    	 {
	    		 total_characters=total_characters+1;
	    		 if (end_word) {end_word=false;words_in_sentense=words_in_sentense+1;}
	    	 }
	    	 else end_word=true;
	     if (total_characters==0) printf("You didn\'t entered any word.\n");
	     else 
	     {
	    	average=(long double)total_characters/(long double)words_in_sentense;
	    	printf("You entered %llu characters and it has %lu words.\n",total_characters,words_in_sentense);
	    	printf("On average there are %.1Lf characters in each word.\n",average);
	     }
		 system("pause");
		 do
		 {
			 printf("Do you want to continue(Y/N)-----");
			 continue_point=getchar(),continue_point=toupper(continue_point);
			 if (continue_point!='\n') while((ch=getchar())!='\n') continue;
		 }while(continue_point!='Y'&&continue_point!='N');
	 }

     printf("Ok, see you next time.\n");
	 system("pause");
	 return 0;
 }