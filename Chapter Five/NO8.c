/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
/* NO8.c (Chapter 5, page 68) */
#define _CRT_SECURE_NO_DERECATE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int input_number,first_digit,second_digit;
	bool checkpoint;
	//input
	checkpoint=true;
	while (checkpoint)
	{
		printf("Enter a two-digit number: ");
	    scanf("%d",&input_number);
		if (input_number<0||input_number>99) {printf("Input Error,please try again.\n");system("pause");}
		else checkpoint=false;
	}
	//output
	printf("Your entered the number ");
	if (input_number<=19)
		switch (input_number) //0-19
	    {
			case  0:printf("zero");     break;
			case  1:printf("one");      break;
			case  2:printf("two");      break;
			case  3:printf("three");    break;
			case  4:printf("four");     break;
			case  5:printf("five");     break;
			case  6:printf("six");      break;
			case  7:printf("seven");    break;
			case  8:printf("eight");    break;
			case  9:printf("nine");     break;
			case 10:printf("ten");      break;
			case 11:printf("eleven");   break;
			case 12:printf("twelve");   break;
			case 13:printf("thirteen"); break;
			case 14:printf("forteen");  break;
			case 15:printf("fifteen");  break;
			case 16:printf("sixteen");  break;
			case 17:printf("seventeen");break;
			case 18:printf("eighteen"); break;
			case 19:printf("ninteen");  break;
		}
    else
	    {
			first_digit=input_number/10;second_digit=input_number%10;
			switch (first_digit)
			{
				case 2:printf("twenty"); break;
				case 3:printf("thirty"); break;
				case 4:printf("forty");  break;
				case 5:printf("fifty");  break;
				case 6:printf("sixty");  break;
				case 7:printf("seventy");break;
				case 8:printf("eighty"); break;
				case 9:printf("ninty");  break;
			}
			switch (second_digit)
			{
				case 0:              ;      break;
				case 1:printf("-one");      break;
			    case 2:printf("-two");      break;
			    case 3:printf("-three");    break;
		    	case 4:printf("-four");     break;
			    case 5:printf("-five");     break;
		     	case 6:printf("-six");      break;
		    	case 7:printf("-seven");    break;
		   	    case 8:printf("-eight");    break;
		    	case 9:printf("-nine");     break;
			}
		}
	printf("\n");
	
	//pause
	system("pause");
	return 0;
}