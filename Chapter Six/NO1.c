/*********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
*********************************************************/
/* NO1.c (Chapter 6, page 85) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf*/
#include <stdlib.h> /*system*/
#include <stdbool.h> /*bool true false*/
/*******************
 *#define Bool int *
 *typedef int Bool;*
 *******************/

int main(void)
{
	float input_data, largest = 0.0f;
	printf("This program is used to caculate the largest number you entered.\n");
	do
	{
		printf("Enter a number:");
		scanf("%f", &input_data);
		if (input_data>largest)               
			largest = input_data;
	} while (input_data>0);
	if (largest == 0) printf("Input Error!");
	else printf("The largest number entered was %-5.2f\n", largest);

	system("pause");
	return 0;
}