//Chapter Three Program Two
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int item_number, d, m, y;
	float unit_price;
	printf("Enter item number:");
	scanf("%d", &item_number);
	printf("Enter unit price:");
	scanf("%f", &unit_price);
	printf("Enter purchase date (mm/dd/yyyy):");
	scanf("%d/%d/%d", &m, &d, &y);
	printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%-3d\t\t$%7.2f\t%-4.4d/%-2.2d/%-2.2d\n", item_number, unit_price, y, m, d);
	system("pause");
	return 0;
}