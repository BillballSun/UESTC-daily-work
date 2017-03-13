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
#include <stdio.h> /*scanf printf*/
#include <stdlib.h> /*system abs*/
#include <stdbool.h> /*bool true false*/
/*******************
*#define Bool int *
*typedef int Bool;*
*******************/

int main(void)
{
	unsigned long long int under=1ull;
	long double e=1.0l,accurency;
	bool checkpoint=false;
	do
	{
		printf("Please input \xeb as the accurency:");
	    scanf("%Lf",&accurency);
		if (accurency<0) printf("Input error, please try again with your silly mind.\n");
		else checkpoint=true;
	}
	while (!checkpoint);
	for(int i=1;(1.0l/(long double)under)>accurency;i++)
	{
		under=under*i;
		e=e+1.0l/(long double)under;
	}
	printf("e= %Lf\n",e);
	
	system("pause");
	return 0;
}

/*
int main(void){unsigned long long int under = 1ull;long double e = 1.0l, accurency;bool checkpoint = false;
do{printf("Please input \xeb as the accurency:"), scanf("%Lf", &accurency);
if (accurency<0) printf("Input error, please try again with your silly mind.\n"); else checkpoint = true;
} while (!checkpoint);
for (int i = 1; under = under*i, (1.0l / (long double)under)>accurency; e = e + 1.0l / (long double)under, i++) continue;
printf("e= %Lf\n", e), system("pause");return 0;}
*/