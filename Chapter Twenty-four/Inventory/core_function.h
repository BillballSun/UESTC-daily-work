/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/

#ifndef HEAD_core_function
#define HEAD_core_function

/* Setjmp_action */
#define Setjmp_action

#ifdef Setjmp_action
extern jmp_buf environment;
#define Alarm "a"
#endif

/* database limit defination */
#define Item_name_length_max 64
#define Item_info_length_max 255
#define Database_info_length 255

void Core_process(void);

#endif