//Chapte Five Program One
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CRT_SECURE_NO_DEPERCATE

int main(void)
{
	int data;
	printf("Enter a number:");
	scanf("%d",&data);
	     if (data>=10000)
	        {printf("Input Error\n");system("pause");exit;}
    else if (data>=1000)
		    printf("The number %4d has 4 numbers.\n");
	else if (data>=100)
		    printf("The number %4d has 3 numbers.\n");
	else if (data>=10)
		    printf("The number %4d has 2 numbers.\n");
	else if (data>=1)
		    printf("The number %4d has 1 numbers.\n");
	else    {printf("Input Error\n");system("pause");exit;}
	
	system("pause");
	return 0;
}