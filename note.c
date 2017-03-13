/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/
/* PR1.c (Chapter 13, page 210) */
#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h>
/* scanf printf getchar putchar qsort */
/* fopen freopen setvbuf fflush rewind fseek ftell fgetpos fsetpos fclose tmpfile */
/* tmpnam L_tmpnam TMP_MAX _IOFBF _IOLBF _IONBF SEEK_SET SEEK_CUR SEEK_END fpos_t */
/* FILENAME_MAX stdin stdout stderr*/
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace size_t isdigit isgraph isxdigit */
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h>
/* memcpy strcpy(n) strlen strcat(n) strcmp memmove strncmp memcmp strncmp strcoll strxfrm */
/* memchr strchr strspn strcspn strpbrk strrchr strtok strstr memset */
/* WARNING non-standard function strdup stricmp strlwr strupr strrev strset */
#include <time.h> /* time */
#include <stddef.h> /* offsetof */
#include <assert.h> /* assert NDEBUG */
#include <errno.h> /* EDOM ERANGE EILSEQ */
/* in stdio perror */
/* in string strerror */
#include <signal.h>  /* SIGABRT SIGFPE SIGILL SIGINT SIGSEGV SIGTERM signal SIG_DEF SIG_IGN raise */
#include <setjmp.h> /* setjmp longjmp */
//#include <iostream> /* C++ input and output */
//using namespace std; /* C++ cout cin */
/**bool decleration**
* #define Bool int  *
* typedef int Bool; *
**********************/
/*******random number generate******************
*srand((unsigned)time(NULL));                  *
*rand() to get a 0-maxint number, use %amount. *
***********************************************/
/********PC-lint check**********************************
*PC-Lint check                                         *
*C:/Lint/Lint-nt -i"C:/Lint" -u cmd_std.lnt D:/lint.cpp*
*******************************************************/
/***********American standard ASCII**********
*system("chcp 437>nul.");Show ASCII extended*
********************************************/
/******Macro decleration*****
*  ===Macro difination===   *
*#define					*
*#if defined				*
*#ifdef				    	*
*#ifndef			 		*
*#endif				    	*
*							*
*#if						*
*#elif						*
*#else				 		*
*#endif			    		*
*							*
*#error				    	*
*#line						*
*#pragma					*
*_Pragma(...)		 		*
*#pragma warning disable	*
*#pragma warning restore	*
*							*
*__LINE__					*
*__FILE__					*
*__DATE__					*
*__TIME__					*
*__STDC__				    *
*__STDC_HOSTED__            *
*__STDC_VERSION__           *
*__STDC_IEC_599__           *
*__STDC_IEC_599_COMPLEX__   *
*__STDC_ISO_10646__         *
*__func___                  *
*__VA_ARGS__				*
*variadic argument symbol   *
****************************/
/******Limit**********
========limit.h========
#define CHAR_BIT      8                            // number of bits in a char
#define SCHAR_MIN   (-128)                         // minimum signed char value
#define SCHAR_MAX     127                          // maximum signed char value
#define UCHAR_MAX     0xff                         // maximum unsigned char value
#ifndef _CHAR_UNSIGNED
#define CHAR_MIN    SCHAR_MIN                  // mimimum char value
#define CHAR_MAX    SCHAR_MAX                  // maximum char value
#else
#define CHAR_MIN      0
#define CHAR_MAX    UCHAR_MAX
#endif
#define MB_LEN_MAX    5                            // max. # bytes in multibyte char
#define SHRT_MIN    (-32768)                       // minimum (signed) short value
#define SHRT_MAX      32767                        // maximum (signed) short value
#define USHRT_MAX     0xffff                       // maximum unsigned short value
#define INT_MIN     (-2147483647 - 1)              // minimum (signed) int value
#define INT_MAX       2147483647                   // maximum (signed) int value
#define UINT_MAX      0xffffffff                   // maximum unsigned int value
#define LONG_MIN    (-2147483647L - 1)             // minimum (signed) long value
#define LONG_MAX      2147483647L                  // maximum (signed) long value
#define ULONG_MAX     0xffffffffUL                 // maximum unsigned long value
#define LLONG_MAX     9223372036854775807i64       // maximum signed long long int value
#define LLONG_MIN   (-9223372036854775807i64 - 1)  // minimum signed long long int value
#define ULLONG_MAX    0xffffffffffffffffui64       // maximum unsigned long long int value
#define _I8_MIN     (-127i8 - 1)                   // minimum signed 8 bit value
#define _I8_MAX       127i8                        // maximum signed 8 bit value
#define _UI8_MAX      0xffui8                      // maximum unsigned 8 bit value
#define _I16_MIN    (-32767i16 - 1)                // minimum signed 16 bit value
#define _I16_MAX      32767i16                     // maximum signed 16 bit value
#define _UI16_MAX     0xffffui16                   // maximum unsigned 16 bit value
#define _I32_MIN    (-2147483647i32 - 1)           // minimum signed 32 bit value
#define _I32_MAX      2147483647i32                // maximum signed 32 bit value
#define _UI32_MAX     0xffffffffui32               // maximum unsigned 32 bit value
#define _I64_MIN    (-9223372036854775807i64 - 1)  // minimum signed 64 bit value
#define _I64_MAX      9223372036854775807i64       // maximum signed 64 bit value
#define _UI64_MAX     0xffffffffffffffffui64       // maximum unsigned 64 bit value
#ifndef SIZE_MAX                                   //SIZE_MAX size_t max defination
#ifdef _WIN64
#define SIZE_MAX _UI64_MAX
#else
#define SIZE_MAX UINT_MAX
#endif
#endif
*/
/***********useful Macro decleration start****************
#define Pascal true
#define DEBUG_mode true
#define Sample_structure_use true
#if Pascal
#define begin {
#define end }
#endif

#Test_divisor(x) if((x)==0) do { printf("Error, divide zero\n");system("pause");} while(false)

#define Show_st(x) do switch((x)%10) \
{								\
	case 1:printf("st");break; \
	case 2:printf("nd");break; \
	case 3:printf("rd");break; \
	default:printf("th");break; \
}								\
while(false)

#define Print_divide_line() printf("------------------------------------------------------\n")

#define Show_start_info() \
do { \
	printf("--------------Amazing CA inc program-----------------\n"); \
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n"); \
	printf("Ways To Use:\n"); \
	printf("Please enter what to say\n"); \
	printf("Please enter what to say\n"); \
	printf("Please enter what to say\n"); \
	Print_divide_line(); \
} while(false)

#define Get_rid_of_RestLine() \
do { \
	unsigned char ch; \
	while((ch=getchar())!='\n') continue; \
} while(false)

#define Safe_read_line(s,n) \
do { \
char ch; \
char *s_temp=s; \
int n_temp=n; \
	while(((ch=getchar())!='\n')&&n>0) \
	{
	*s_temp++=ch;
	n_temp--;
	}
	if(ch!='\n') Get_rid_of_RestLine();
	*s_temp='\0';
} while(false)

#define Is_try_again() \
(printf("Another chance(Y/N)?----"),toupper(getchar())=='Y')?true\
:false

#define My_printf_without_escpe_sequence(x,...) printf(#x,__VA_ARGS__)

************useful Macro decleration end*****************/
/*****************Sample structure start******************
void Show_start_info(void);
void Show_exit_info(void);
void Print_divide_line(void);
void Print_small_line(void);
bool Safe_read_name(char *,int);
void Get_rid_of_RestLine(void);
void Show_st(int);
void Safe_read_line(char *, int);
bool Get_Y_or_N(char *info);
======Modify indicator======
void Main_program(void);
int main(int argc, int argv[])
{
	bool cycle;
	Show_start_info();
	do
	{
		Main_program();
		cycle=Get_Y_or_N("Test again");
	}while(cycle);
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}
======Modify indicator======
void Main_program(void)
{

}

void Show_start_info(void)
{
	printf("--------------Amazing CA inc program-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("Ways To Use:\n");
	printf("Please enter what to say\n");
	printf("Please enter what to say\n");
	printf("Please enter what to say\n");
	Print_divide_line();
}

void Print_divide_line(void)
{
	printf("------------------------------------------------------\n");
}

void Print_small_line(void)
{
	printf("-----------------------\n");
}

void Show_exit_info(void)
{
	Print_divide_line();
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}

void Show_st(int x)
{
	switch(x%10)
	{
		case 1:printf("st");break;
		case 2:printf("nd");break;
		case 3:printf("rd");break;
		default:printf("th");break;
	}
}

void Get_rid_of_RestLine(void)
{
	unsigned char ch;
	while((ch=getchar())!='\n') continue;
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
	}while(!isspace(ch)&&n>0);
	if(ch!='\n') Get_rid_of_RestLine();
	*s='\0';
	return true;
}

void Safe_read_line(char *s, int n)
{
	char ch;
	while(((ch=getchar())!='\n')&&n>0)
	{
		*s++=ch;
		n--;
	}
	if(ch!='\n') Get_rid_of_RestLine();
	*s='\0';
}

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
*****************Sample structure end*******************/
/**************Standard I/O header decleration**********
#define EOF     (-1)

#ifndef _FILE_DEFINED
struct _iobuf {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
        };
typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif  //_FILE_DEFINED
********************************************************/
/*************************Memory copy**************************************
void *memcpy(void *restrict target, const void * restrict source, size_t len);
void *memmove(void *target, const void *source, size_t len);
***************************************************************************/
/***************Basic bit operate******************
//position goes from 0 to 15, it have 16 bits
signed short i=0x0000;

//set the j position
i|=1<<j;

//clean the j position
i&=~(1<<j);

//test the j position
if(i&1<<j)
***************************************************/
/****************Bits every type*******************
//16
unsigned char 8
unsigned short 16
unsigned int 16
unsigned long 32
//32
unsigned char 8
unsigned short 16
unsigned int 32
unsigned long 32
unsigned long long (more than) 64
//64
unsigned char 8
unsigned short 16
unsigned int 32
unsigned long 64
unsigned long long (more than) 64
**************************************************/
















































