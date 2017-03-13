#define _CRT_SECURE_NO_DEPRECATE
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "external.h"

#include "error_message_macro.h"
#include "control.h"

#include "supporting_function.h"
#include "structure.h"
#include "info.h"

void Find_by_number_process(struct part ***link_point, size_t *amount);
void Find_by_name_process(struct part ***link_point, size_t *amount);
void Find_by_amount_process(struct part ***link_point, size_t *amount);
void Find_by_price_process(struct part ***link_point, size_t *amount);
void Find_by_order_process(struct part ***link_point, size_t *amount);

void Find_parts(struct part ***link_point, size_t *amount)
//WARNING make sure allocation made before call function Find_parts
//INFO if realloc failed return NULL and automatically free (*link_point) in this function
//WARNING Link_Point must point to PREVIOUS part
{
	char ch=Get_a_upper_range('1','5',"1--number  2--name  3--amount  4--price  5--order","please enter your selection:");
	switch(ch)
	{
		case '1':Find_by_number_process(link_point,amount);break;
		case '2':Find_by_name_process(link_point,amount);break;
		case '3':Find_by_amount_process(link_point,amount);break;
		case '4':Find_by_price_process(link_point,amount);break;
		case '5':Find_by_order_process(link_point,amount);break;
	}
}

void Find_by_number_process(struct part ***link_point, size_t *amount)
{
	unsigned short find_number=Get_a_number();
	#if !(defined Enable_print_small_line_after_every_entrance)&& !(defined Enable_print_small_line_after_get)
	Print_small_line();
	#endif
	struct part *p;
	struct part *pre;
	for(p=inventory_first_point,pre=NULL;p!=NULL;pre=p,p=p->next)
		if(p->number==find_number)
		{
			struct part **temp=(struct part **)realloc(*link_point,(*amount+1)*sizeof(struct part *));
			if(temp==NULL)
			{
				free(*link_point);
				*link_point=NULL;
				return;
			}
			*link_point=temp;
			*((*link_point)+*amount)=pre;
			(*amount)++;
		}
}


void Find_by_name_process(struct part ***link_point, size_t *amount)
{
	char* find_name=Get_a_name();
	#if !(defined Enable_print_small_line_after_every_entrance)&& !(defined Enable_print_small_line_after_get)
	Print_small_line();
	#endif
	struct part *p;
	struct part *pre;
	for(p=inventory_first_point,pre=NULL;p!=NULL;pre=p,p=p->next)
		if(strcmp(p->name,find_name)==0)
		{
			struct part **temp=(struct part **)realloc(*link_point,(*amount+1)*sizeof(struct part *));
			if(temp==NULL)
			{
				free(*link_point);
				*link_point=NULL;
				return;
			}
			*link_point=temp;
			*((*link_point)+*amount)=pre;
			(*amount)++;
		}
	if(*amount==0)
		if(Get_Y_or_N("No found at present, hope a decent finding"))
		{
			#ifndef Enable_print_small_line_after_Y_or_N
			Print_small_line();
			#endif
			for(p=inventory_first_point,pre=NULL;p!=NULL;pre=p,p=p->next)
			if(Decent_match(p->name,find_name))
			{
				struct part **temp=(struct part **)realloc(*link_point,(*amount+1)*sizeof(struct part *));
				if(temp==NULL)
				{
					free(*link_point);
					*link_point=NULL;
					return;
				}
				*link_point=temp;
				*((*link_point)+*amount)=pre;
				(*amount)++;
			}
		}
}

void Find_by_amount_process(struct part ***link_point, size_t *amount)
{
	unsigned int find_amount=Get_an_amount();
	#if !(defined Enable_print_small_line_after_every_entrance)&& !(defined Enable_print_small_line_after_get)
	Print_small_line();
	#endif
	struct part *p;
	struct part *pre;
	for(p=inventory_first_point,pre=NULL;p!=NULL;pre=p,p=p->next)
		if(p->price==find_amount)
		{
			struct part **temp=(struct part **)realloc(*link_point,(*amount+1)*sizeof(struct part *));
			if(temp==NULL)
			{
				free(*link_point);
				*link_point=NULL;
				return;
			}
			*link_point=temp;
			*((*link_point)+*amount)=pre;
			(*amount)++;
		}
}

void Find_by_price_process(struct part ***link_point, size_t *amount)
{
	float find_price=Get_a_price();
	#if !(defined Enable_print_small_line_after_every_entrance)&& !(defined Enable_print_small_line_after_get)
	Print_small_line();
	#endif
	struct part *p;
	struct part *pre;
	for(p=inventory_first_point,pre=NULL;p!=NULL;pre=p,p=p->next)
		if(p->amount==find_price)
		{
			struct part **temp=(struct part **)realloc(*link_point,(*amount+1)*sizeof(struct part *));
			if(temp==NULL)
			{
				free(*link_point);
				*link_point=NULL;
				return;
			}
			*link_point=temp;
			*((*link_point)+*amount)=pre;
			(*amount)++;
		}
}

