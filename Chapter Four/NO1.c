//Chapter Four Program One
#define_CRT_SECURE_NO_DEPERCATE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n1,n2;
	
	printf("Enter a two-digit number:");
	scanf("%1d%1d",&n1,&n2);
	printf("The reveal is:%-1.1d%-1.1d\n",n2,n1);
	
	system("pause");
	return 0;
}