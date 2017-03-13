//Chapter Three Program Three
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//voice
	int
	GS1,group,code,item_number,check;
	
	//work
	printf("Enter ISBN:");
	scanf("%d-%d-%d-%d-%d",&GS1,&group,&code,&item_number,&check);
	printf("GS1 prefix:%d\nGroup prefix:%d\nPublisher code:%d\nItem number:%d\nCheck digit:%d\n",GS1,group,code,item_number,check);
	
	//show
	system("pause");
	return 0;
}