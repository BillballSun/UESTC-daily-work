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
int GiveDigitAmount(long long int x)
{
	int digits=0;
	x=abs(x);
	if (x==0) return 1;
	while(x>0)
	{
		x=x/10;
		digits=digits+1;
	}
	return digits;
}

int Succeed(signed short int position,unsigned short int length)
{
	position=position+1;
	if (position>length-1) position=0;
	return position;
}

int Preceed(signed short int position,unsigned short int length)
{
	position=position-1;
	if (position<0) position=length-1;
	return position;
}

void PrintLine(unsigned short int square_length,int digit_amount)
{
	for (long long int i=1;i<=square_length*(digit_amount+1);i++)
		printf("=");
	printf("\n");
}

int main(void)
{
	unsigned short int square_length;
	signed short int x_position,y_position,x_try,y_try;
	bool checkpoint;
	int digit_amount,blackspace;
	unsigned short int square[20][20]={0};
	do
	{
		checkpoint=false;square_length=0;
		printf("To generate a magic square, please input its length(1<=n<=20):");
		scanf("%hu",&square_length);
		if (square_length<=0||square_length>=21) {printf("Error, unaccepted length.\n");checkpoint=true;}
	}while(checkpoint);
	printf("The %hu magic square is shown below.\n");
	x_position=0;
	y_position=square_length/2+square_length%2-1;
	square[x_position][y_position]=1;
	for(int i=2;i<=square_length*square_length;i++)
	{
		x_try=Preceed(x_position,square_length);
		y_try=Succeed(y_position,square_length);
		if (square[x_try][y_try]!=0)
		{
			y_try=y_position;
			x_try=Succeed(x_position,square_length);
		}
		x_position=x_try;y_position=y_try;
		square[x_position][y_position]=i;
	}
	digit_amount=GiveDigitAmount(square_length*square_length);
	PrintLine(square_length,digit_amount);
	for (int x=0;x<=square_length-1;x++)
	{
		for (int y=0;y<=square_length-1;y++) 
		{
			blackspace=digit_amount+1-GiveDigitAmount(square[x][y]);
			for (int b=1;b<=blackspace;b++) printf(" ");
			printf("%hu",square[x][y]);
		}
		printf("\n");
	}
	PrintLine(square_length,digit_amount);
	system("pause");
	return 0;
}