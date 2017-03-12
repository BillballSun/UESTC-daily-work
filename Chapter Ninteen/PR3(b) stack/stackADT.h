#ifndef HEAD_stackADT
#define HEAD_stackADT

#include <stdbool.h>

typedef int Item;
typedef struct stack *Stack;

Stack Create_stack(void)
//if allocation failed return NULL

bool Insert_data_to_stack(Stack s, Item value)
//if allocation failed return false

bool Pop_data_from_stack(Stack s, Item *value)
//if stack empty return false, result stored in value

#endif