//Chapter Five Program Three
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CRT_SECURE_NO_DEPERCATE
#define OTHER_PER_GET (33f+0.02f)

int main(void)
{
	int number;
	float per,amount,pay,ohter;
	
	printf("Please enter the number:");
	scanf("%d",&number);
	printf("Please enter the per price:");
	scanf("%f",&per);
	amount=per*number;
	     if ((number<0)||(per<=0)) {printf("Input Error");system("pause");exit;}
	else if (amount<=2500)   pay=30f+0.017f*amount;
	else if (amount<=6250)   pay=56f+0.0066f*amount;
	else if (amount<=20000)  pay=76f+0.0034f*amount;
	else if (amount<=50000)  pay=100f+0.0022f*amount;
	else if (amount<=500000) pay=155f+0.0011f*amount;
	else                     pay=255f+0.0009f*amount;
	
	     if (number <2000) other=number*OTHER_PER_GET;
	else                   other=number*OTHER_PER_GET;
	printf("The manager will get %-.2f\nand the other will get %-.2f",pay,other);
	
	system("pause");
	return 0;
}