/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/

#include <stdio.h>

#define Max_date_string_length 10
#define Clean_stdin() while(getc(stdin)!='\n')

struct date
{
	unsigned short year;
	unsigned char month, day;
};

int main(int argc, char *argv[])
{
	fprintf(stdout, "Please enter your date.\n"
			"(format like 2016/2/3, 2016-2-3 or 2016 2 3):");
	char date[Max_date_string_length+1];
	fgets(date, Max_date_string_length+1, stdin);
	if(date[strlen(date)-1]!='\n') Clean_stdin();
	struct date data;
	if(sscanf(date, "%hu%*[-/ ]%hhu%*[-/ ]%hhu", &date.year, &date.month, &date.day)<3)
	{
		fprintf(stderr, "ERROR: warning date illegal.\n");
		system("pause");
		return EXIT_FAILURE;
	}
	auto const char *months_string[]=
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	}
	fprintf(stdout, "DATE: %s %hhu, %hu\n", month_string[data.month-1], data.day, data.year);
	system("pause");
	return EXIT_SUCCESS;
}
