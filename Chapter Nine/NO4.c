/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
/* NO1.c (Chapter 9, page 151) */
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

void Read_word(unsigned short int counts[26])
{
	unsigned char ch;
	for(int i=0;i<=25;i++) counts[i]=0;
	printf("Please input a word:");
	while((ch=getchar())!='\n') if(isalpha(ch=toupper(ch))) counts[ch-'A']=counts[ch-'A']+1;
}
bool equal_array(unsigned short int counts1[26],unsigned short int counts2[26])
{
	bool equal=true;
	for(int i=0;i<=25;i++) if (counts1[i]!=counts2[i]) equal=false;
	return equal;
}
int main(void)
{
	unsigned short counts[26],counts1[26]={0},counts2[26]={0};
	//Useless for counts, why not give read_word counts1/2016
	Read_word(counts);
	memcpy(counts1,counts,sizeof(counts1));
	Read_word(counts);
	memcpy(counts2,counts,sizeof(counts2));
	if (equal_array(counts1,counts2)) printf("They are somehow similar.\n");
	else printf("They are somehow unsimilar.\n");
	system("pause");
	return 0;
}
