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

#define Mode_negative_accepted 0x01
#define Mode_positive_accepted 0x02
#define Mode_zero_accepted 0x04
#define Mode_float_range 0x08
#define Mode_error_terminate_program 0x10
#define Mode_dont_add_common 0x20
#define Mode_cls_after_entered 0x40
#define Mode_double_check_value 0x80

#define Clear_stdin() while(getc(stdin)!='\n')
#define Common_mode (Mode_negative_accepted|Mode_positive_accepted|Mode_zero_accepted|Mode_error_terminate_program)

int main(int argc, char *argv[])
{
	fprintf(stdout, "Program will caculate the final amount of money you\'ll get.\n");
	double p=Get_a_value("Input the start money", Common_mode),
		   r=Get_a_value("Input the percentage for each year", Common_mode),
		   t=Get_a_value("Input the year", Common_mode);
	fprintf(stdout, "At last you will get %f\n", p*exp(r*t));
	system("pause");
	return EXIT_SUCCESS;
}

double Get_a_value(char *enter_message, unsigned char mode)
{
	double result;
	bool check=false;
	do
	{
		fprintf(stdout, "%s", enter_message);
		if(!(mode&Mode_dont_add_common)) putc(':', stdout);
		if(fscanf(stdin, "%lf", &result)==1)
		{
			if(!(mode&Mode_negative_accepted)) if(result<0) goto terminate;
			if(!(mode&Mode_positive_accepted)) if(result>0) goto terminate;
			if(!(mode&Mode_zero_accepted)) if(result==0) goto terminate;
			if(mode&Mode_float_range) if(fabs(result)>=FLT_MAX||(fabs(result)<=FLT_MIN&&result!=0)) goto terminate;
			if(mode&Mode_double_check_value)
			{
				fprintf(stdout, "The value is %f\n", result);
				system("pause");
			}
			check=true;
		}
		else if(ferror(stdin)&&(mode&Mode_error_terminate_program))
		{
			fprintf(stdout, "ERROR: user's input met an error.\n");
			system("pause");
			exit(EXIT_FAILURE);
		}
		terminate:Clear_stdin();
	}while(!check);
	if(mode&Mode_cls_after_entered) system("cls");
	return result;
}
