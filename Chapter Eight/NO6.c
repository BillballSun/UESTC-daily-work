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
	 typedef char input_word_array;
	 input_word_array input_word[256];
	 unsigned short int sentence_length=0;
	 unsigned char ch;
	 printf("Enter message:");
	 while((ch=getchar())!='\n')
	 {
		 input_word[sentence_length]=ch;
		 sentence_length=sentence_length+1;
	 }
	 printf("In B1FF-speak:");
	 for(int i=0;i<=(sentence_length-1);i++)
	 {
		 ch=toupper(input_word[i]);
		 switch (ch)
		 {
			 case 'A':ch='4';break;
			 case 'B':ch='8';break;
			 case 'E':ch='3';break;
			 case 'I':ch='1';break;
			 case 'O':ch='0';break;
			 case 'S':ch='5';break;
		 }
		 putchar(ch);
	 }
	 printf("!!!!!!!!!!\n");
	 system("pause");
	 return 0;
 }