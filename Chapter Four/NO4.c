//Chapter Four Program Five
#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_DEPERCATE
#define MOD (9+1)
#define PLUG (8+1)

int main(void)
{
	int check=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,a10=0,a11=0;
	
	printf("Enter the first 11 digits of a UPC:");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9,&a10,&a11);
	check=PLUG-((3*(a1+a3+a5+a7+a9+a11)+(a2+a4+a6+a8+a10)-1)%MOD);
	printf("Check digit:%d\n",check);
	
	system("pause");
	return 0;
}