#include <stdio.h>
#include <limits.h>

#include "error_message_macro.h"

#include "info.h"
#include "structure.h"

void Show_start_info(void)
{
	printf("--------------Amazing CA inc program-----------------\n");
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n\n");
	printf("New inventory\n");
	Print_divide_line();
}

void Show_exit_info(void)
{
	printf("Copyright (c) 2016, 1998  CaptainAllred Incorperated.\n");
	printf("The way it is meant to be used.\n");
	printf("See you next time.\n");
}

void Show_info(int code)
{
	switch (code)
	{
	case Info_message_number_flow:printf("Info: Number range from 1 to %d.\n", (int)USHRT_MAX); break;
		case Info_message_amount_flow:printf("Info: Amount range from 1 to %lu.\n",(unsigned long)UINT_MAX);break;
		case Info_message_price_percentage_flow:printf("Info: Price_percetage range from 1%% to %d%%.\n",(int)UCHAR_MAX);break;
		case Info_message_illegal_entrance:printf("Info: Illegal entrance, please check with your mind.\n");break;
		case Info_message_allocation_failed:printf("Info: Allocation failed, memory is full.\n");break;
		case Info_message_added_succesfully:printf("Info: Add item successfully done.\n");break;
		case Info_message_inventory_empty:printf("Info: Now the inventory is empty.\n");break;
		case Info_message_order_flow:printf("Info: Can\'t find the item with this order.\n");break;
		case Info_message_price_flow:printf("Info: Price must be more than zero.\n");break;
		case Info_message_part_removed:printf("Info: The item was removed successfully.\n");break;
		case Info_message_part_changed:printf("Info: The item was modified successfully.\n");break;
		case Info_message_amount_change_flow:printf("Info: The new amount must range from 1 to %lu.\n",(unsigned long)UINT_MAX);break;
		case Info_message_no_finding:printf("Info: No such match found in inventory.\n");break;
		case Info_message_process_canceled:printf("Info: Process canceled by user.\n");break;
	}
}
