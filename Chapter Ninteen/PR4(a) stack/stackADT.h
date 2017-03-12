#ifndef HEAD_stackADT
#define HEAD_stackADT
#include <stdbool.h>
typedef int Item
typedef struct stack_type *Stack;
extern Stack* Create_stack(size_t limit);
extern void Delete_stack(Stack s);
extern bool Insert_data_into_stack_back(Stack s, Item value);
extern bool Insert_data_into_stack_front(Stack s, Item value);
extern bool Pop_stack_front(Stack s, Item *get);
extern bool Pop_stack_back(Stack s, Item *get);
extern size_t Find_ID_value(Stack s,Item value);
#endif
