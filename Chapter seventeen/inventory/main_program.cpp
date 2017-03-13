#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

#include "external.h"

#include "error_message_macro.h"

#include "main_program.h"
#include "structure.h"
#include "supporting_function.h"
#include "info.h"

void Add_process(void);
void Delete_process(void);
void Print_process(void);
void Modify_process(void);
void Search_process(void);

void Main_program(void)
{
	char ch;
	bool exitpoint=false;
	do
	{
		do
		{
			printf("a--Add  d--Delete  p--Print  m--Modify  s--Search  e-Exit\n");
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
	struct part *new_part=(struct part *)malloc(sizeof(struct part));
	if(new_part==NULL)
	{
		Show_info(Info_message_allocation_failed);
		return;
	}
	new_part->number=Get_a_number();
	struct part *test=Locate_a_part_by_number(new_part->number);
	if(test==NULL&&inventory_first_point!=NULL&&inventory_first_point->number==new_part->number)
	{
		free(new_part);
		Show_part_by_point(NULL);
		#ifndef Enable_print_small_line_after_show_part
		Print_small_line();
		#endif
		printf("Parts already existing in inventory.\n");
		inventory_first_point->amount = Get_amount_change(inventory_first_point->amount);
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
	else if(test!=NULL&&test->next!=NULL)
	{
		free(new_part);
		Show_part_by_point(test);
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

void Delete_process(void)
{
	printf("===Delete process===\n");
	if(inventory_first_point==NULL)
	{
		Show_info(Info_message_inventory_empty);
	}
	size_t amount=0;
	struct part **link_point=(struct part **)malloc(sizeof(struct part *));
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
		Show_part_by_point(link_point[i-1]);
		#ifndef Enable_print_small_line_after_show_part
		Print_small_line();
		#endif
	}
	if(Get_Y_or_N("Are you sure to delete all of them"))
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
	if (inventory_first_point == NULL)
	{
		Show_info(Info_message_inventory_empty);
		return;
	}
	struct  part *p;
	struct  part *pre;
	for (p = inventory_first_point, pre = NULL; p != NULL; pre = p, p = p->next)
	{
		Show_part_by_point(pre);
		#ifndef Enable_print_small_line_after_show_part
		if (p->next != NULL) Print_small_line();
		#endif
	}
}

void Modify_process(void)
{
	printf("===Modify process===\n");
	size_t amount=0;
	struct part **link_point=(struct part **)malloc(sizeof(struct part *));
	if(link_point==NULL) 
	{
		Show_info(Info_message_allocation_failed);
		return;
	}
	printf("How to locate the one for modifying\n");
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
		Show_part_by_point(link_point[i-1]);
		#ifndef Enable_print_small_line_after_show_part
		Print_small_line();
		#endif
		if(link_point[i-1]==NULL)
			Modify_part_by_point(inventory_first_point);
		else
			Modify_part_by_point(link_point[i-1]->next);
		if(i<amount) Print_small_line();
	}
	free(link_point);
}

void Search_process(void)
{
	printf("===Search process===\n");
	size_t amount=0;
	struct part **link_point=(struct part **)malloc(sizeof(struct part *));
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
		Show_part_by_point(link_point[i-1]);
		#ifndef Enable_print_small_line_after_show_part
		if (i<amount) Print_small_line();
		#endif
	}
	free(link_point);
}
