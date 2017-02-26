//Chapter Four Program Two
#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_DEPERCATE

int main(void)
{
	printf("Enter a three-digit number:");
	scanf("%3d",&data);
	n1=data/100;
	n2=(data%100)/10;
	n3=data%10;
	printf("The reveal is:%-1.1d%-1.1d%-1.1d\n",n3,n2,n1);
	
	system("pause");
	return 0;
}