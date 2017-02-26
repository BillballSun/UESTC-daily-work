//Chapter Five Program Two
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CRT_SECURE_NO_DEPERCATE

int main(void)
{
	int hour,minute;
	printf("Enter a 24-hour time:");
	scanf("%d:%d",&hour,&minute);
	switch (hour)
	{
		case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:
		printf("Equivalent 12-hour time: %-2.2d:%-2.2d AM\n",hour,minute);break;
		case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:
		printf("Equivalent 12-hour time: %-2.2d:%-2.2d PM\n",hour-12,minute);break;
		case 24:
		printf("Equivalent 12-hour time: 00:%-2.2d AM\n",minute);break;
		default:
		printf("Input Error\n");system("pause");exit;
	}
	system("pause");
	return 0;
}