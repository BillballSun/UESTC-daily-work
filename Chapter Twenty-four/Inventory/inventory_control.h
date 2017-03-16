/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/

#ifndef HEAD_inventory

#define HEAD_inventory

/* signal call control */
#define Activated 1
#define Deactivated 0
#define Signal_modified 1
#define Signal_ignore 0

#define Signal_all_to_default Deactivated

#if !Signal_all_to_default
	#define SIGINT_control   Signal_modified
	#define SIGABRT_control  Signal_modified
	#define SIGTERM_control  Signal_modified
	#define SIGFPE_control   Signal_modified
	#define SIGILL_control   Signal_modified
	#define SIGSEGV_control  Signal_modified
#endif
/* signal call control end */

#endif