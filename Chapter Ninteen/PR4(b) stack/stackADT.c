#include <stdlib.h>
#include <stdbool.h>

#include "stackADT.h"

struct stack_type
{
	struct node *top;
	size_t present_amount;
	size_t limit;
};

struct node
{
	Item value;
	struct node *next;
};

extern Stack* Create_stack(size_t limit)
//If failed return NULL
{
	Stack p=(Stack)malloc(sizeof(struct stack_type));
	if (p==NULL) return NULL;
	p->limit=limit;
	p->present_amount=0;
	p->top=NULL;
	return p;
}

extern void Delete_stack(Stack s)
{
	Release_node(s->top);
	free(s);
}

extern bool Insert_data_into_stack_back(Stack s, Item value)
//If failed return NULL
//(a)stack is full
//(b)stack alloaction failed
{
	if(Is_stack_full(s)) return false;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	if (temp==NULL) return false;
	temp->value=value;
	temp->next=NULL;
	struct node**p=Find_last_data_pointer(s);
	*p=temp;
	s->present_amount++;
	return true;
}

extern bool Insert_data_into_stack_front(Stack s, Item value)
//If failed return NULL
//(a)stack is full
//(b)stack alloaction failed
{
	if(Is_stack_full(s)) return false;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	if (temp==NULL) return false;
	temp->next=s->top;
	s->top=temp;
	s->present_amount++;
	return true;
}

extern bool Pop_stack_front(Stack s, Item *get)
//If failed return false
//(a) stack is empty
{
	if(Is_stack_empty(s)) return false;
	*get=s->top->value;
	struct node *temp=s->top;
	s->top=temp->next;
	s->present_amount--;
	free(temp);
	return true;
}

extern bool Pop_stack_back(Stack s, Item *get)
{
	if(Is_stack_empty(s)) return false;
	struct node **p=Find_last_data_pointer(s);
	*get=(*p)->value;
	free(*p);
	*p=NULL;
	return true;
}

extern size_t Find_ID_value(Stack s,Item value)
//if not found return zero
{
	size_t count=0;
	struct node *p;
	for(p=s->top;p!=NULL;p=p->next)
	{
		count++;
		if(p->value==value) return count;
	}
	return 0;
}

static inline struct node **Find_last_node_pointer(Stack s)
{
	struct node **p;
	for(p=&(s->top);(*p)->next!=NULL;p=&((*p)->next)) continue;
	return p;
}

static inline struct node **Find_last_data_pointer(Stack s)
{
	struct node **p;
	for(p=&(s->top);*p!=NULL;p=&((*p)->next)) continue;
	return p;
}

static void Release_node(struct node *top)
{
	if(top==NULL) return;
	if(top->next==NULL) free(top);
	else
	{
		Release_node(top->next);
		free(top);
	}
}

static inline bool Is_stack_full(Stack s)
{
	return s->present_amount>=s->limit;
}

static inline bool Is_stack_empty(Stack s)
{
	return s->present_amount==0;
}
