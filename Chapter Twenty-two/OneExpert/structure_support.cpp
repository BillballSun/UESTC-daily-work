#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "structure_support.h"

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

void Print_small_line(void)
{
	printf("-----------------------\n");
}

void Get_rid_of_RestLine(void)
{
	while(getchar()!='\n') continue;
}

bool Safe_read_name(char *s,int n)
//Empty word return false, true means at least one letter read.
{
	char ch;
	while(isspace(ch=getchar())&&ch!='\n') continue;
	if(ch=='\n')
	{
		*s='\0';
		return false;
	}
	do
	{
		*s++=ch;
		n--;
		ch=getchar();
	}while(ch!='\n'&&n>0);
	if(ch!='\n') Get_rid_of_RestLine();
	*s='\0';
	return true;
}

char Get_a_upper_range(char *main_massage,char *input_show, char *range)
{
	char ch;
	bool find_match=false;
	char *p;
	printf("%s\n", main_massage);
	do
	{
		printf("%s:", input_show);
		if((ch = toupper(getchar()))!='\n') Get_rid_of_RestLine();
		p = range;
		while (*p)
			if (toupper(*p++) == ch) find_match = true;
	} while (!find_match);
	return ch;
}
