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
#include <stdlib.h>

#if defined _WIN32
	#define s_t_printf_replace "%u"
#elif defined _WIN64
	#define s_t_printf_replace "%lu"
#else
	#error WIN32 or WIN64 compiler required
#endif

int main(int argc, char *argv[])
{
	size_t count=0u;
	while((ch=getc(stdin))!=EOF)
		if(ch=='.'||ch==';'||ch=='?'||ch=='!') count++;
	
	fprintf(stdout, "Count " s_t_printf_replace "\n", count);
	system("pause");
	return EXIT_SUCCESS;
}
