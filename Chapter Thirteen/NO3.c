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
/*****************Sample structure start*****************
void Show_start_info(void);
void Show_exit_info(void);
void Print_divide_line(void);
void Safe_read_word(char *,int);
void Get_rid_of_RestLine(void);
void Show_st(int);
bool Is_try_again(void);
======Modify indicator======
void main_program(void);

int main(int argc, int argv[])
{
	bool cycle;
	Show_start_info();
	do
	{
		main_program();
		cycle=Is_try_again();
	}while(cycle);
	system("pause");
	return EXIT_SUCCESS;
}

======Modify indicator======
void main_program(void)
{
	
}

void Show_start_info(void)
{
	printf("------------Amazing Splitting program---------------\n");
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
		printf("Another game(Y/N)?-------");
	    ch=toupper(getchar());
		if (ch!='\n') Get_rid_of_RestLine();
	}while(!(ch=='Y'||ch=='N'));
	return ch=='Y';
}

bool Safe_read_word(char *s,int len)
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
	*s='\0'
	return true;
}
*****************Sample structure end*******************/
/*
//NO 3 Chapter Eight
#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
  int num_cards, rank, suit;
  const char rank_code[] = {'2','3','4','5','6','7','8',
                            '9','t','j','q','k','a'};
  const char suit_code[] = {'c','d','h','s'};

  srand((unsigned) time(NULL));

  printf("Enter number of cards in hand: ");
  scanf("%d", &num_cards);

  printf("Your hand:");
  while (num_cards > 0) {
    suit = rand() % NUM_SUITS;     //picks a random suit
    rank = rand() % NUM_RANKS;     //picks a random rank
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = true;
      num_cards--;
      printf(" %c%c", rank_code[rank], suit_code[suit]);
    }
  }
  printf("\n");

  return 0;
}
*/

/*heart
 *diamond    tile
 *spade      pike
 *club       clover
 *
 *Order as bellow
 *Ace
 *Rank two to ten
 *Jack
 *Queen
 *King
**/

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
  int num_cards, rank, suit;
  const char *rank_code[] = {"Two","Three","Four","Five","Six","Seven","Eight",
                            "Nine","Ten","Jack","Queen","King","Ace"};
  const char *suit_code[] = {"club","diamond","heart","spade"};

  srand((unsigned) time(NULL));

  printf("Enter number of cards in hand: ");
  scanf("%d", &num_cards);

  printf("Your hand:\n");
  while (num_cards > 0) {
    suit = rand() % NUM_SUITS;     //picks a random suit
    rank = rand() % NUM_RANKS;     //picks a random rank
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = true;
      num_cards--;
      printf(" %5s of %s\n", rank_code[rank], suit_code[suit]);
    }
  }
  printf("\n");
  system("pause");
  return EXIT_SUCCESS;
}
