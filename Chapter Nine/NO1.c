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
 /*******************************************************
  *PC-Lint check                                        *
  *C:/Lint/Lint-nt -i"C:/Lint" -u cmd_std.lnt X:/xxx.cpp*
  *******************************************************/
#define Length_array 20
void InputData(int a[],int length)
{
	printf("Plase input %d digits:",length);
	for(int i=0;i<=length-1;i++)
		scanf("%d",&a[i]);
}
void Sort_array_bubble(int a[],int length)
{
	int temp;
	if (length<=1) return;
	for(int i=0;i<=length-2;i++)
		if(a[i]>a[i+1]) {temp=a[i];a[i]=a[i+1];a[i+1]=temp;}
	Sort_array_bubble(a,length-1);
}
void Sort_array_select(int a[],int length)
{
	int point=0,temp;
	if (length<=1) return;
	for(int i=1;i<=length-1;i++)
		if(a[i]>a[point]) point=i;
	temp=a[point];a[point]=a[length-1];a[length]=temp;
	Sort_array_select(a,length-1);
}
void SeperateLine(int length)
{
	for(int i=1;i<=length;i++)
		printf("==");
	printf("\n");
}
void ShowTime(int length)
{
	printf("The result is as follow:\n");
	SeperateLine(length);
	for(int i=0;i<=length-1;i++)
		printf("%d ",a[i]);
	printf("\n");
	SeperateLine(length);
}
int main(void)
{
	int a[Length_array];
	InputData(a,Length_array);
	Sort_array_bubble(a,Length_array);
	ShowTime(Length_array);
	system("pause");
	return 0;
}