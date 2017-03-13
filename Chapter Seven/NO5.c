/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
*********************************************************/
/* NO8.c (Chapter 6, page 86) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf getchar putchar*/
#include <stdlib.h> /*system abs*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper*/
#include <math.h> /*sqrt*/
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*******************
*#define Bool int *
*typedef int Bool;*
*******************/

int main(void)
{
	bool checkpoint;
	int total;
	unsigned char h;
	do
	{
		printf("Enter a word:");
	    checkpoint=false;total=0;
	    while(!checkpoint&&((h=getchar())!='\n'))
	    {
	    	h=toupper(h);/*if (h<='z') h=h-'a'+'A';*/
	    	switch (h)
		    {
			    case 'A':case 'E':case 'I':case 'L':case 'N':case 'O':case 'R':case 'S':case 'T':case 'U':
			    total=total+1;break;
			    case 'D':case 'G':
			    total=total+2;break;
		    	case 'B':case 'C':case 'M':case 'P':
		    	total=total+3;break;
		    	case 'F':case 'H':case 'V':case 'W':case 'Y':
		    	total=total+4;break;
		    	case 'K':
		    	total=total+5;break;
		    	case 'J':case 'X':
		    	total=total+8;break;
		    	case 'Q':case 'Z':
		    	total=total+10;break;
		    	default:checkpoint=true;
				        printf("Input Error, please try again with your dump mind.\n");
						while((h=getchar())!='\n') continue;
						break;
		    }
	    }
	}while(checkpoint);
	printf("Scrabble value: %d\n",total);
	
	system("pause");
	return 0;
}