/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
**********************************************************/
/* PR1.c (Chapter 11, page 182) */
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
/*********************************************
 *system("chcp 437>nul.");Show ASCII extended*
**********************************************/

void Swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void Avg_sum(double a[],int length,double *average,double *sum)
{
	*sum=0.0;
	for(int i=0;i<=length-1;i++)
		*sum=*sum+a[i];
	*average=*sum/length;
}

void split_time(unsigned long total_sec,int *hours,int *minutes,int seconds)
{
    if (total_sec>=60*60*24) (*hours=-1;*minutes=-1;*seconds=-1;}
	else
	{
		*hours=total_sec/(60ul*60ul);
		total_sec=total_sec%(unsigned long)(60*60);
		*minutes=total_sec/60ul;
		total_sec=total_sec%60ul;
		*seconds=total_sec;
	}
}

void Find_two_largest(int a[],int length, int *largest, int *second_largest)
{
	unsigned short point;
	int temp;
	point=0u;
	for(int i=1;i<=length-1;i++)
		if(a[point]<a[i]) point=i;
	*largest=a[point];
	if (length>=2)
	{
		unsigned short point2;
		if (point==0u) point2=1u; else point2=0u;
		for(int i=0;i<=point-1;i++)
			if (a[point2]<a[i]) point2=i;
		for(int i=point+1;i<=length-1;i++)
			if (a[point2]<a[i]) point2=i;
		*second_largest=a[point2];
	}
}

bool Is_LeapYear(int year)
{
	if (year%100==0)
		if (year%400==0) return true;
	    else return false;
	else if (year%4==0) return true;
	else return false;
}

void split_date(int day_of_year, int year, int *month, int *day)
{
	int day_month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (Is_LeapYear(year)) day[2]=day[2]+1;
	*month=1;
	while(day_of_year>day_month[*month])
	{
		day_of_year=day_of_year-day_of_year[*month];
		*month=*month+1;
	}
	*day=day_of_year;
}

int *Find_largest(int a[],int length)
{
	int point=0;
	for(int i=0;i<=length-1;i++)
		if (a[i]>a[point]) point=i;
	return &a[point];
}

void Pay_amount(int dollars,int *twenties, int *tens, int *fives, int *ones)
{
	*twenties=dollars/20;
	dollars=dollars%20;
	*tens=dollar/10;
	dollars=dollars%10;
	*fives=dollars/5;
	dollars=dollars%5;
	*ones=dollars;
}

int Get_GCD(int a,int b)
{
	if (a<b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	int temp;
	while(b>0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

int Reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
	bool negative=(numerator*denominator)<0;
	numerator=abs(numerator);
	denominator=abs(denominator);
	if (denominator==0) return EXIT_FAILURE;
	else if (numerator==0) {*reduced_numerator=0;*reduced_denominator=0;}
	else
	{
		int temp=Get_GCD(numerator,denominator);
		*reduced_numerator=numerator/temp;
		*reduced_denominator=denominator/temp;
	}
	return EXIT_SCUCCESS;
}
