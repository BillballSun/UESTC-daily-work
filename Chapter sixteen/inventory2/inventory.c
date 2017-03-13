/*********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may  not be freely distributed,          *
* provided that this copyright notice is retained.      *
**********************************************************/
/* PR1.c (Chapter 13, page 210) */
#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h> /* scanf printf getchar putchar */
#include <stdlib.h> /* system abs(int) srand rand exit EXIT_SUCCESS EXIT_FAILURE malloc calloc realloc free */
#include <stdbool.h> /* bool true false */
#include <ctype.h> /* toupper tolower isalpha isupper islower isspace */
#include <math.h> /* sqrt fabs(double) trunc */
#include <string.h> /* mencpy strcpy(n) strlen strcat(n) strcmp */
#include <time.h> /* time */

#if 0 //limit.h
#define HEAD_limit
#define UCHAR_MAX     0xff                         // maximum unsigned char value
#define USHRT_MAX     0xffff                       // maximum unsigned short value
#define UINT_MAX      0xffffffff                   // maximum unsigned int value

#ifndef SIZE_MAX                                   //SIZE_MAX size_t max defination
#ifdef _WIN64
#define SIZE_MAX _UI64_MAX
#else
#define SIZE_MAX UINT_MAX
#endif
#endif

#endif

#define Info_message_number_flow 1
#define Info_message_amount_flow 2
#define Info_message_price_percentage_flow 3
#define Info_message_illegal_entrance 4
#define Info_message_allocation_failed 5
#define Info_message_added_succesfully 6
#define Info_message_inventory_empty 7

#define Max_part_name_length 64 //from 1 to (Max_size_t-1)

#if 0 //useful control
#define Enable_print_small_line_after_get
#define Enable_print_small_line_after_every_entrance
#define Enable_print_small_line_after_show_part
#define Enable_print_small_line_after_Y_or_N
#endif

struct part
{
	unsigned short number;
	//range from 1 to USHRT_MAX
	char *name;
	//allocation
	unsigned int amount;
	//range from 1 to UINT_MAX
	float price;
	unsigned char *price_percentage;
	//range from 1 to UCHAR_MAX
	struct part *next;
};

struct part *inventory_first_point=NULL;

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
		printf("Please enter a number:");
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
			if(price>1.0f)
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
	struct part *result=malloc(sizeof(struct part));
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
	struct part *previous=NULL,present;
	for(struct part *present=inventory_first_point;present!=NULL;previous=present,present=present->next)
		if(present->number<=number) break;
	return previous;
}

void Insert_a_part(struct part *new_part)
//WARNING new_part mustn't equal any thing by number
{
	struct part *insert_point=Locate_a_part_by_number(new_item->number);
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
	for(struct part *p=inventory_first_point,pre=NULL;p!=NULL;pre=p,p=p->next)
		if(p->number==find_number)
		{
			struct part **temp=realloc(*link_point,(*amount+1)*(struct part *));
			if(temp==NULL)
			{
				free(*link_point);
				*link_point=NULL;
				return;
			}
			*link_point=temp;
			*((*link_point)+amount)=pre;
			amount++;
		}
}


void Find_by_name_process(struct part ***link_point, size_t *amount)
{
	char* find_name=Get_a_name();
	#if !(defined Enable_print_small_line_after_every_entrance)&& !(defined Enable_print_small_line_after_get)
	Print_small_line();
	#endif
	for(struct part *p=inventory_first_point,pre=NULL;p!=NULL;pre=p,p=p->next)
		if(strcmp(p->name,find_name))
		{
			struct part **temp=realloc(*link_point,(*amount+1)*(struct part *));
			if(temp==NULL)
			{
				free(*link_point);
				*link_point=NULL;
				return;
			}
			*link_point=temp;
			*((*link_point)+amount)=pre;
			amount++;
		}
	if(*link_point!=NULL&&amount==0)
		if(Get_Y_or_N("No found at present, hope a decent finding"))
		{
			#ifndef Enable_print_small_line_after_Y_or_N
			Print_small_line();
			#endif
			for(struct part *p=inventory_first_point,pre=NULL;p!=NULL;pre=p,p=p->next)
			if(Decent_match(p->name,find_name))
			{
				struct part **temp=realloc(*link_point,(*amount+1)*(struct part *));
				if(temp==NULL)
				{
					free(*link_point);
					*link_point=NULL;
					return;
				}
				*link_point=temp;
				*((*link_point)+amount)=pre;
				amount++;
			}
		}
}

