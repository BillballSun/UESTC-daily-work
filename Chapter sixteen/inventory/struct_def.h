#include "inventory_control.h"

#ifndef HEAD_struct_def
#define HEAD_struct_def
struct component
{
	signed short number;
	char name[Max_component_name_length+1];
	unsigned long present_amount;
};
#endif