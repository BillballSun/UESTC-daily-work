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
void Sort(int a[],int low,int high)
{
	int takeup;
	takeup=a[low];
	while(low<high&&a[high]>=takeup)
		high--;
	if (low>=high) return;
	a[low++]=a[high];
	while(low<high&&a[low]<=takeup)
		low++;
	if (low>=high) {a[high]=takeup;return;}
	a[high--]=a[low];
	a[low]=takeup;
	Sort(a,low,high);
	return;
}

void DivideLine(unsigned short int length)
{
	for(int i=0;i<=length-1;i++)
		printf("==");
	printf("\n");
}
void Output_sqaure(int a[],unsigned short int length)
{
	for(int i=0;i<=length-1;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void Outputresult(int a[],unsigned short int length)
{
	printf("The result is as follow:\n");
	DivideLine(length);
	Output_sqaure(a,length);
	DivideLine(length);
}

unsigned short int UI_input_GetLength(void)
{
	bool checkpoint;
	unsigned short int length;
	unsigned char ch;
	printf("Sort a square by first number.\n");
	do
	{
		length=0;checkpoint=false;
		printf("How many numbers you want to input(no more than 20):");
	    scanf("%hu",&length);
		while((ch=getchar())!='\n') continue;
		if (length<=0||length>=21) {printf("Error, unexpected length of square.\n");checkpoint=true;}
	}while(checkpoint);
	return length;
}

void Input_square(int a[],unsigned short int length)
{
	printf("Plase input the %hu numbers:",length);
	for(int i=0;i<=length-1;i++)
		scanf("%d",&a[i]);
}

void Pause_Program(void)
{
	system("pause");
}

int main(void)
{
	unsigned short int length;
	length=UI_input_GetLength();
	int a[20];
	Input_square(a,length);
	Sort(a,0,length-1);
	Outputresult(a,length);
	Pause_Program();
	return 0;
}