bool Get_Y_or_N(char *info)
{
	char ch;
	do
	{
		printf("%s(Y/N)--", info);
		ch = Get_a_upper_letter();
	} while (ch != 'Y'&&ch != 'N');
	#ifdef Enable_print_small_line_after_Y_or_N
	Print_small_line();
	#endif
	return ch == 'Y';
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

void Find_by_amount_process(struct part ***link_point, size_t *amount)
{
	unsigned int find_amount=Get_a_price();
	#if !(defined Enable_print_small_line_after_every_entrance)&& !(defined Enable_print_small_line_after_get)
	Print_small_line();
	#endif
	for(struct part *p=inventory_first_point,pre=NULL;p!=NULL;pre=p,p=p->next)
		if(p->price==find_price)
		{
			struct part **temp=realloc(*link_point,(*amount+1)*(struct part *));
			if(temp==NULL)
			{
				free(*link_point);
				*link_point=NULL;
				return;
			}
			*link_point=temp;
			*((*link_point)+amount)=pre;
			amount++;
		}
}

void Find_by_price_process(struct part ***link_point, size_t *amount)
{
	float find_price=Get_a_price();
	#if !(defined Enable_print_small_line_after_every_entrance)&& !(defined Enable_print_small_line_after_get)
	Print_small_line();
	#endif
	for(struct part *p=inventory_first_point,pre=NULL;p!=NULL;pre=p,p=p->next)
		if(p->amount==find_amount)
		{
			struct part **temp=realloc(*link_point,(*amount+1)*(struct part *));
			if(temp==NULL)
			{
				free(*link_point);
				*link_point=NULL;
				return;
			}
			*link_point=temp;
			*((*link_point)+amount)=pre;
			amount++;
		}
}

void Find_by_order_process(struct part ***link_point, size_t *amount)
{
	unsigned int find_order=Get_an_order();
	#if !(defined Enable_print_small_line_after_every_entrance)&& !(defined Enable_print_small_line_after_get)
	Print_small_line();
	#endif
	unsigned int count=0;
	for(struct part *p=inventory_first_point,pre=NULL;p!=NULL;pre=p,p=p->next)
	{
		count++;
		if(count==find_order)
		{
			struct part **temp=realloc(*link_point,(*amount+1)*(struct part *));
			if(temp==NULL)
			{
				free(*link_point);
				*link_point=NULL;
				return;
			}
			*link_point=temp;
			*((*link_point)+amount)=pre;
			amount++;
			break;
		}
	}
}

void Show_part_by_point(struct part *show_part)
{
	printf("Number:%hu\n",show_part->number);
	printf("Name:%s\n",show_part->name);
	printf("Amount:%u\n",show_part->amount);
	printf("Price:%.2f\n",show_part->price);
	if(show_part->price_percentage!=100)
		if(show_part->price_percentage<100)
			printf("Discount price:%f\n",show_part->price*show_part->price_percentage);
		else
			printf("Upcount price:%f\n",show_part->price*show_part->price_percentage);
	#ifdef Enable_print_small_line_after_show_part
	Print_small_line();
	#endif
}



int main(int argc, char argv[])
{
	Show_start_info();
	Main_program();
	Show_exit_info();
	return EXIT_SUCCESS;
}

void Main_program(void)
{
	char ch;
	bool exitpoint=false;
	do
	{
		do
		{
			printf("a--Add  d--Delete  p--Print  m--Modify  s--Search  e-Exit");
			printf("Please enter your selection:");
			ch=Get_a_upper_letter();
		}while(ch!='A'&&ch!='D'&&ch!='P'&&ch!='M'&&ch!='S'&&ch!='E');
		switch(ch)
		{
			case 'A':Add_process();break;
			case 'D':Delete_process();break;
			case 'P':Print_process();break;
			case 'M':Modify_process();break;
			case 'S':Search_process();break;
			case 'E':exitpoint=true;break;
		}
	Print_divide_line();
	}while(!exitpoint);
}

void Add_process(void)
{
	printf("===Add process===\n");
	struct part *new_part=malloc(sizeof(struct part));
	if(new_part==NULL)
	{
		Show_info(Info_message_allocation_failed);
		return;
	}
	new_part->number=Get_a_number();
	struct part *test=Locate_a_part_by_number(new_part->number);
	if(test==NULL)
		if(inventory_first_point!=NULL)
		{
			free(new_part);
			Show_part_by_point(inventory_first_point);
			#ifndef Enable_print_small_line_after_show_part
			Print_small_line();
			#endif
			printf("Parts already existing in inventory.\n");
			inventory_first_point->amount=Get_amount_change(inventory_first_point->amount)
			if(inventory_first_point->amount==0)
			{
				Remove_a_part(test);
				Show_info(Info_message_part_removed);
				return;
			}
			else
			{
				Show_info(Info_message_part_changed);
				return;
			}
		}
	else
		if(test->next!=NULL)
		{
			free(new_part);
			Show_part_by_point(test->next);
			#ifndef Enable_print_small_line_after_show_part
			Print_small_line();
			#endif
			printf("Parts already existing in inventory.\n");
			test->next->amount=Get_amount_change(test->next->amount);
			if(test->next->amount==0)
			{
				Remove_a_part(test);
				Show_info(Info_message_part_removed);
				return;
			}
			else
			{
				Show_info(Info_message_part_changed);
				return;
			}
		}
	new_part->name=Get_a_name();
	new_part->amount=Get_an_amount();
	new_part->price=Get_a_price();
	new_part->price_percentage=Get_price_percentage();
	Insert_a_part(new_part);
	Show_info(Info_message_added_succesfully);
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
	ch=Get_a_upper_range('A','D',"A--name  B--amount  C--price  D--price_percentage","Please enter your selection:");
	switch(ch)
	{
		case 'A':modify_part->name=Get_a_name()break;
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
				Show_info(Info_message_price_change_flow);
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

void Delete_process(void)
{
	printf("===Delete process===\n");
	if(inventory_first_point==NULL)
	{
		Show_info(Info_message_inventory_empty);
	}
	size_t amount=0;
	struct part **link_point=malloc(sizeof(struct part *));
	if(link_point==NULL) 
	{
		Show_info(Info_message_allocation_failed);
		return;
	}
	Find_parts(&link_point,&amount);
	if(link_point==NULL)
	{
		Show_info(Info_message_allocation_failed);
		return;
	}
	if(amount==0)
	{
		Show_info(Info_message_no_finding);
		return;
	}
	for(size_t i=1;i<=amount;i++)
	{
		Show_part_by_point(part[i-1]);
		#ifndef Enable_print_small_line_after_show_part
		Print_small_line();
		#endif
	}
	if(Get_Y_or_N(Are you sure to delete all of them))
	{
		#ifndef Enable_print_small_line_after_Y_or_N
		Print_small_line();
		#endif
		for(size_t i=1;i<=amount;i++)
			Remove_a_part(link_point[i-1]);
	}
	else
	{
		#ifndef Enable_print_small_line_after_Y_or_N
		Print_small_line();
		#endif
		Show_info(Info_message_process_canceled);
		
	}
	free(link_point);
}

void Print_process(void)
{
	printf("===Print process===\n");
	size_t amount=0;
	struct part **link_point=malloc(sizeof(struct part *));
	if(link_point==NULL) 
	{
		Show_info(Info_message_allocation_failed);
		return;
	}
	Find_parts(&link_point,&amount);
	if(link_point==NULL)
	{
		Show_info(Info_message_allocation_failed);
		return;
	}
	if(amount==0)
	{
		Show_info(Info_message_no_finding);
		return;
	}
	for(size_t i=1;i<=amount;i++)
	{
		Show_part_by_point(part[i-1]);
		#ifndef Enable_print_small_line_after_show_part
		Print_small_line();
		#endif
	}
	free(link_point);
}

void Modify_process(void)
{
	printf("===Modify process===\n");
	size_t amount=0;
	struct part **link_point=malloc(sizeof(struct part *));
	if(link_point==NULL) 
	{
		Show_info(Info_message_allocation_failed);
		return;
	}
	Find_parts(&link_point,&amount);
	if(link_point==NULL)
	{
		Show_info(Info_message_allocation_failed);
		return;
	}
	if(amount==0)
	{
		Show_info(Info_message_no_finding);
		return;
	}
	for(size_t i=1;i<=amount;i++)
	{
		Show_part_by_point(part[i-1]);
		#ifndef Enable_print_small_line_after_show_part
		Print_small_line();
		#endif
		if(link_point[i-1]==NULL)
			Modify_part_by_point(inventory_first_point);
		else
			Modify_part_by_point(link_point[i-1]->next);
		Print_small_line();
	}
	free(link_point);
}

void Search_process(void)
{
	printf("===Search process===\n");
	size_t amount=0;
	struct part **link_point=malloc(sizeof(struct part *));
	if(link_point==NULL) 
	{
		Show_info(Info_message_allocation_failed);
		return;
	}
	Find_parts(&link_point,&amount);
	if(link_point==NULL)
	{
		Show_info(Info_message_allocation_failed);
		return;
	}
	if(amount==0)
	{
		Show_info(Info_message_no_finding);
		return;
	}
	for(size_t i=1;i<=amount;i++)
	{
		Show_part_by_point(part[i-1]);
		#ifndef Enable_print_small_line_after_show_part
		Print_small_line();
	}
	free(link_point);
}

char Get_a_upper_range(char begin, char end ,char *option ,char *message)
{
	char ch;
	do
	{
		printf("%s\n",option);
		printf("%s",message);
		ch = Get_a_upper_letter();
		Print_small_line();
	} while (ch<begin || ch>end);
}

char Get_a_upper_letter(void)
{
	char ch;
	if ((ch = toupper(getchar())) != '\n') Get_rid_of_RestLine();
	return ch;
}











