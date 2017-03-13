//Chapter Three Program Four
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int place,first,second;
	
	printf("Enter phone number[(xxx) xxx-xxxx]:");
	scanf("（%d） %d-%d",&place,&first,&second);
	printf("You entered %3.3d.%3.3d.%3.3d\n",place,first,second);
	
	system("pause");
	return 0;
}