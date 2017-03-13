#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#include "inventory_process.h"
#include "struct_def.h"
#include "inventory_control.h"
#include "find_info.h"
#include "info.h"
#include "structure_function.h"
#include "error_info.h"

extern struct component inventory[Max_component_amount];
extern int present_component_amount;

void Find_by_ID_process(void);
void Find_by_number_process(void);
void Find_by_name_process(void);
bool Decent_find_match(const char *s1,const char *s2);
void Find_by_amount_process(void);
int Find_id(signed short number, bool *check);
bool Safe_read_name(char *s,int n);
int Get_name_longest_ID(void);
int Get_name_shortest_ID(void);
int Get_amount_biggest_ID(void);
int Get_amount_smallest_ID(void);
int Get_number_biggest_ID(void);
int Get_number_smallest_ID(void);

char Get_command_order(void)
{
	char ch;
	Show_command_info();
	do
	{
		printf("Enter your command:");
		if((ch=getchar())!='\n') Get_rid_of_RestLine();
	}while(isspace(ch));
	return tolower(ch);
}

void Add_component_process(void)
{
	printf("======Add component======\n");
	signed short number;
	signed char check;
	bool find_check;
	do
	{
		printf("Please enter the component number:");
		check=scanf("%hd",&number);
		Get_rid_of_RestLine();
	}while(check<1);
	int id=Find_id(number,&find_check);
	/*find_check means find it already existing*/
	if(find_check)
	{
		printf("----------------------------------------\n");
		printf("Component already existing in inventory.\n");
		printf("Component info:\n");
		printf("ID: %d\n",id);
		printf("Number: %hd\n",inventory[id-1].number);
		printf("Name: %s\n",inventory[id-1].name);
		printf("Amount: %lu\n",inventory[id-1].present_amount);
		printf("----------------------------------------\n");
		long add_amount_temp;
		int scanf_check;
		do
		{
			add_amount_temp=-1l;
			printf("Please enter add amount:");
			scanf_check=scanf("%ld",&add_amount_temp);
			Get_rid_of_RestLine();
		}while(scanf_check<1||add_amount_temp<=0);
		if((unsigned long)add_amount_temp+inventory[id-1].present_amount<=Max_component_store_amount)
		{
			inventory[id-1].present_amount+=add_amount_temp;
			printf("Add succussfully done.\n");
		}
		else Show_error_info(Error_info_store_amount_overflow);
	}
	else if(id<=Max_component_amount)
	{
		bool length_check_temp;
		struct component new_component;
		new_component.number=number;
		do
		{
			printf("Please name this new item:");
			length_check_temp=Safe_read_name(new_component.name,Max_component_name_length);
		}while(!length_check_temp);
		long add_amount_temp;
		int scanf_check;
		do
		{
			add_amount_temp=-1l;
			printf("Please enter the amount:");
			scanf_check=scanf("%ld",&add_amount_temp);
			Get_rid_of_RestLine();
			if(add_amount_temp>Max_component_store_amount&&scanf_check>0) Show_error_info(Error_info_store_amount_overflow);
		}while(scanf_check<1||add_amount_temp<=0||add_amount_temp>Max_component_store_amount);
		new_component.present_amount=add_amount_temp;
		inventory[id-1]=new_component;
		present_component_amount++;
		printf("New item store in inventory successfully.\n");
	}
	else Show_error_info(Error_info_store_amount_overflow);
}

void Delete_component_process(void)
{
	printf("=====Delete component====\n");
	signed short number;
	signed char check;
	bool find_check;
	do
	{
		printf("Please enter the component number:");
		check=scanf("%hd",&number);
		Get_rid_of_RestLine();
	}while(check<1);
	int id=Find_id(number,&find_check);
	/*find_check means find it already existing*/
	if(find_check)
	{
		printf("----------------------------------------\n");
		printf("Component found in inventory.\n");
		printf("Component info:\n");
		printf("ID: %d\n",id);
		printf("Number: %hd\n",inventory[id-1].number);
		printf("Name: %s\n",inventory[id-1].name);
		printf("Amount: %lu\n",inventory[id-1].present_amount);
		printf("----------------------------------------\n");
		long delete_amount_temp;
		int scanf_check;
		do
		{
			delete_amount_temp=-1l;
			printf("Please enter delete amount:");
			scanf_check=scanf("%ld",&delete_amount_temp);
			Get_rid_of_RestLine();
		}while(scanf_check<1||delete_amount_temp<=0);
		long long then_amount=(long long)inventory[id-1].present_amount-(long long)delete_amount_temp;
		if(then_amount>0)
		{
			inventory[id-1].present_amount=(unsigned long)then_amount;
			printf("Delete succussfully done.\n");
		}
		else if(then_amount==0)
		{
			for(int i=id-1;i<=present_component_amount-2;i++)
				inventory[i]=inventory[i+1];
			present_component_amount--;
			printf("Remove Item from the inventory successfully.\n");
		}
		else Show_error_info(Error_info_store_amount_downflow);
	}
	else Show_error_info(Error_info_no_match_component);
}

