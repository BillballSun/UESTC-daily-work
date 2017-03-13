/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
*********************************************************/
/* NO9.c (Chapter 7, page 111) */
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
	int hour,minute,hour_add;
	bool checkpoint;
	unsigned char ch;
	do
	{
		checkpoint=false;hour=-1;minute=-1;
		printf("Enter a 12-hour time:");
	    scanf("%d:%d ",&hour,&minute);
		if (hour<0||hour>12) {checkpoint=true;printf("Error, the time of hour flows\n");}
		if (minute<0||minute>59) {checkpoint=true;printf("Error, the time of minute flows\n");}
    	if ((ch=getchar(),ch=toupper(ch))=='P') hour_add=12;
    	else if (ch=='A') hour_add=0;
	    else {checkpoint=true;printf("Error, AM/PM not detected.\n");}
    	if (!checkpoint) 
		{
			ch=getchar(),ch=toupper(ch);
			if (ch!='M') {checkpoint=true;printf("Error, AM/PM not detected.\n");}
		}
		if (checkpoint) printf("Please try again.\n");
		while((ch=getchar())!='\n') continue;
	}while (checkpoint);
	printf("In 24-hour time, it is: %d:%d.\n",hour+hour_add,minute);
	
	system("pause");
	return 0;
}