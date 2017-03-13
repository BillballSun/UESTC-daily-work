/********************************************************
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
#include <stdlib.h> /*system abs*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper*/
#include <math.h> /*sqrt*/
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*******************
*#define Bool int *
*typedef int Bool;*
*******************/

int main(void)
{
	bool checkpoint;
	float total,right_digit;
	int operate_time;
	unsigned char ch;
	printf("It performs as a limited caculator.\n");
	printf("You are only allowed to use + - * / four operators.\n");
	printf("WARNING: It will only caculate from left to right.\n");
	do
	{
		checkpoint=false;total=0.0f;/*Avoid not detecting total*/
		printf("Enter an expression:");
		scanf("%f",&total);
		operate_time=0;
		while(((ch=getchar())!='\n')&&(!checkpoint))
			switch(ch)
			{
				case '+':case '-':case '*':case '/':
				right_digit=1;scanf("%f",&right_digit);
				operate_time=operate_time+1;
				switch (ch)
				{
					case '+':total=total+right_digit;break;
					case '-':total=total-right_digit;break;
					case '*':total=total*right_digit;break;
					case '/':
				    if (right_digit==0) {printf("Error, divide zero.\n");checkpoint=true;}
				    else total=total/right_digit;break;
				}break;
				default:
				checkpoint=true;printf("Error, operator isn\'t detected.\n");break;
			}
		if (checkpoint) 
		{
			printf("Please try again with your mind.\n");
			while((ch=getchar())!='\n') continue;
		}
	}while(checkpoint);
	printf("After %d times caculation, the result is %-3.2f\n",operate_time,total);
	
	system("pause");
	return 0;
}