void Find_by_order_process(struct part ***link_point, size_t *amount)
{
	unsigned int find_order=Get_an_order();
	#if !(defined Enable_print_small_line_after_every_entrance)&& !(defined Enable_print_small_line_after_get)
	Print_small_line();
	#endif
	unsigned int count=0;
	struct part *p;
	struct part *pre;
	for(p=inventory_first_point,pre=NULL;p!=NULL;pre=p,p=p->next)
	{
		count++;
		if(count==find_order)
		{
			struct part **temp=(struct part **)realloc(*link_point,(*amount+1)*sizeof(struct part *));
			if(temp==NULL)
			{
				free(*link_point);
				*link_point=NULL;
				return;
			}
			*link_point=temp;
			*((*link_point)+*amount)=pre;
			(*amount)++;
			break;
		}
	}
}

unsigned short Get_a_number(void)
{
	int result;
	bool check;
	do
	{
		check=false;
		printf("Please enter a number:");
		if(scanf("%d",&result)==1)
			if(result<=USHRT_MAX&&result>=1)
				check=true;
			else
				Show_info(Info_message_number_flow);
		else
			Show_info(Info_message_illegal_entrance);
	Get_rid_of_RestLine();
	#ifdef Enable_print_small_line_after_every_entrance
	Print_small_line();
	#endif
	}while(!check);
	#if (defined Print_small_line_after_get)&&(!(Enable_print_small_line_after_every_entrance))
	Print_small_line();
	#endif
	return (unsigned short) result;
}

unsigned int Get_an_order(void)
{
	long result;
	bool check;
	do
	{
		check=false;
		printf("Please enter an order:");
		if(scanf("%ld",&result)==1)
			if(result<=SIZE_MAX&&result>=1)
				check=true;
			else
				Show_info(Info_message_order_flow);
		else
			Show_info(Info_message_illegal_entrance);
	Get_rid_of_RestLine();
	#ifdef Enable_print_small_line_after_every_entrance
	Print_small_line();
	#endif
	}while(!check);
	#if (defined Print_small_line_after_get)&&(!(Enable_print_small_line_after_every_entrance))
	Print_small_line();
	#endif
	return (unsigned int) result;
}

char* Get_a_name(void)
//if allocation failed return NULL
{
	char *point=(char *)malloc(Max_part_name_length+1);
	if(point==NULL) return NULL;
	printf("Please enter a name:");
	unsigned long n=0;
	char ch;
	while((ch=getchar())!='\n')
		if(n<Max_part_name_length)
		{
			*(point+n)=ch;
			n++;
		}
	*(point+n)='\0';
	#ifdef Print_small_line_after_get
	Print_small_line();
	#endif
	return point;
}

unsigned int Get_an_amount(void)
{
	long  long result;
	bool check;
	do
	{
		check=false;
		printf("Please enter an amount:");
		if(scanf("%lld",&result)==1)
			if(result<=UINT_MAX&&result>=1)
				check=true;
			else
				Show_info(Info_message_amount_flow);
		else
			Show_info(Info_message_illegal_entrance);
	Get_rid_of_RestLine();
	#ifdef Enable_print_small_line_after_every_entrance
	Print_small_line();
	#endif
	}while(!check);
	#if (defined Print_small_line_after_get)&&(!(Enable_print_small_line_after_every_entrance))
	Print_small_line();
	#endif
	return (unsigned int) result;
}

float Get_a_price(void)
{
	float result;
	bool check;
	do
	{
		check=false;
		printf("Please enter a price:");
		if(scanf("%f",&result)==1)
			if(result>1.0f)
				check=true;
			else
				Show_info(Info_message_price_flow);
		else
			Show_info(Info_message_illegal_entrance);
	Get_rid_of_RestLine();
	#ifdef Enable_print_small_line_after_every_entrance
	Print_small_line();
	#endif
	}while(!check);
	#if (defined Print_small_line_after_get)&&(!(Enable_print_small_line_after_every_entrance))
	Print_small_line();
	#endif
	return result;
}

