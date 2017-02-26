#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdio.h> /*scanf printf getchar putchar*/
#include <ctype.h> /*toupper tolower isalpha isupper islower*/
#include "word.h"
#include "max_limit.h"
int read_word(char *present_word)
{
	char ch;
	int word_length=0;
	while(isspace(ch=getchar())) continue;
	while (ch != EOF&&!isspace(ch))
	{
		if (word_length <= Max_word_length)
			present_word[word_length++] = ch;
		ch = getchar();
	}
	if(word_length>Max_word_length) present_word[word_length-1]=Replace_extra_character;
	present_word[word_length]='\0';
	return word_length;
}