void Print_component_process(void)
{
	char ch;
	printf("======Show inventory info=====\n");
	do
	{
		printf("0--Show whole inventory info\n");
		printf("1--List all the content by ID\n");
		printf("2--Show the index of inventory\n");
		printf("Please select:");
		ch=getchar();
		if(ch!='\n') Get_rid_of_RestLine();
		Print_small_line();
	}while(!(ch>='0'&&ch<='2'));
	#define Show_whole_info '0'
	#define List_all '1'
	#define Show_index '2'
	switch(ch)
	{
		case Show_whole_info:
			printf("Now the inventory got %d items exactly.\n",present_component_amount);
		break;
		case List_all:
			for(int i=0;i<=present_component_amount-1;i++)
			{
				printf("ID:%d\n",i);
				printf("Number:%hd\n",inventory[i].number);
				printf("Name:%s\n",inventory[i].name);
				printf("Amount:%lu\n",inventory[i].present_amount);
				Print_small_line();
			}
			if(present_component_amount==0) printf("Nothing got in inventory right now.\n");
		break;
		case Show_index:
			if(present_component_amount==0) printf("Index is not available now, due to nothing stored.\n");
			else
			{
				printf("The longest name item, ID:%d, name:%s\n",
				       Get_name_longest_ID(),inventory[Get_name_longest_ID()-1].name);
				printf("The shortest name item, ID:%d, name:%s\n",
				       Get_name_shortest_ID(),inventory[Get_name_shortest_ID()-1].name);
				printf("The largest amount item, ID:%d, amount:%lu\n",
				       Get_amount_biggest_ID(),inventory[Get_amount_biggest_ID()-1].present_amount);
				printf("The smallest amount item, ID:%d, amount:%lu\n",
				       Get_amount_smallest_ID(),inventory[Get_amount_smallest_ID()-1].present_amount);
				printf("The biggest number item, ID:%d, number:%hd\n",
				       Get_number_biggest_ID(),inventory[Get_number_biggest_ID()-1].number);
				printf("The smallest number item, ID:%d, number:%hd\n",
				       Get_number_smallest_ID(),inventory[Get_number_smallest_ID()-1].number);
				Print_small_line();
			}
		break;
	}
	printf("For detailed one info, please use search mode.\n");
}

int Get_name_longest_ID(void)
{
	if (present_component_amount==0) return 0;
	int target=1;
	for(int i=2;i<=present_component_amount;i++)
		if(strlen(inventory[target].name)<strlen(inventory[i].name)) target=i;
	return target;
}

int Get_name_shortest_ID(void)
{
	if (present_component_amount==0) return 0;
	int target=1;
	for(int i=2;i<=present_component_amount;i++)
		if(strlen(inventory[target].name)>strlen(inventory[i].name)) target=i;
	return target;
}

int Get_amount_biggest_ID(void)
{
	if (present_component_amount==0) return 0;
	int target=1;
	for(int i=2;i<=present_component_amount;i++)
		if(inventory[target].present_amount<inventory[i].present_amount) target=i;
	return target;
}

int Get_amount_smallest_ID(void)
{
	if (present_component_amount==0) return 0;
	int target=1;
	for(int i=2;i<=present_component_amount;i++)
		if(inventory[target].present_amount>inventory[i].present_amount) target=i;
	return target;
}

int Get_number_biggest_ID(void)
{
	if (present_component_amount==0) return 0;
	int target=1;
	for(int i=2;i<=present_component_amount;i++)
		if(inventory[target].number<inventory[i].number) target=i;
	return target;
}

int Get_number_smallest_ID(void)
{
	if (present_component_amount==0) return 0;
	int target=1;
	for(int i=2;i<=present_component_amount;i++)
		if(inventory[target].number<inventory[i].number) target=i;
	return target;
}

void Search_component_process(void)
{
	printf("======Find component=====\n");
	char ch;
	do
	{
		printf("Please select how to find your component.\n");
		printf("1--ID  2--number  3--name  4--amount\n");
		printf("Enter your selecting:");
		if((ch=getchar())!='\n') Get_rid_of_RestLine();
	}while(ch<='0'||ch>='5');
	
	switch(ch-'0')
	{
		case Find_by_ID:Find_by_ID_process();break;
		case Find_by_number:Find_by_number_process();break;
		case Find_by_name:Find_by_name_process();break;
		case Find_by_amount:Find_by_amount_process();break;
	}
}

