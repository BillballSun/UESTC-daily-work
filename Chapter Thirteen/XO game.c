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
/*********************************************
 *system("chcp 437>nul.");Show ASCII extended*
**********************************************/
void Print_divide_line(void);
int Select_import_way(void);
void Get_rid_of_RestLine(void);
void Get_row_col(int *,int *,int);

int main(int argc, int argv[])
{
	void Show_start_info(void),Show_exit_info(void);
	bool Play_XO(int,bool),cycle,Select_your_symbol(void);
	/*Return if cycle*/
	Show_start_info();
	srand((unsigned)time(NULL));
	int import_way=Select_import_way();
	bool now_is_X=Select_your_symbol();
	do
	{
		cycle=Play_XO(import_way,now_is_X);
	}while(cycle);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

bool Select_your_symbol(void)
{
	unsigned char ch='\0';
	/*No useful, just my own habbit*/
	printf("Please enter X or O to select your side.\n");
	do
	{
		printf("Enter your selection:");
		ch=toupper(getchar());
		if (ch!='\n') Get_rid_of_RestLine();
	}while(ch!='O'&&ch!='X');
	printf("\n");
	return ch=='X';
}

bool Play_XO(int import_way,bool now_is_X)
{
	char board[3][3];
	void Input_data(char (*)[3],int,bool,unsigned short),Show_this_time(char (*)[3]),Show_win_info(int,bool);
	void Computer_data(char (*)[3],bool);
	int Tell_situation(char const(*)[3]);
	bool Is_try_again(void),Is_go_firest(void);
	bool go_first=Is_go_firest();
	unsigned short step_time=1;
	for(char *board_point=*board;board_point<=*board+3*3-1;board_point++)
		*board_point='.';
	/*situation
	 *0 continue
	 *1 X win
	 *2 O win
	 *3 draw
	 */
	int situation;
	printf("******************************************************\n");
	printf("*           Welcome to X and O game                  *\n");
	printf("******************************************************\n");
	printf("Auto generating result is ");
	if (go_first) printf("you"); else printf("computer");
	printf(" go first.\n");
	do
	{
		switch(go_first)
		{
			case true:
			Print_divide_line();
		    Show_this_time(board);
		    printf("\n");
			Input_data(board,import_way,now_is_X,step_time);
			situation=Tell_situation(board);
			if (situation==0) Computer_data(board,now_is_X);
			break;
			case false:
			Computer_data(board,now_is_X);
			situation=Tell_situation(board);
			if (situation==0)
			{
				Print_divide_line();
		        Show_this_time(board);
		        printf("\n");
			    Input_data(board,import_way,now_is_X,step_time);
			}break;
		}
		step_time=step_time+1;
		situation=Tell_situation(board);
	}while(situation==0);
	Print_divide_line();
	Show_this_time(board);
	Show_win_info(situation,now_is_X);
	return Is_try_again();
}

void Computer_data(char (*board)[3],bool now_is_X)
{
	bool accept_place[9]={false};
	int position_now=0;
	for(int i=0;i<=2;i++)
		for(int ii=0;ii<=2;ii++)
		{
			if(board[ii][i]=='.') accept_place[position_now]=true;
			position_now++;
		}
	int random_amount=0;
	for(int i=0;i<=8;i++)
		if (accept_place[i]) random_amount=random_amount+1;
	int get_rand=rand()%random_amount+1;
	int where_to_put=0;
	while(get_rand>0)
	{
		where_to_put++;
		if (accept_place[where_to_put-1]) get_rand--;
	}
	int row,col;
	Get_row_col(&row,&col,where_to_put);
	/*board[ROW][COL]
	*-------ROW-------
    *-
	*-
	*COL
	*-
	*-
	*/
	*(*(board+row)+col)=(now_is_X?'O':'X');
}

bool Is_go_firest(void)
{
	return rand()%2;
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

void Show_win_info(int situation,bool now_is_X)
{
	printf("\n");
	switch(situation)
	{
		case 1:
		printf("Congratulations for X, ");
		if (now_is_X) printf("player wins.\n");
		else printf("computer wins.\n");
		break;
		case 2:
		printf("Congratulations for O, ");
		if (now_is_X) printf("computer wins.\n");
		else printf("player wins.\n");
		break;
		case 3:printf("Congratulations for both of you, you draw.\n");break;
	}
	printf("\n");
}

void Show_this_time(char (*board)[3])
{
	
	printf("Board Now as follow\n");
	for(int i=0;i<=2;i++)
	{
		for(int ii=0;ii<=2;ii++)
			printf("%c",board[ii][i]);
		printf("\n");
	}
}

 
/*A 1
 *B 2
 *C 3
 *true way to identify in program
 */

/*selection A           selection B           selection C
 *EASY__________________MOBILE________________KEYBOARD
 *0 1 2                 1 2 3                 7 8 9
 *3 4 5                 4 5 6                 4 5 6
 *6 7 8                 7 8 9                 1 2 3
 *                  true to identify
 */

void Input_data(char (*board)[3],int import_way, bool now_is_X,unsigned short step_time)
{
	unsigned char ch;
	void Show_th(int);
	int Get_enter_place_C(int),enter_place,row,col;
	bool enter_right;
	do
	{
		enter_right=true;
		printf("Now it\'s the %hu",step_time);
		Show_th(step_time);
		printf(" step for player as ");
		if (now_is_X) putchar('X'); else putchar('O');
		printf(" to go, enter your place:");
		ch=getchar();
		if (ch!='\n') Get_rid_of_RestLine();
		switch(import_way)
		{
			case 1:
			if (ch>='0'&&ch<='8') enter_place=ch-'0'+1; else enter_right=false;
			break;
			case 2:
			if (ch>='1'&&ch<='9') enter_place=ch-'0'; else enter_right=false;
			break;
			case 3:
			if (ch>='1'&&ch<='9') enter_place=Get_enter_place_C((int)(ch-'0')); else enter_right=false;
			break;
		}
		if (!enter_right) printf("Error, illegal enter.\n");
		else
		{
			/*board[ROW][COL]
			 *-------ROW-------
			 *-
			 *-
			 *COL
			 *-
			 *-
			 */
			Get_row_col(&row,&col,enter_place);
			if (*(*(board+row)+col)!='.') {enter_right=false;printf("Error, already taken place.\n");}
		}
	}while(!enter_right);
	*(*(board+row)+col)=(now_is_X?'X':'O');
}

void Get_row_col(int *row, int *col,int enter_place)
{
	*col=(enter_place-1)/3;
	*row=(enter_place-1)%3;
}

/*selection A           selection B           selection C
 *EASY__________________MOBILE________________KEYBOARD
 *0 1 2                 1 2 3                 7 8 9
 *3 4 5                 4 5 6                 4 5 6
 *6 7 8                 7 8 9                 1 2 3
 */
 
int Get_enter_place_C(int n)
{
	if (n<=3) return n+6;
	if (n<=6) return n;
	return n-6;
}

void Show_th(int n)
{
	char *th_words[]={"st","nd","rd","th"};
	switch(n%10)
	{
		case 1:printf("%s",*th_words);break;
		case 2:printf("%s",*(th_words+1));break;
		case 3:printf("%s",*(th_words+2));break;
		default:printf("%s",*(th_words+3));break;
	}
}

int Tell_situation(char const (*a)[3])
{
	/*situation
	 *0 continue
	 *1 X win
	 *2 O win
	 *3 draw
	 */
	for(int i=0;i<=2;i++)
		if (a[i][0]!='.'&&a[i][0]==a[i][1]&&a[i][0]==a[i][2]) return (a[i][0]=='X')?1:2;
	for(int i=0;i<=2;i++)
		if (a[0][i]!='.'&&a[0][i]==a[1][i]&&a[0][i]==a[2][i]) return (a[0][i]=='X')?1:2;
	if (a[0][0]!='.'&&a[0][0]==a[1][1]&&a[0][0]==a[2][2]) return (a[1][1]=='X')?1:2;
	if (a[0][2]!='.'&&a[0][2]==a[1][1]&&a[0][2]==a[2][0]) return (a[1][1]=='X')?1:2;
	bool full=true;
	for(int i=0;i<=2;i++)
		for(int ii=0;ii<=2;ii++)
			if (a[i][ii]=='.') full=false;
	if (full) return 3; else return 0;
}

void Show_start_info(void)
{
	printf("------------Stupid boring X and O game---------------\n");
	printf("Copyright (c)   2016, 1998  Victor Ding Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("When I ask my teacher how do X and O game play.\n");
	printf("He sayed what a stupid boy, just look on wikipedia.\n");
	printf("So to hand in this boring easy game homework.\n");
	printf("NO WORDS TO SAY.\n");
	printf("https://en.wikipedia.org/wiki/Tic-tac-toe\n");
	Print_divide_line();
}

void Show_exit_info(void)
{
	Print_divide_line();
	printf("Copyright (c) 2016, 1998     Victor Ding Incorperated.\n");
	printf("The way it is meant to be played.\n");
	printf("See you next time.\n");
}

int Select_import_way(void)
{
	int Get_selection(void);
	printf("Please input A or B or C to select your way of playing.\n");
	printf("selection A           selection B           selection C\n");
	printf("EASY__________________MOBILE________________KEYBOARD\n");
	printf("0 1 2                 1 2 3                 7 8 9\n");
	printf("3 4 5                 4 5 6                 4 5 6\n");
	printf("6 7 8                 7 8 9                 1 2 3\n");
	return Get_selection();
}

int Get_selection(void)
{
	unsigned char ch='\0';
	/*No useful, just my own habbit*/
	do
	{
		printf("Enter your selection:");
		ch=toupper(getchar());
		if (ch!='\n') Get_rid_of_RestLine();
	}while(ch!='A'&&ch!='B'&&ch!='C');
	printf("\n");
	return (int)(ch-'A'+1);
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while((ch=getchar())!='\n') continue;
}