unsigned char Get_price_percentage(void)
{
	int result;
	bool check;
	do
	{
		check=false;
		printf("Please enter price percentage:");
		if(scanf("%d",&result)==1)
			if(result<=UCHAR_MAX&&result>=1)
				check=true;
			else
				Show_info(Info_message_price_percentage_flow);
		else
			Show_info(Info_message_illegal_entrance);
	Get_rid_of_RestLine();
	#ifdef Enable_print_small_line_after_every_entrance
	Print_small_line();
	#endif
	}while(!check);
	#if (defined Print_small_line_after_get)&&(!(Enable_print_small_line_after_every_entrance))
	Print_small_line();
	#endif
	return (unsigned char) result;
}

struct part *Get_a_part(void)
//WARNING failed using by existing...
//if failed allocation struct part return NULL
//if failed allocation string, free allocation for struct part automatically
{
	struct part *result=(struct part *)malloc(sizeof(struct part));
	if (result==NULL) return NULL;
	result->name=Get_a_name();
	if (result->name==NULL)
	{
		free(result);
		return NULL;
	}
	result->number=Get_a_number();
	result->amount=Get_an_amount();
	result->price_percentage=Get_price_percentage();
	return result;
}

struct part *Locate_a_part_by_number(unsigned short number)
//if equal return the one before accurate point
//else return the one before the first point larger than it
//if reach the final return the last one
//WARNING at least large than one thing,if not return NULL
{
	struct part *previous = NULL;
	for(struct part *present=inventory_first_point;present!=NULL;previous=present,present=present->next)
		if(present->number>=number) break;
	return previous;
}

void Insert_a_part(struct part *new_part)
//WARNING new_part mustn't equal any thing by number
{
	struct part *insert_point=Locate_a_part_by_number(new_part->number);
	if(insert_point==NULL)
	{
		new_part->next=inventory_first_point;
		inventory_first_point=new_part;
	}
	else
	{
		new_part->next=insert_point->next;
		insert_point->next=new_part;
	}
}

bool Decent_match(char *s1, char *s2)
{
	int len1 = strlen(s1), len2 = strlen(s2);
	if (len1<len2) return false;
	bool result = false;
	bool temp;
	for (int i = 1; !result && (i <= len1 - len2 + 1); i++)
	{
		temp = true;
		for (int t = 1; temp&&t <= len2; t++)
			if (toupper(s1[i + t - 2]) != toupper(s2[t - 1])) temp = false;
		result = temp;
	}
	return result;
}

void Show_part_by_point(struct part *previous_part)
{
	struct part *show_part;
	if (previous_part == NULL)
		show_part = inventory_first_point;
	else
		show_part = previous_part->next;
	printf("Number:%hu\n",show_part->number);
	printf("Name:%s\n",show_part->name);
	printf("Amount:%u\n",show_part->amount);
	printf("Price:%.2f\n",show_part->price);
	if(show_part->price_percentage!=100)
		if(show_part->price_percentage<100)
			printf("Discount price:%.2f\n",(show_part->price)*(show_part->price_percentage)/100.0f);
		else
			printf("Upcount price:%.2f\n",(show_part->price)*(show_part->price_percentage)/100.0f);
	#ifdef Enable_print_small_line_after_show_part
	Print_small_line();
	#endif
}

void Remove_a_part(struct part *previous_part)
//INFO it will free it
{
	if(previous_part==NULL)
	{
		struct part *temp=inventory_first_point;
		inventory_first_point=inventory_first_point->next;
		free(temp);
	}
	struct part *temp=previous_part->next->next;
	free(previous_part->next->name);
	free(previous_part->next);
	previous_part->next=temp;
}

void Modify_part_by_point(struct part *modify_part)
//WARNING can't clean a part please clear by the function which called it
{
	char ch=Get_a_upper_range('A','D',"A--name  B--amount  C--price  D--price_percentage","Please enter your selection:");
	switch(ch)
	{
		case 'A':modify_part->name = Get_a_name(); break;
		case 'B':modify_part->amount=Get_amount_change(modify_part->amount);
		case 'C':modify_part->price=Get_a_price();break;
		case 'D':modify_part->price=Get_price_percentage();break;
	}
}

unsigned int Get_amount_change(unsigned int former_amount)
{
	long change;
	bool check;
	do
	{
		check=false;
		printf("Please enter a change(+/-):");
		if(scanf("%ld",&change)==1)
			if(change+former_amount>=0&&change+former_amount<=UINT_MAX)
				check=true;
			else
				Show_info(Info_message_amount_change_flow);
		else
			Show_info(Info_message_illegal_entrance);
	Get_rid_of_RestLine();
	#ifdef Enable_print_small_line_after_every_entrance
	Print_small_line();
	#endif
	}while(!check);
	#if (defined Print_small_line_after_get)&&(!(Enable_print_small_line_after_every_entrance))
	Print_small_line();
	#endif
	return change+former_amount;
}