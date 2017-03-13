/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By Bill Sun                                           *
 * Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
 * All rights reserved.                                  *
 * This program may  not be freely distributed,          *
 * provided that this copyright notice is retained.      *
 *********************************************************/
/* NO10.c (Chapter 7, page 111) */
#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf getchar putchar*/
#include <stdlib.h> /*system abs(int)*/
#include <stdbool.h> /*bool true false*/
#include <ctype.h> /*toupper*/
#include <math.h> /*sqrt fabs(double)*/
#include <iostream> /*C++ input and output*/
using namespace std; /*C++ cout cin*/
/*********************
 * #define Bool int  *
 * typedef int Bool; *
 *********************/
 
 int main(void)
 {
	 int total_carpet,caculate_point_x,caculate_point_y,result_number;
	 int x_point,y_point,x_length,y_length;
	 bool checkpoint;
	 unsigned char ch;
	 do
	 {
		 checkpoint=false;total_carpet=-1;
		 printf("How many carpet do you wanna caculate:");
	     scanf("%d",&total_carpet);
	     while((ch=getchar())!='\n') continue;
		 if (total_carpet<=0) {checkpoint=true;printf("Error, wrong carpet number.\n");}
		 else
		 {
			 do
			 {
		    	 caculate_point_x=caculate_point_y=-1;
				 printf("Please input the position you wanna caculate(x y):");
			     scanf("%d%d",&caculate_point_x,&caculate_point_y);
				 while((ch=getchar())!='\n') continue;
			 }while(!(caculate_point_x>=0&&caculate_point_y>=0));
		 }
	 }while(checkpoint);
	 printf("Please input %d carpets\' data for (x,y) and (x_length,y_length).\n",total_carpet);
	 result_number=-1;
	 for(int i=1;i<=total_carpet;i++)
	     do
		 {	 
		     checkpoint=false;
			 x_point=y_point=x_length=y_length=-1;
		     printf("Enter the %d",i);
			 switch (i%10)
		     {
			     case 1:printf("st");break;
			     case 2:printf("nd");break;
			     case 3:printf("rd");break;
			     default:printf("st");break;
		     }
			 printf(" carpet's data:");
		     scanf("%d%d%d%d",&x_point,&y_point,&x_length,&y_length);
			 while((ch=getchar())!='\n') continue;
		     if (x_point<=-1||y_point<=-1||x_length<=0||y_length<=0)
		     {
			     printf("Error, carpet data is not accepted.\n");
			     checkpoint=true;
		     }
			 else if (caculate_point_x>=x_point&&caculate_point_x<=(x_point+x_length))
				      if (caculate_point_y>=y_point&&caculate_point_y<=(y_point+y_length))
				          result_number=i;
	     }while(checkpoint);
	 if (result_number==-1) printf("Nothing found on that point.\n");
	 else
	 {
		 printf("The %d",result_number);
		 switch (result_number%10)
		 {
			 case 1:printf("st");break;
			 case 2:printf("nd");break;
			 case 3:printf("rd");break;
			 default:printf("st");break;
		 }
		 printf(" carpet wins this boring battle.\n");
	 }
	 system("pause");
	 return 0;
 }