#ifndef HEAD_stackADT
#define HEAD_stackADT
#include <stdbool.h>
typedef int Item
typedef struct stack_type *Stack;
extern Stack* Create_stack(size_t stack_size_limit);
extern void Delete_stack(Stack s);
extern bool Insert_data_into_stack_back(Stack s, Item insert_value);
extern bool Insert_data_into_stack_front(Stack s, Item insert_value);
extern bool Pop_stack_front(Stack s, Item *get_value);
extern bool Pop_stack_back(Stack s, Item *get_value);
extern size_t Find_ID_value(Stack s,Item finding_value);
static inline bool Is_stack_full(Stack s);
static inline bool Is_stack_empty(Stack s);
#endif
