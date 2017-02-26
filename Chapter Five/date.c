//Empty Program
#define CRT_SECURE_NO_DEPERATE //do not check scanf
#include <stdio.h> //include printf scanf
#include <stdlib.h>  //include system
#include <stdbool.h> //include bool true false

int main(void)
{
	int year,month,date;
	printf("Enter data(mm/dd/yy):");
	scanf("%d/%d/%d",&month,&date,&year);
	printf("Dated this %d",date);
	switch (date%10) /*date is integer and date>=1*/
	{
		 case 1:printf("st");break;
		 case 2:printf("nd");break;
		 case 3:printf("rd");break;
		default:printf("st");break;
	}
	printf(" day of ");
	switch (month) /*1<=month<=12 and it is an int*/
	{
		 case  1:printf("Janurary"); break;
		 case  2:printf("Febrary");  break;
		 case  3:printf("March");    break;
		 case  4:printf("April");    break;
		 case  5:printf("May");      break;
		 case  6:printf("June");     break;
		 case  7:printf("July");     break;
		 case  8:printf("August");   break;
		 case  9:printf("September");break;
		 case 10:printf("October");  break;
		 case 11:printf("November"); break;
		 case 12:printf("December"); break;
	}
	printf(", %d.\n",year);
	system("pause");
	return 0;
}