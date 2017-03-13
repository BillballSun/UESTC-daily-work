//NO1
(a) signal could be asynchronous, which means it won't happen at the exact time we plan to do things.
(b) system("shutdown"); disk removed physically; power off;

//NO2
assert(top!=NULL);
#define _STR(x) _VAL(x)
#define _VAL(x) #x
#define assert(test) ((test)?(void)0 \
		:_Assert(__FILE__ ":" _STR(__LINE__) " " #test))
void _Assert(char *mesg)
{
	fputs(mesg, stderr);
	fputs(" -- assertion failed.\n", stderr);
	abort();
}

//NO3
double try_math_function(double (*func)(double) , double x, char *message)
{
	errno=0;
	double result=(*func)(x);
	if(error!=0)
	{
		perror(message);
		exit(EXIT_FAILURE);
	}
	return result;
}

#define TRY_MATH_FUNCTION(func, x) try_math_function(func, x, "Error in call of " #func)
