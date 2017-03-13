/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/

#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h>

int main(int argc, char *argv[])
{
	bool Word_begins=false;
	int ch;
	while((ch=getc(stdin))!=EOF)
	{
		if(isalpha(ch)) 
			{if(!Word_begins) ch=toupper(ch);}
		else
			Word_begins=false;
		putc(ch, stdout);
	}
	return EXIT_SUCCESS;
}
