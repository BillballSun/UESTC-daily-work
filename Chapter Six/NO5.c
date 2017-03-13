/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
*********************************************************/
/* NO5.c (Chapter 6, page 85) */
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
	int i=1,n;
	printf("Please input n to continue:");
	scanf("%d",&n);
	for ( ;i++,i<=n; )
		if (i%2==0) printf("%d\n",i*i);
	
	system("pause");
	return 0;
}