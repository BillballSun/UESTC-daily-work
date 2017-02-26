#define _CRT_SECURE_NO_DEPRECATE /*Before all the includes*/
#include <stdbool.h>
#include "max_limit.h"
//#define Word_amount 10
#define Show_st(x) switch(x%10) \
	          {case 1:printf("st");break; \
	    case 2:printf("nd");break; \
		case 3:printf("rd");break; \
		default:printf("th");break;} 
			
#include "sort.h"
#include "structure.h"
void Sort(int *a,int low,int high);

void Read_array(int *array)
{
	int check;
	for(int i=1;i<=Word_amount;i++)
	{
		do
		{
			printf("Please enter the %d",i);
			Show_st(i);
			printf(" digit:");
			check=scanf("%d",array+i-1);
			Get_rid_of_RestLine();
		}while(!check);
	}
	Print_divide_line();
}

void Sort_array(int *array)
{
	Sort(array,0,Word_amount-1);
}

void Sort(int *a,int low,int high)
{
	int takeup;
	takeup=a[low];
	while(low<high&&a[high]>=takeup)
		high--;
	if (low>=high) return;
	a[low++]=a[high];
	while(low<high&&a[low]<=takeup)
		low++;
	if (low>=high) {a[high]=takeup;return;}
	a[high--]=a[low];
	a[low]=takeup;
	Sort(a,low,high);
	return;
}

void Show_array(int *array)
{
	printf("The sort result is as follow:\n");
	for(int i=0;i<=Word_amount-1;i++)
		printf("%d ",array[i]);
	putchar('\n\n');
}