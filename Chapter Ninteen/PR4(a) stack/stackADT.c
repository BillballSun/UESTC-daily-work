#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "stackADT.h"

struct stack_type
{
	Item *top;
	size_t present_amount;
	size_t limit;
};

extern Stack* Create_stack(size_t limit)
//If failed return NULL
{
	Stack p=(Stack)malloc(sizeof(struct stack_type));
	Item *temp=(Item *)malloc(sizeof(Item)*limit)
	if (p==NULL||temp==NULL) 
	{
		free(p);
		free(temp);
		return NULL;
	}
	p->limit=limit;
	p->present_amount=0;
	p->top=temp;
	return p;
}

extern void Delete_stack(Stack s)
{
	free(s->top);
	free(s);
}

extern bool Insert_data_into_stack_back(Stack s, Item value)
//If failed return NULL
//(a)stack is full
{
	if(Is_stack_full(s)) return false;
	*(s->top+present_amount)=value;
	s->present_amount++;
	return true;
}

extern bool Insert_data_into_stack_front(Stack s, Item value)
//If failed return NULL
//(a)stack is full
{
	if(Is_stack_full(s)) return false;
	for(size_t i=present_amount;i>=1;i--)
		memmove((void *)s->top[i],(void *)s->top[i-1],sizeof(Item));
	*(s->top)=value;
	s->present_amount++;
	return true;
}

extern bool Pop_stack_front(Stack s, Item *get)
//If failed return false
//(a) stack is empty
{
	if(Is_stack_empty(s)) return false;
	*get=*(s->top);
	for(size_t i=0;i<=present_amount-2;i++)
		memmove((void *)s->top[i],(void *)s->top[i+1],sizeof(Item));
	s->present_amount--;
	return true;
}

extern bool Pop_stack_back(Stack s, Item *get)
{
	if(Is_stack_empty(s)) return false;
	*get=*(s->top+present_amount-1);
	s->present_amount--;
	return true;
}

extern size_t Find_ID_value(Stack s,Item value)
//if not found return zero
{
	for(size_t count=1;count<=present_amount;count++)
		if(s->top[count-1]==value) return count;
	return 0;
}

static inline bool Is_stack_full(Stack s)
{
	return s->present_amount==s->limit;
}

static inline bool Is_stack_empty(Stack s)
{
	return s->present_amount==0;
}
