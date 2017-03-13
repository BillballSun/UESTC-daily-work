#include <stdio.h>
#include <stdbool.h>
#include "structure.h"

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

void Print_small_line(void)
{
	printf("---------------------------\n");
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while((ch=getchar())!='\n') continue;
}

void Show_st(int x)
{
	switch(x%10)
	{
		case 1:printf("st");break;
		case 2:printf("nd");break;
		case 3:printf("rd");break;
		default:printf("th");break;
	}
}

bool Is_try_again(void)
{
	unsigned char ch;
	do
	{
		printf("Another chance(Y/N)?-------");
	    ch=toupper(getchar());
		if (ch!='\n') Get_rid_of_RestLine();
	}while(!(ch=='Y'||ch=='N'));
	return ch=='Y';
}
