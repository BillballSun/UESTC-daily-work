/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
/* NO7.c (Chapter 5, page 68) */
#define _CRT_SECURE_NO_DEPERCATE /*Before all the includes*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int grade;
	_Bool checkpoint;
	checkpoint=true;
	//Input
	while (checkpoint)
	{
		printf("Enter numerical grade:");
     	scanf("%d",&grade);
	         if (grade<0||grade>100) {printf("Input Error,please try again\n");system("pause");}
		else if checkpoint=false;
	}
	//Output
	printf("Letter grade: ");
	switch (grade/10)
	{
		case 10: case 9:printf("A");break;
		case  8:        printf("B");break;
		case  7:        printf("C");break;
		case  6:        printf("D");break;
		default:        printf("F");//Don't wanna a break.....
	}
	printf("\n");
	//Pause
	system("pause");
	return 0;
}