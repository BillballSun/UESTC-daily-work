/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
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
 *********************/
/************************************************
 *srand((unsigned)time(NULL));                  *
 *rand() to get a 0-maxint number, use %amount. *
 ************************************************/
/********************************************************
 *PC-Lint check                                         *
 *C:/Lint/Lint-nt -i"C:/Lint" -u cmd_std.lnt D:/lint.cpp*
 ********************************************************/
void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}
void Print_info(void)
{
	printf("---------------Amazing Guessing game-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("Ways To Play:\n");
	printf("Default win  number:7 11\n");
	printf("Default lose number:2 3 12\n");
	printf("After that, 7 to lose, what you roll before is to win.\n");
	Print_divide_line();
}

void Show_order(unsigned long long int order)
{
	printf("Now the %llu",order);
	switch(order%10)
	{
		case 1:printf("st");break;
		case 2:printf("nd");break;
		case 3:printf("rd");break;
		default:printf("st");break;
	}
	printf(" time to play, wish you good luck.\n");
}

unsigned short int Radom_roll(void)
{
	return (unsigned short)(rand()%6+1);
}

void Show_random_result(unsigned short int roll_1,unsigned short int roll_2)
{
	printf("The first  random roll is %hu\n",roll_1);
	printf("The second random roll is %hu\n",roll_2);
	printf("So the sum is %hu\n",roll_1+roll_2);
}

bool Is_try_again(bool win[13],bool lose[13],unsigned short int sum)
{
	bool result=true;
	if (win[sum]||lose[sum]) result=false;
	return result;
}

bool Is_win(bool win[13],unsigned short int sum)
{
	bool result=false;
	if (win[sum]) result=true;
	return result;
}

void Print_exit_info(unsigned int win_time,unsigned int lose_time)
{
	printf("Your result is as below.\n");
	printf("Win  time: %u\n",win_time);
	printf("Lose time: %u\n",lose_time);
	Print_divide_line();
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be played.\n");
	printf("See you next time.\n");
}

int main(void)
{
	unsigned char cycle='Y',ch;
	unsigned long long int order;
	unsigned short int roll_1,roll_2,sum;
	unsigned int win_time=0u,lose_time=0u;
	bool win[13],lose[13],checkpoint;
	srand((unsigned)time(NULL));
	Print_info();
	while(cycle=='Y')
	{
		for(int i=1;i<=12;i++) {win[i]=false;lose[i]=false;}
		win[7]=true;win[11]=true;
		lose[2]=true;lose[3]=true;lose[12]=true;
		order=0ull;checkpoint=false;
		do
		{
			order=order+1ull;
	    	Show_order(order);
			printf("Ready to start?-----------");
			ch=getchar();
			if (ch!='\n') while((ch=getchar())!='\n') continue;
			roll_1=Radom_roll();
			roll_2=Radom_roll();
			sum=roll_1+roll_2;
			Show_random_result(roll_1,roll_2);
			if (!Is_try_again(win,lose,sum))
			{
				checkpoint=true;
				if(Is_win(win,sum)) {printf("Congratulations! you win.\n");win_time=win_time+1u;}
				else {printf("Lose, don\'t be sad.\n");lose_time=lose_time+1u;}
			}
			else
			{
				for(int i=1;i<=12;i++) {win[i]=false;lose[i]=false;}
				win[sum]=true;
				lose[7]=true;
				printf("Opp, no result this time.\n");
			}
		Print_divide_line();
		}while(!checkpoint);
		do
		{
			printf("Do you wanna continue?(Y/N)---------");
			cycle=getchar();
			if(cycle!='\n') while((ch=getchar())!='\n') continue;
			cycle=toupper(cycle);
		}while(!(cycle=='Y'||cycle=='N'));
		Print_divide_line();
	}while(cycle=='Y');
	Print_exit_info(win_time,lose_time);
	system("pause");
	return 0;
}
