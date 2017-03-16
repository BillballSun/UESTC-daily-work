/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/

#ifndef HEAD_useful_macro
#define HEAD_useful_macro

#define Clear_stdin() while(getc(stdin)!='\n')

#ifndef Size_t_format_replacement
	#ifdef _WIN32
		#define Size_t_format_replacement "u"
	#elif defined _WIN64
		#define Size_t_format_replacement "lu"
	#else
		#error WIN32 or WIN64 compiler required
	#endif
#endif

#endif