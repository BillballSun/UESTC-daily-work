#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf getchar putchar*/
#include <ctype.h> /*toupper tolower isalpha isupper islower*/
#include "line.h"
#include "max_limit.h"
//#define Max__line_length 60
void Flush_line(char *present_line, int line_length, int word_amount)
{
	if(word_amount==1) puts(present_line);
	else
	{
		int extra_space=Max_line_length-line_length,
	    common_each_space=extra_space/(word_amount-1),
		special_number=extra_space%(word_amount-1),
		word_point_symbol=1;
		for(int i=0;i<=line_length-1;i++)
			if(present_line[i]!=' ') putchar(present_line[i]);
		    else
			{
				for(int temp=1;temp<=common_each_space+1;temp++) putchar(' ');
				if(word_point_symbol++<=special_number) putchar(' ');
			}
		putchar('\n');
	}
}
