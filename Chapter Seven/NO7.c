/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
*********************************************************/
/* NO8.c (Chapter 6, page 86) */
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
	int first_up,first_down,first_symbol;
	int second_up,second_down,second_symbol;
	int result_up,result_down;
	int GCD_up,GCD_down,t;
	bool checkpoint;
	char ch;
	do
	{
		checkpoint=false;
		printf("Please input the first fraction:");
		scanf("%d/%d",&first_up,&first_down);
		printf("Please input the second fraction:");
		scanf("%d/%d",&second_up,&second_down);
		while((ch=getchar())!='\n') continue;/*get rid of the rest of the line*/
		printf("You are allowed to use +-*/ as operator.\nPlease input the operator:");
		ch=getchar();
		if (ch!='+'&&ch!='-'&&ch!='*'&&ch!='/') {checkpoint=true;printf("Error, wrong operator.\n");}
		if (first_down==0||second_down==0) {checkpoint=true;printf("Error, incorrect fraction form.\n");}
		if (second_up==0&&ch=='/') {checkpoint=true;printf("Error, divide zero.\n");}
		if (checkpoint) printf("Please try again with your mind.\n");
	}while(checkpoint);
	first_symbol=((first_up<0)+(first_down<0))%2;
	second_symbol=((second_up<0)+(second_down<0))%2;
	first_up=abs(first_up);first_down=abs(first_down);
	second_up=abs(second_up);second_down=abs(second_down);
	switch(ch)
	{
		case '+':case '-': 
		    if (first_symbol) first_up=first_up*(-1);
			if (second_symbol) second_up=second_up*(-1);
			if (ch=='+') result_up=first_up*second_down+second_up*first_down;
			else         result_up=first_up*second_down-second_up*first_down;
			result_down=first_down*second_down;break;
		case '*':case '/':	    
			if ((first_symbol+second_symbol)%2) first_up=first_up*(-1);
			if (ch=='*') {result_down=first_down*second_down;result_up=first_up*second_up;}
		    else {result_up=first_up*second_down;result_down=first_down*second_up;}break;
	}
	printf("The result is ");
	if (result_up==0) printf("0");
	else
	{
		if (result_up<0) {printf("-");result_up=abs(result_up);}
		GCD_up=result_up;GCD_down=result_down;
		if (GCD_up<GCD_down) {t=GCD_up;GCD_up=GCD_down;GCD_down=t;}
		while (GCD_down!=0)
		{
			t=GCD_up%GCD_down;
			GCD_up=GCD_down;
			GCD_down=t;
		}
		result_up=result_up/GCD_up;
		result_down=result_down/GCD_up;
		if (result_down==1) printf("%d",result_up);
		else printf("%d/%d",result_up,result_down);
	}
	printf("\n");
	
	system("pause");
	return 0;
}