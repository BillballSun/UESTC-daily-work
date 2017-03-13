#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdbool.h>

#include "structure_function.h"

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while((ch=getchar())!='\n') continue;
}

void Print_small_line(void)
{
	printf("-----------------------\n");
}
