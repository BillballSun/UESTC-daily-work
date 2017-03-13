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
#define Length 10

int Stack[Length];

int *pointer=Stack;

void Empty_stack(void)
{
	*pointer=Stack;
}

bool Is_stack_full(void)
{
	return pointer==Stack+Length;
}

bool Is_stack_empty(void)
{
	return pointer==Stack;
}

void Insert_data(int get_data)
{
	if (Is_stack_full()) Stack_overflow();
	else *p++=Insert_data;
}

int Pop_data(void)
{
	if (Is_stack_empty()) Stack_downflow();
	else return *--p;
}

bool Search(const int *a,int length, int key)
{
	bool result=false;
	for(int *p=a;p<=a+Length-1&&!result;p++)
		if (*p==key) result=true;
	return result;
}

void Store_zero(int *a, int length)
{
	for(int i=0;i<=length-1;i++)
		*(a+i)=0;
}

void Store_zero_2(int *a, int length)
{
	for(int *p=a;p<=a+length-1;p++)
		*p=0;
}

long double Innner_product(const double *a, const double *b, int length)
{
	double sum=0.0l;
	for(int i=0;i<=length-1;i++)
		sum=sum+*(a+i)+*(b+i);
	return sum;
}

void Find_two_largest(const int *a, int length, int * const largest, int * const second_largest)
{
	int *largest_point=a;
	for(int *point=a+1;point<=a+length-1;point++)
	int second_largest_point;
    if (length==1) second_largest_point=largest_point;
	else
	{
		if (largest_point==a) second_largest_point=a+1;
		else second_largest_point=a;
		for(int *point=a;point<=largest_point-1;point++)
			if (*second_largest_point<*point) second_largest_point=point;
		for(int *point=largest_point+1;point<=length-1;point++)
			if (*second_largest_point<*point) second_largest_point=point;
	}
	*largest=*largest_point;
	*second_largest=*second_largest_point;
}

/*
#define Length 10
int a[Length][Length]
Default_ident(*a,Length);
*/

void Default_ident(int *a00_point,int length)
{
	for(int *p=a00_point,x=0;p<=a+length*length-1;p++,x=(x+1)%length)
		if (x==0) *p=1; else *p=0;
}

/*
int temperatures[7][24];
*/

void Search_external(int (*a)[24], bool (*result)[24], int length, int key, int *amount)
{
	for(bool *p=*result;p<=result+length*24-1;p++)
		*P=false;
	*amount=0;
	for(int i=0;i<=length*24-1;i++)
		if (*(*a+i)==key) {*(*result+i)=true;*amount+=1;}
}

void Show_role_info(int (*a)[24], int role)
{
	int *p=*(a+role-1);
	printf("The %d role is: ",role);
	for(int i=0;i<=24-1;i++)
		printf("%d  ",*(p+i));
	printf("\n");
}

int Find_largest(int *a, int length)
{
	int big=*a;
	for(int *p=a+1;p<=a+length-1;p++)
		if(big<*p) big=*p;
	return big;
}

void Show_highest_everyday(int (*a)[24], int length)
{
	for(int i=1;i<=length;i++)
		printf("In the %d day, the highest temperature is %d.\n",i,Find_largest(*(a+i-1),24));
}

int Sum_two_dimensional_array(const int *a[LEN], int length)
{
	int sum=0;
	for(int i=0;i<=length-1;i++)
		for(int *j=*(a+i);j<=*(a+i)+LEN-1;j++)
			sum=sum+*j;
	return sum;
}

bool Is_upcase(unsigned char ch)
{
	if (ch>='A'&&ch<='Z') return true;
	else return false;
}

int Get_value(unsigned char ch)
{
	int result;
	switch(toupper(ch))
	{
		case 'Q':result=9;break;
		case 'R':result=5;break;
		case 'B':result=3;break;
		case 'N':result=3;break;
		case 'P':result=1;break;
		default:result=0;break;
	}
	return result;
}

int evaluate_position(unsigned char (*board)[8],int length)
{
	
	int white_sum=0;black_sum=0;
	for (unsigned char *p=*board;p<=*(board+length-1)+8-1;p++)
		if(Is_upcase(*p)) white_sum=white_sum+Get_value(ch);
	    else black_sum=black_sum+Get_value(ch);
	return white_sum-black_sum;
}



































