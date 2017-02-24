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
#include <stdlib.h> /*system abs(int) srand rand*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper tolower*/
#include <math.h> /*sqrt fabs(double) trunc*/
#include <string.h> /*mencpy*/
#include <time.h> /*time*/
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*********************
 * #define Bool int  *
 * typedef int Bool; *
 *********************/
 #define sentence_max_length 200
 
 int main(void)
 {
	 typedef unsigned char sentence_array_type;
	 sentence_array_type sentence[sentence_max_length];
	 unsigned long long int sentence_true_length;
	 unsigned char ch;
	 unsigned short int shift;
	 bool checkpoint;
	 printf("Enter message to be encrypted:");
	 sentence_true_length=0ull;
	 while (((ch=getchar())!='\n')&&(sentence_true_length<sentence_max_length))
	 {
		 sentence[sentence_true_length]=ch;
		 sentence_true_length++;
	 }
	 do
	 {
		 checkpoint=false;
		 shift=0u;
		 printf("Enter shift(1-25):");
		 scanf("%u",&shift);
		 if (shift==0||shift>=26) checkpoint=true;
	 }while(checkpoint);
	 for(int i=0;i<=sentence_true_length-1;i++)
		 if (sentence[i]>='a'&&sentence[i]<='z') 
		     sentence[i]=((ch-'a')+shift)%26+'a';
	else if (sentence[i]>='A'&&sentence[i]<='Z') 
		     sentence[i]=((ch-'A')+shift)%26+'A';
	 printf("Encrypted message:");
	 for(int i=0;i<=sentence_true_length-1;i++)
		 printf("%c",sentence[i]);
	 printf("\n");
	 system("pause");
	 return 0;	 
 }