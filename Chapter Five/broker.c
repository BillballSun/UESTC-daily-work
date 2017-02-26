#define CRT_SECURE_NO_DEPERCATE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float amount,pay;
	printf("Please enter the amount:");
	scanf("%f",&amount);
	     if (amount<0) {printf("Input Error");system("pause");exit;}
	else if (amount<=2500)   pay=30f+0.017*amount;
	else if (amount<=6250)   pay=56f+0.0066*amount;
	else if (amount<=20000)  pay=76f+0.0034*amount;
	else if (amount<=50000)  pay=100f+0.0022*amount;
	else if (amount<=500000) pay=155f+0.0011*amount;
	else                     pay=255f+0.0009*amount;
	printf("The manager will get %.2f",pay);
	
	system("pause");
	return 0;
}