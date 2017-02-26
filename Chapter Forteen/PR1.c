/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
**********************************************************/
/* PR1.c (Chapter 13, page 210) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf getchar putchar*/
#include <stdlib.h> /*system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper tolower isalpha isupper islower*/
#include <math.h> /*sqrt fabs(double) trunc*/
#include <string.h> /*mencpy strcpy(n) strlen strcat(n) strcmp*/
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
/****************************
 *#define					*
 *#if defined				*
 *#ifdef					*
 *#ifndef					*
 *#endif					*
 *							*
 *#if						*
 *#elif						*
 *#else						*
 *#endif					*
 *							*
 *#error					*
 *#line						*
 *#pragma					*
 *_Pragma(...)		 		*
 *#pragma warning disable	*
 *#pragma warning restore	*
 *							*
 *__LINE__					*
 *__FILE__					*
 *__DATE__					*
 *__TIME__					*
 *__STDC__				    *
 *__STDC_HOSTED__           *
 *__STDC_VERSION__          *
 *__STDC_IEC_599__          *
 *__STDC_IEC_599_COMPLEX__  *
 *__STDC_ISO_10646__        *
 *__func___                 *
 *__VA_ARGS__				*
 *variadic argument symbol  *
*****************************/
/***********useful Macro decleration start****************
#define Pascal true
#define DEBUG_mode true

#define Sample_structure_use true
#if Pascal
	#define begin {
	#define end }
#endif

#if 0
====DUBUG macro decleration====
#Test_divisor(x) if(x==0) do { printf("Error, divide zero\n");system("pause");} while(false)
#endif

#define Show_st(x) do switch(x%10) \
       {case 1:printf("st");break; \
	    case 2:printf("nd");break; \
		case 3:printf("rd");break; \
		default:printf("th");break;} while(false)

#define Print_divide_line() rintf("------------------------------------------------------\n")

#define Show_start_info() \
    do { \
	printf("--------------Amazing CA inc program-----------------\n"); \
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n"); \
	printf("Ways To Use:\n"); \
	printf("Please enter what to say\n"); \
	printf("Please enter what to say\n"); \
	printf("Please enter what to say\n"); \
	Print_divide_line(); \
	} while(false)
		
#define Get_rid_of_RestLine() \
do { \
	unsigned char ch; \
	while((ch=getchar())!='\n') continue; \
} while(false)

#define Safe_read_line(s,n) \
do { \
	char ch; \
	char *s_temp=s; \
	int n_temp=n; \
	while(((ch=getchar())!='\n')&&n>0) \
	{
		*s_temp++=ch;
		n_temp--;
	}
	if(ch!='\n') Get_rid_of_RestLine();
	*s_temp='\0';
} while(false)
	
bool Is_try_again(void)
{
	unsigned char ch;
	do
	{
		printf("Another chance(Y/N)?-------");
	    ch=toupper(getchar());
		if (ch!='\n') Get_rid_of_RestLine();
	}while(!(ch=='Y'||ch=='N'));
	return ch=='Y';
}

#define Is_try_again() \
(printf("Another chance(Y/N)?----"),toupper(getchar())=='Y')?,true \
:false

#define My_printf_without_escpe_sequence(x,...) printf(#x,__VA_ARGS__)
************useful Macro decleration end*****************/
/*****************Sample structure start*****************
void Show_start_info(void);
void Show_exit_info(void);
void Print_divide_line(void);
bool Safe_read_word(char *,int);
void Get_rid_of_RestLine(void);
void Show_st(int);
bool Is_try_again(void);
void Safe_read_line(char *, int);
======Modify indicator======
void Main_program(void);

int main(int argc, int argv[])
{
	bool cycle;
	Show_start_info();
	do
	{
		Main_program();
		cycle=Is_try_again();
	}while(cycle);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

======Modify indicator======
void Main_program(void)
{
	
}

void Show_start_info(void)
{
	printf("--------------Amazing CA inc program-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("Please enter what to say\n");
	printf("Please enter what to say\n");
	printf("Please enter what to say\n");
	Print_divide_line();
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

void Show_exit_info(void)
{
	Print_divide_line();
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}

void Show_st(int x)
{
	switch(x%10)
	{
		case 1:printf("st");break;
		case 2:printf("nd");break;
		case 3:printf("rd");break;
		default:printf("th");break;
	}
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while((ch=getchar())!='\n') continue;
}

bool Is_try_again(void)
{
	unsigned char ch;
	do
	{
		printf("Another chance(Y/N)?-------");
	    ch=toupper(getchar());
		if (ch!='\n') Get_rid_of_RestLine();
	}while(!(ch=='Y'||ch=='N'));
	return ch=='Y';
}

bool Safe_read_word(char *s,int n)
//Empty word return false, true means at least one letter read.
{
	char ch;
    while(isspace(ch=getchar())&&ch!='\n') continue;
	if(ch=='\n') 
	{
		s='\0';
		return false;
	}
	do
	{
		*s++=ch;
		n--;
		ch=getchar();
	}while(!isspace(ch)&&n>0);
	if(ch!='\n') Get_rid_of_RestLine();
	*s='\0';
	return true;
}

void Safe_read_line(char *s, int n)
{
	char ch;
	while(((ch=getchar())!='\n')&&n>0)
	{
		*s++=ch;
		n--;
	}
	if(ch!='\n') Get_rid_of_RestLine();
	*s='\0';
}
*****************Sample structure end*******************/
#define Sqare(x) ((x)*(x))
#define PR1_b(n) ((n)%4)
#define PR1_c(x,y) ((x)*(y)<100?true:false)
#define Nelems(a) (sizeof(a)/sizeof(*a))
#define Double(x) (2*(x))
#define AVG(x,y) (((x)+(y))/2)
#define AREA(x,y) ((x)*(y))
#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
//Output step 1: BCD...
//Output step 2: 123...
#define DISP(f,x) printf(#f"(%g) = %g\n", x, f(x))
#define DISP2(f,x,y) printf(#f"(%g) = %g, "#f"(%g) = %g\n",x,f(x),y,f(y))
#define Generic_max_func(type) 		\
type Max_##type(type x, type y) \
{								\
	return x>y?x:y;				\
}								
long Max_long(long x, long y)
{
	return x>y?x:y;
}
Generic_max_func(unsigned long) //Wrong

