#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include "structure.h"
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

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while((ch=getchar())!='\n') continue;
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}