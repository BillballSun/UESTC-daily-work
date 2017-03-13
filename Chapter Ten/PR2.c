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

int user_guess,random_number;

void Print_divide_line(void);

void Show_start_info(void);

void Cycle_game(void);

void Show_exit_info(void);

int Generate_random(int);

void Show_turn_time(unsigned long int);

void Show_guess_info(void);

int Get_guess(void);

bool Is_try_again(void);

void Show_guess_time_info(unsigned long long int);

int main(void)
{
	Show_start_info();
	Cycle_game();
	Show_exit_info();
	system("pause");
	return 0;
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

void Show_start_info(void)
{
	printf("---------------Amazing Guessing game-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("Ways To Play:\n");
	printf("Generating a random number from 1 to 100.\n");
	printf("Enter your guess.\n");
	printf("After that, follow the system instruction, try to find it with least time.\n");
	Print_divide_line();
}


void Show_exit_info(void)
{
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be played.\n");
	printf("See you next time.\n");
}


void Cycle_game(void)
{
	unsigned long int turn=0ul;
	bool checkpoint=false;
	unsigned long long int guess_time;
	srand((unsigned)time(NULL));
	do
	{
		turn=turn+1ul;
		random_number=Generate_random(100);
		Show_turn_time(turn);
		guess_time=0ull;
		do
		{
			guess_time=guess_time+1ull;
			user_guess=Get_guess();
			Show_guess_info();
		}while(user_guess!=random_number);
		Show_guess_time_info(guess_time);
		checkpoint=!(Is_try_again());
		Print_divide_line();
	}while(!checkpoint);
}

void Show_guess_time_info(unsigned long long int guess_time)
{
	if (guess_time==1) printf("Incredible! You win in just one chance!\n\n");
	else printf("You win in %llu times.\n\n",guess_time);
}

bool Is_try_again(void)
{
	unsigned char getit,ch;
	getit='1';
	do
	{
		printf("New game, new chance, shall we try again?(Y/N)---------");
		getit=toupper(getchar());
		if (getit!='\n') while ((ch=getchar())!='\n') continue;
	}while(getit!='Y'&&getit!='N');
	return getit=='Y';
}

int Generate_random(int x)
{
	return rand()%x+1;
}

void Show_turn_time(unsigned long int turn)
{
	printf("Now, it is the %lu",turn);
	switch(turn%10)
	{
		case 1:printf("st");break;
		case 2:printf("nd");break;
		case 3:printf("rd");break;
		default:printf("st");break;
	}
	printf(" time to play, wish you good luck.\n");
	printf("\nInfo: A random number between 1-100 has been generated.\n\n");
}

int Get_guess(void)
{
	int result=0;
	bool check;
	unsigned char ch;
	do
	{
		check=false;
		printf("Enter your guess:");
	    scanf("%d",&result);
		while ((ch=getchar())!='\n') continue;
		if (result<=0||result>=101) {printf("Unaccpted guess.\n");check=true;}
	}while(check);
	return result;
}

void Show_guess_info(void)
{
	if (user_guess==random_number) printf("Congratulations, You are definitely right.\n");
	else if (user_guess<random_number)
	{
		     if (random_number-user_guess<=5) printf("A slight bit low, be careful, almost there.\n");
		else if (random_number-user_guess<=15) printf("Low, but not far.\n");
		   else printf("Too low, come on!\n");
	}
	else
	{
		     if (user_guess-random_number<=5) printf("A slight bit high, be careful, almost there.\n");
		else if (user_guess-random_number<=15) printf("High, but not far.\n");
		   else printf("Too high, come on!\n");
	}
	printf("\n");
}
