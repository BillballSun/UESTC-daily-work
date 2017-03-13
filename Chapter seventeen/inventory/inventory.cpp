#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN64
#error Compiler reqiured a WIN32 enviroment, please check
#endif

struct part
{
	unsigned short number;
	//range from 1 to USHRT_MAX
	char *name;
	//allocation
	unsigned int amount;
	//range from 1 to UINT_MAX
	float price;
	unsigned char price_percentage;
	//range from 1 to UCHAR_MAX
	struct part *next;
};

struct part *inventory_first_point=NULL;

#include "info.h"
#include "main_program.h"

int main(int argc, char argv[])
{
	Show_start_info();
	Main_program();
	Show_exit_info();
	system("pause");
	return EXIT_SUCCESS;
}

