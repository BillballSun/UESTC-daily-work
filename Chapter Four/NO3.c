//Chapter Four Program Three
#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_DEPERCATE

int main(void)
{
	int data,n1,n2,n3,n4,n5;
	
	printf("Enter a number between 0 and 32767:");
	scanf("%d",&data);
	//Get each number
	n1=data%8;data=data/8;n2=data%8;data=data/8;n3=data%8;data=data/8;n4=data%8;data=data/8;n5=data%8;
	printf("In octal,your number is:%-1.1d%-1.1d%-1.1d%-1.1d%-1.1d\n",n1,n2,n3,n4,n5);
	
	system("pause");
	return 0;
}