#define unsigned_long unsigned long
Generic_max_func(unsigned_long)
//step 1
unsigned_long Max_unsgined_long(unsigned_long x, unsigned_long y)
{
	return x>y?x:y;
}
//step 2
unsigned long Max_unsgined_long(unsigned long x, unsigned long y)
{
	return x>y?x:y;
}
//PR8
#define temp(x) "Line "#x" of file "__FILE__
#define temp_call(x) temp(x)
#define LINE_FILE temp_call(__LINE__)
//PR9
#CHECK(x,y,n) ((x)<=(n)-1&&(x)>=0&&(y)<=(n)-1&&(y)>=0?true:false)
#MEDIAN(x,y,z) (((x)+(y)+(z))/3)
#POLYNOMIAL(x) (3*(x)*(x)*(x)*(x)*(x)+2*(x)*(x)*(x)*(x)-5*(x)*(x)*(x)-(x)*(x)+7*(x)-6)
// PR10
// Difference between function_call and macro_difination_replacement
// macro difination can't check the type
// macro can't cycle
// macro only return expressions, unless it calls a function...
// macro ont easy to check errors, but preprocess result will help
// PR11
// In order to call
// fprintf(stderr, "Range error: index = %d/n", index)
#define ERROR(x,y) printf(stderr, x,y)
ERROR("Range error: index = %d/n", index)
// NO14
/*******Source file start***********/
#define N = 10
#define INC(x) x+1 //common make the mistake
#define SUB(x,y) x - y
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

int main(void)
{
	int a[N], i, j, k, m;
	
	#ifdef N
	i = j;
	#else
	j = i;
	#endif
	
	i=10*INC(j);
	i=SUB(j,k);
	i=SQR(SQR(j));
	i=M1(j,k);
	puts(M2(i,j));
	
	#undef SQR
	i=SQR(j);
	#define SQR
	i=SQR(j);
	
	return 0;
}
/*******Source file end*************/
/****My preprocess result start*****/








int main(void)
{
	int a[= 10], i, j, k, m;
	

	i = j;



	
	i=10*j+1;
	i=j-k;
	i=((j)*(j))*((j)*(j));
	i=jk;
	puts("i" "j");
	

	i=SQR(j);

	i=(j);
	
	return 0;
}
/****My preprocess result end*******/
// PR15
#define ENGLISH /*ENGLISH/FRENCH/SPANISH*/
printf(
#if defined	ENGLISH
	"Insert Disk 1"
#elif defined FRENCH
	"Inserez Le Disque 1"
#elif define SPANISH
	"Inserte El Disco 1"
#else
	#error Language difination not found
#endif
);
// PR16
#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)
IDENT(foo)
// step 1
PRAGMA(ident "foo")
// step 2*
#pragma ident "foo"
