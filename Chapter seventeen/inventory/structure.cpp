#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "control.h"

#include "structure.h"

bool Get_Y_or_N(char *info)
{
	char ch;
	do
	{
		printf("%s(Y/N)--", info);
		ch = Get_a_upper_letter();
	} while (ch != 'Y'&&ch != 'N');
	#ifdef Enable_print_small_line_after_Y_or_N
	Print_small_line();
	#endif
	return ch == 'Y';
}

char Get_a_upper_range(char begin, char end ,char *option ,char *message)
{
	char ch;
	do
	{
		printf("%s\n",option);
		printf("%s",message);
		ch = Get_a_upper_letter();
		Print_small_line();
	} while (ch<begin || ch>end);
	return ch;
}

char Get_a_upper_letter(void)
{
	char ch;
	if ((ch = toupper(getchar())) != '\n') Get_rid_of_RestLine();
	return ch;
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

void Print_small_line(void)
{
	printf("-----------------------\n");
}
