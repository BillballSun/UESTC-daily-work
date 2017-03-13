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

/*
*color cdhs
*sort  23456789tjqka
*/

bool all_card[4][13];
unsigned short card_inhand[5][2];

void Print_start_info(void);
void Main_cycle(void);
void Print_exit_info(void);
bool Read_card(void);
void Show_result(void);
int Card_up(unsigned char);
int Card_down(unsigned char);
void Get_rid_of_RestLine(void);
void Show_warning(short);
void Print_divide_line(void);
bool Is_straight(void);
bool Is_flush(void);
bool Is_four(void);
bool Is_full_house(void);
bool Is_three_color_same(void);
short Get_pairs(void);
void Get_color_order(unsigned short []);
void Get_amount_order(unsigned short []);
void Sort_order(unsigned short []);
void Show_entered_order(unsigned short);

int main(void)
{
	Print_start_info();
	Main_cycle();
	Print_exit_info();
	system("pause");
	return 0;
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

void Print_start_info(void)
{
	printf("------------Amazing Card choosing game---------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Play:\n");
	printf(" Color: cdhs\n");
	printf("Amount: 23456789tjqka\n");
	printf(" First: Enter five card with form like c2,sj,hk...\n");
	printf("  Then: Program will tell the largest combination.\n\n");
	printf("Combination order:\n");
	printf("Straight Flash, Four of a kind, Full house\n");
	printf("Flush, Straight, Three of a kind, Two pair\n");
	printf("High card(somehow the lowest with a sweet name)\n");
	Print_divide_line();
}

void Print_exit_info(void)
{
	Print_divide_line();
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be played.\n");
	printf("See you next time.\n");
}

void Main_cycle(void)
{
	bool exit_point=false;
	do
	{
		for(int i=0;i<=3;i++)
			for(int ii=0;ii<=12;ii++)
				all_card[i][ii]=false;
		/*
		for(int i=0;i<=4;i++)
			for(int ii=0;ii<=1;ii++)
				card_inhand[i][ii]=0;
		Useless
		*/
		exit_point=Read_card();
		if (!exit_point) Show_result();
	}while(!exit_point);
}

/*Support exit_point return*/
bool Read_card(void)
{
	unsigned short point=0;
	unsigned char ch1,ch2;
	/*
	 *-1 exit
	 *0 nothing
	 *1 bad card
	 *2 repeat card
	 */
	short warning;
	do
	{
		warning=0;
		Show_entered_order(point);
		ch1=getchar();
		if (ch1=='\n') warning=1;
		else if (ch1=='0') {Get_rid_of_RestLine();warning=-1;point=5;}
		else if (Card_up(ch1)==-1) {warning=1;Get_rid_of_RestLine();}
		else
		{
			ch2=getchar();
			if (ch2=='\n') warning=1;
			else
			{
				if (Card_down(ch2)==-1) warning=1;
				else if (all_card[Card_up(ch1)][Card_down(ch2)]) warning=2;
				else
				{
					all_card[Card_up(ch1)][Card_down(ch2)]=true;
					card_inhand[point][0]=Card_up(ch1);
					card_inhand[point][1]=Card_down(ch2);
					point=point+1;
				}
				Get_rid_of_RestLine();
			}
		}
		Show_warning(warning);
	}while(point<=4);
	return warning==-1;
}

void Show_entered_order(unsigned short point)
{
	point=point+1;
	printf("Please enter the %hu",point);
	switch(point%10u)
	{
		case 1:printf("st");break;
		case 2:printf("nd");break;
		case 3:printf("rd");break;
		default:printf("st");break;
	}
	printf(" card:");
}

int Card_up(unsigned char ch1)
{
	/*cdhs*/
	int result;
	ch1=toupper(ch1);
	switch(ch1)
	{
		case 'C':result=0;break;
		case 'D':result=1;break;
		case 'H':result=2;break;
		case 'S':result=3;break;
		default:result=-1;break;
	}
	return result;
}

int Card_down(unsigned char ch2)
{
	/*23456789tjqka*/
	int result;
	ch2=toupper(ch2);
	if (ch2>=2&&ch2<='9') result=ch2-'2';
	else switch(ch2)
	{
		case 'T':result=8;break;
		case 'J':result=9;break;
		case 'Q':result=10;break;
		case 'K':result=11;break;
		case 'A':result=12;break;
		default:result=-1;break;
	}
	return result;
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while ((ch=getchar())!='\n') continue;
}

void Show_warning(short warning)
{
	switch(warning)
	{
		case -1:printf("Detected zero, default to exit program.\n");break;
		case 1:printf("Unaccepted card, ignore it.\n");break;
		case 2:printf("Opp, card repeated, ignore it.\n");break;
	}
}

void Show_result(void)
{
	bool straight,flush,four,three_color_same,full_house;
	short pairs;
	straight=Is_straight();
	flush=Is_flush();
	four=Is_four();
	full_house=Is_full_house();
	three_color_same=Is_three_color_same();
	pairs=Get_pairs();
	/*
	 *Straight Flush, Four of a kind, Full house
	 *Flush, Straight, Three of a kind, Two pair
	 *High card(somehow the lowest with a sweet name)
	 */
    printf("\n");
	if (straight&&flush) printf("You get Straight Flush, what some nice cards.");
	else if (four) printf("Ha, Four of a kind, not bad.");
    else if (full_house) printf("Oh, Full house, it\'s OK.");
	else if (flush) printf("Ah, you get a flush.");
	else if (straight) printf("Straight, seems not easy to stop.");
	else if (three_color_same) printf("Lala, three of a kind.");
	else if (pairs==2) printf("Just two pairs.");
	else printf("You know high card?");
	printf("\n\n");
}

bool Is_straight(void)
{
	unsigned short order[5];
	bool result;
	Get_amount_order(order);
	Sort_order(order);
	result=true;
	for(int i=0;i<=3;i++)
		if(order[i]+1!=order[i+1]) result=false;
	return result;
}

void Get_color_order(unsigned short order[5])
{
	for(int i=0;i<=4;i++)
		order[i]=card_inhand[i][0];
}

void Get_amount_order(unsigned short order[5])
{
	for(int i=0;i<=4;i++)
		order[i]=card_inhand[i][1];
}

void Sort_order(unsigned short order[5])
{
	for(int i=4-1;i>=0;i--)
		for(int ii=0;ii<=i;ii++)
			if(order[ii]>order[ii+1])
			{
				unsigned short temp;
				temp=order[ii];
				order[ii]=order[ii+1];
				order[ii+1]=temp;
			}
}

bool Is_flush(void)
{
	bool result;
	result=true;
	for(int i=1;i<=4&&result;i++)
		if(card_inhand[i][0]!=card_inhand[0][0])
			result=false;
	return result;
}

bool Is_four(void)
{
	unsigned short order[5];
	bool result;
	Get_amount_order(order);
	Sort_order(order);
	result=false;
	for(int i=0;i<=4-3&&!result;i++)
		if (order[i]==order[i+1]&&order[i]==order[i+2])
			if(order[i]=order[i+3])
				result=true;
	return result;
}

bool Is_full_house(void)
{
	unsigned short order[5][2];
	bool result;
	/*Get color and amount order*/
	for(int i=0;i<=4;i++)
		for(int ii=0;ii<=1;ii++)
			order[i][ii]=card_inhand[i][ii];
	/*Sort order by color*/
	for(int i=4-1;i>=0;i--)
		for(int ii=0;ii<=i;ii++)
			if(order[ii][0]>order[ii+1][0])
			{
				unsigned short temp[2];
				temp[0]=order[ii][0];
				temp[1]=order[ii][1];
				order[ii][0]=order[ii+1][0];
				order[ii][1]=order[ii+1][1];
				order[ii+1][0]=temp[0];
				order[ii+1][1]=temp[1];
			}
	/*Check whether full house*/
	result=false;
	for(int i=0;i<=4-2&&!result;i++)
		if(order[i][0]==order[i+1][0]&&order[i][0]==order[i+2][0])
		{
			int order_rest_down[5-3];
			int point=0,t=0;
			unsigned short rest_amount_order[5-3];
			while(point<=5-3-1)
			{
			    if(t<i||t>i+2) {order_rest_down[point]=t;point=point+1;}
				t=t+1;
			}
			for(int i=0;i<=5-3-1;i++)
				rest_amount_order[i]=order[order_rest_down[i]][1];
			for(int i=0;i<=5-3-1-1&&!result;i++)
				if (rest_amount_order[i]==rest_amount_order[i+1]) result=true;
		}
	return result;
}

bool Is_three_color_same(void)
{
	unsigned short order[5];
	bool result;
	Get_color_order(order);
	Sort_order(order);
	result=false;
	for(int i=0;i<=4-2&&!result;i++)
		if(order[i]==order[i+1]&&order[i]==order[i+2]) result=true;
	return result;
}

short Get_pairs(void)
{
	unsigned short order[5];
	short result;
	Get_amount_order(order);
	Sort_order(order);
	int i=0;result=0;
	while(i<=4-1)
	{
		if(order[i]==order[i+1]){result=result+1;i=i+2;}
		else i=i+1;
	}
	return result;
}
