/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
*********************************************************/
/* NO11.c (Chapter 6, page 86) */
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
	unsigned long long int n,under=1;
	long double data=1.0l;
	printf("Please input n to caculate e:");
	scanf("%llu",&n);
	for(int i=1;i<=n;i++)
	{
		under=under*i;
		data=data+(long double)1/(long double)under;
	}
	printf("e= %Lf\n",data);
	
	system("pause");
	return 0;
}