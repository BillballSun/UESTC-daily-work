/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
/* NO16.c (Chapter 8, page 128) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf getchar putchar*/
#include <stdlib.h> /*system abs(int) srand rand*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper tolower isalpha*/
#include <math.h> /*sqrt fabs(double) trunc*/
#include <string.h> /*mencpy*/
#include <time.h> /*time*/
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*********************
 * #define Bool int  *
 * typedef int Bool; *
 *********************/
 
 int main(void)
 {
	 typedef unsigned long long int letter_array_type;
	 letter_array_type letter1[26]={0},letter2[26]={0};
	 unsigned char ch;
	 bool checkpoint;
	 do
	 {
		 checkpoint=false;
		 printf("Enter the first word:");
		 while(((ch=tolower(getchar()))!='\n')&&!checkpoint)
			 if (isalpha(ch)) letter1[ch-'a']=letter1[ch-'a']+1;
		     else {checkpoint=true;printf("Error, unexpected input.\nPlease try again.\n");}
	 }while(checkpoint);
	 do
	 {
		 checkpoint=false;
		 printf("Enter the sencond word:");
		 while(((ch=tolower(getchar()))!='\n')&&!checkpoint)
			 if (isalpha(ch)) letter2[ch-'a']=letter2[ch-'a']+1;
		     else {checkpoint=true;printf("Error, unexpected input.\nPlease try again.\n");}
	 }while(checkpoint);
	 checkpoint=true;
	 for (int i=0;i<=25&&checkpoint;i++) if (letter1[i]!=letter2[i]) checkpoint=false;
	 if (checkpoint) printf("They are anagtams.\n");
	 else printf("They are not anagrams.\n");
	 system("pause");
	 return 0;
 }