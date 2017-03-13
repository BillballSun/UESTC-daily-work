//Chapter Three Program Six
#define_CRT_SECURE_NO_DEPERCATE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int z1,z2,m1,m2;
	printf("Enter two fractions seperated by a plug sign:");
	scanf("%d/%d+%d/%d",&z1,&m1,&z2,&m2);
	printf("The sum is: %d/%d",z1*m2+z2*m1,m1*m2);
	system("pause");
	return 0;
}