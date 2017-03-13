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
	bool Line_begins=false;
	int ch;
	while((ch=getc(stdin))!=EOF)
	{
		if(isblack(ch)&&!Line_begins) continue;
		if(ch=='\n') Line_begins=false;
		else Line_begins=true;
		putc(ch, stdout);
	}
	return EXIT_SUCCESS;
}