void Find_by_ID_process(void)
{
	int id;
	signed char check;
	do
	{
		printf("Please enter the finding ID:");
		check=scanf("%d",&id);
		Get_rid_of_RestLine();
	}while(check<1);
	if(id<=present_component_amount)
	{
		printf("----------------------------------------\n");
		printf("Component found in inventory.\n");
		printf("Component info:\n");
		printf("ID: %d\n",id);
		printf("Number: %hd\n",inventory[id-1].number);
		printf("Name: %s\n",inventory[id-1].name);
		printf("Amount: %lu\n",inventory[id-1].present_amount);
		printf("----------------------------------------\n");
	}
	else Show_error_info(Error_info_no_match_component);
}

void Find_by_number_process(void)
{
	signed short number;
	signed char check;
	bool find_check;
	do
	{
		printf("Please enter the finding number:");
		check=scanf("%hd",&number);
		Get_rid_of_RestLine();
	}while(check<1);
	int id=Find_id(number,&find_check);
	/*find_check means find it already existing*/
	if(find_check)
	{
		printf("----------------------------------------\n");
		printf("Component already existing in inventory.\n");
		printf("Component info:\n");
		printf("ID: %d\n",id);
		printf("Number: %hd\n",inventory[id-1].number);
		printf("Name: %s\n",inventory[id-1].name);
		printf("Amount: %lu\n",inventory[id-1].present_amount);
		printf("----------------------------------------\n");
	}
	else Show_error_info(Error_info_no_match_component);
}

void Find_by_name_process(void)
{
	char find_target_name[Max_component_name_length+1];
	bool enter_check;
	do
	{
		printf("Please enter the finding name:");
		enter_check=Safe_read_name(find_target_name,Max_component_name_length);
	}while(!enter_check);
	bool find_check=false;
	printf("----------------------------------------\n");
	for(int i=0;i<=present_component_amount-1;i++)
		if(strcmp(inventory[i].name,find_target_name)==0)
		{
			find_check=true;
			printf("ID: %d\n",i+1);
			printf("Number: %hd\n",inventory[i].number);
			printf("Name: %s\n",inventory[i].name);
			printf("Amount: %lu\n",inventory[i].present_amount);
			printf("----------------------------------------\n");
		}
	if(!find_check)
	{
		printf("No finding for name \"%s\"\n",find_target_name);
		char ch;
		do
		{
			printf("Do you hope a decent search result(Y/N)---");
			if((ch=toupper(getchar()))!='\n') Get_rid_of_RestLine();
		}while(ch!='Y'&&ch!='N');
		if(ch=='Y')
		{
			bool decent_find_result=false;
			printf("----------------------------------------\n");
			for(int i=0;i<=present_component_amount-1;i++)
			if(Decent_find_match(inventory[i].name,find_target_name))
			{
				decent_find_result=true;
				printf("ID: %d\n",i+1);
				printf("Name: %s\n",inventory[i].name);
				printf("----------------------------------------\n");
			}
			if(!decent_find_result) printf("No decent result\n");
		}
	}
}

bool Decent_find_match(const char *s1,const char *s2)
{
	int len1=strlen(s1),len2=strlen(s2);
	if(len1<len2) return false;
	else
	{
		for(int i=0;i<=len1-len2;i++)
		{
			bool check=true;
			for(int temp=0;temp<=len2-1;temp++)
				if(toupper(s1[i+temp])!=toupper(s2[temp])) check=false;
			if (check) return true;
		}
	}
	return false;
}

void Find_by_amount_process(void)
{
	long find_target_amount;
	signed char check;
	do
	{
		printf("Please enter the finding amount:");
		check=scanf("%ld",&find_target_amount);
		Get_rid_of_RestLine();
	}while(check<1&&find_target_amount<=0);
	printf("----------------------------------------\n");
	bool find_check=false;
	for(int i=0;i<=present_component_amount-1;i++)
		if((unsigned long)find_target_amount==inventory[i].present_amount)
		{
			find_check=true;
			printf("ID: %d\n",i);
			printf("Number: %hd\n",inventory[i].number);
			printf("Name: %s\n",inventory[i].name);
			printf("----------------------------------------\n");
		}
	if(!find_check) Show_error_info(Error_info_no_match_component);
}

int Find_id(signed short number, bool *check)
/*Return ID range from i-Max_component_amount*/
{
	*check=false;
	int i;
	for(i=0;i<present_component_amount;i++)
		if(inventory[i].number==number) {*check=true;break;}
	if(*check) return i+1;
	else return present_component_amount+1;
}

bool Safe_read_name(char *s,int n)
//Empty word return false, true means at least one letter read.
{
	char ch;
    while(isspace(ch=getchar())&&ch!='\n') continue;
	if(ch=='\n') 
	{
		s='\0';
		return false;
	}
	do
	{
		*s++=ch;
		n--;
		ch=getchar();
	}while(ch!='\n'&&n>0);
	if(ch!='\n') Get_rid_of_RestLine();
	*s='\0';
	return true;
}
