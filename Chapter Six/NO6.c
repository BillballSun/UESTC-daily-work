/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
*********************************************************/
/* NO6.c (Chapter 6, page 85) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf*/
#include <stdlib.h> /*system abs*/
#include <stdbool.h> /*bool true false*/
/*******************
*#define Bool int *
*typedef int Bool;*
*******************/

int main(void)
{
	short unsigned int number_month,start_day,i,turn;
	bool checkpoint=false;
	do
	{
		printf("Enter number of days in month:");
	    scanf("%hu",&number_month);
	    printf("Enter starting day of the week(1=Sun, 7=Sat):");
    	scanf("%hu",&start_day);
		if (number_month>=28&&number_month<=31&&start_day>=1&&start_day<=7)
			checkpoint=true;
		else printf("Input Error,please try again with your silly mind.\n");
	}
	while(!checkpoint);
	for(i=1;i<start_day;i++)
		printf("   ");
	for(turn=start_day-1,i=1;i<=number_month;i++)
	{
		printf("%2hu",i);
		if ((turn=(turn+1)%7)==0) printf("\n"); else printf(" ");
	}
	printf("\n");
	
	system("pause");
	return 0;
}