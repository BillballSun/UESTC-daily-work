/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
/* PR3.c (Chapter 9, page 151) */
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
bool Range_xy(long long int x,long long int y,long long int n)
{
	return x<=n-1&&x>=0&&y<=n-1&&y>=0?true:false;
}
unsigned long long int GraeatestCommonDivision(long long int x,long long int y)
{
	if (x<=0||y<=0) return 0;
	long long int helper;
	if (x<y) {helper=x;x=y;y=helper;}
	while(y>0)
	{
		helper=x%y;
		x=y;
		y=helper;
	}
	return x;
}
bool Is_leap_year(unsigned short int year)
{
	if (year%100==0)
		if (year%400==0) return true;
	    else return false;
	else
		if (year%4==0) return true;
	    else return false;
}
unsigned short int Day_of_year(unsigned short int month,unsigned short int day,unsigned short int year)
{
	bool leap_year=Is_leap_year(year);
	unsigned short int day_everymonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	unsigned short int total_day=0;
	if (month<=0||month>=13) return 0;
	if (leap_year) day_everymonth[2]=day_everymonth[2]+1;
	if (day>day_everymonth[month]) return 0;
	for (int i=1;i<=month-1;i++)
		total_day=total_day+day_everymonth[i];
	total_day=total_day+day;
	return total_day;
}
signed int Num_digits(long long int n)
{
	signed int digits;
	if (n<0) n=-n;
	if (n==0) return 1;
	digits=0;
	while (n>0)
	{
		n=n/10;
		digits=digits+1;
	}
	return digits;
}
signed short int Get_k_digit(long long int n,int k)
{
	int i;
	k=abs(k);
	if (n<0) n=-n;
	if (n==0&&k==1) return 0;
	for(i=1;i<=k-1&&n>0;i++)
		n=n/10;
	if (i<k-1||n==0) return -1;
	return n%10;
}
int Get_array_max(int a[],int length)
{
	int point=0;
	for(int i=0;i<=length-1;i++)
		if (a[i]>a[point]) point=i;
	return point;
}
int Get_array_average(int a[],int length)
{
	int total=0;
	for(int i=0;i<=length-1;i++)
		total=total+a[i];
	return total/length;
}
int Get_array_PositiveAmount(int a[],int length)
{
	int amount=0;
	for(int i=0;i<=length-1;i++)
		if (a[i]>0) amount=amount+1;
	return amount;
}
int Get_score(unsigned char ch)
{
	int result;
	switch(ch)
	{
		case 'A':result=4;break;
		case 'B':result=3;break;
		case 'C':result=2;break;
		case 'D':result=1;break;
		case 'F':result=0;break;
		default:result=0;break;
	}
	return result;
}
long double Compute_GPA(char grade[],int length)
{
	long double total=0.0l;
	unsigned char ch;
	for(int i=0;i<=length-1;i++)
		if (isalpha(ch=toupper(grade[i]))) total=total+Get_score(ch);
	return total/(long double)length;
}
long double Inner_product(double a[],double b[],int length)
{
	long double result=0.0l;
	for(int i=0;i<=length-1;i++)
		result=result+a[i]*b[i];
	return result;
}
int Get_value(unsigned char ch)
{
	ch=toupper(ch);
	int result;
	switch(ch)
	{
		case 'Q':result=9;
		case 'R':result=5;
		case 'B':result=3;
		case 'N':result=3;
		case 'P':result=1;
		 default:result=0;
	}
	return result;
}
int Evaluate_position(unsigned char board[8][8])
{
	int while_side=0,black_side=0;
	for(int i=0;i<=8-1;i++)
		for(int ii=0;i<=8-1;i++)
			if(isupper(board[i][ii])) while_side=while_side+Get_value(board[i][ii]);
		    else black_side=black_side+Get_value(board[i][ii]);
	return while_side-black_side;
}
bool Has_zero(int a[],int length)
{
	for(int i=0;i<=length-1;i++)
		if (a[i]==0) return true;
	return false;
}
double Median(double x,double y,double z)
{
	return x>=y?(x>=z?x:z):(y>=z?y:z);
}
unsigned long long int Power(unsigned short int n)
{
	unsigned long long int result=1ull;
	for(int i=2;i<=n;i++)
		result=result*i;
	return result;
}
unsigned long long int GCD_recursion(long long int x,long long int y)/*x>=y>=1*/
{
	if (y==0) return x;
	else return GCD_recursion(y,x%y);
}

unsigned long long int GCD_recursion_function(long long int x,long long int y)
{
	if (x<=0||y<=0) return 0;
	long long int helper;
	if (x<y) {helper=x;x=y;y=helper;}
	return GCD_recursion(x,y);
}
void Ten_to_x_Reversted(int n,int x)
{
	if (n!=0)
	{
		Ten_to_x(n/x,x);
		putchar('0'+n%x);
	}
}