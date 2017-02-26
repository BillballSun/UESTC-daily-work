/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
/* NO6.c (Chapter 5, page 68) */
#define CRT_SECURE_NO_DEPERCATE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int year1,year2,month1,month2,day1,day2,p;
	printf("Enter  first date (mm/dd/yy):");
	scanf("%d/%d/%d",&month1,&day1,&year1);
	printf("Enter second date (mm/dd/yy):");
	scanf("%d/%d/%d",&month2,&day2,&year2);
	     if (year1<>year2)   p=year1>year2?1:2;
	else if (month1<>month2) p=month1>month2?1:2;
	else if (day1<>day2)     p=day1>day2?1:2;
	else                     p=0;
	switch (p)
	{
		case 1:printf("%2d/%-2.2d/%4d is earlier than %2d/%-2.2d/%4d\n",month2,day2,year2,month1,day1,year1);break;
		case 2:printf("%2d/%-2.2d/%4d is earlier than %2d/%-2.2d/%4d\n",month1,day1,year1,month2,day2,year2);break;
		case 0:printf("They are definetely equal.\n");break;
	}
	
	system("pause");
	return 0;
}