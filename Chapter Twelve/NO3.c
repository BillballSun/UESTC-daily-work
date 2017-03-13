/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
**********************************************************/
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
**********************/
/************************************************
 *srand((unsigned)time(NULL));                  *
 *rand() to get a 0-maxint number, use %amount. *
*************************************************/
/********************************************************
 *PC-Lint check                                         *
 *C:/Lint/Lint-nt -i"C:/Lint" -u cmd_std.lnt D:/lint.cpp*
*********************************************************/

int main(void)
 {
	 unsigned char sentence[200];
	 unsigned long long int i;
	 bool checkpoint,output_symbol,still_letter;
	 short int last_subscript,work_point,word_start,word_end;
	 unsigned short int blackspace,letter_length;
	 unsigned char ch;
	 printf("Enter a sentence: ");
	 i=0ull;checkpoint=false;output_symbol=false;
	 do
	 {
		 ch=getchar();
		 if (ch=='\n'||i>=200) checkpoint=true;
		 else if ((ch=='!')||(ch=='\?')||(ch=='.')) {checkpoint=true;*(sentence+i)=ch;output_symbol=true;}
		 else *(sentence+i)=ch;
		 i=i+1;
	 }while(!checkpoint);
	 //i represent the true length of sentence
	 if (output_symbol) last_subscript=i-2; else last_subscript=i-1;
	 work_point=last_subscript;
	 while(work_point>=0)
	 {
		 blackspace=0;
		 for(int i=work_point;i>=0&&*(sentence+i)==' ';i--) blackspace=blackspace+1;
		 work_point=work_point-blackspace;
		 if (work_point>=0)
		 {
			 letter_length=0;
			 for(int i=work_point;i>=0&&*(sentence+i)!=' ';i--) letter_length=letter_length+1;
			 word_start=work_point-letter_length+1;
			 word_end=work_point;
			 for(int i=word_start;i<=word_end;i++)printf("%c",*(sentence+i));
			 work_point=work_point-letter_length;
			 still_letter=false;
			 for(int i=0;i<work_point;i++) if (*(sentence+i)!=' ') still_letter=true;
			 if (still_letter) printf(" ");
		 }
	 }
	 if (output_symbol) printf("%c\n",*(sentence+i-1));
	 system("pause");
	 return 0;
 }
 