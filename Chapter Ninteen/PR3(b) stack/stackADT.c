#include <stdbool.h>
#include <stdlib.h>

#include "stackADT.h"

typedef struct node *Node;


struct node
{
	Item value;
	struct node *next;
}

struct stack
{
	struct node *begin;
	struct node *end;
};

Stack Create_stack(void)
//if allocation failed return NULL
{
	Stack temp=(Stack)malloc(struct stack);
	if(temp==NULL) return NULL;
	temp->begin=NULL;
	temp->end=NULL;
	return temp;
}

bool Insert_data_to_stack(Stack s, Item value)
//if allocation failed return false
{
	Node temp=(Node)malloc(sizeof(struct node));
	if(temp==NULL) return false;
	temp->value=value;
	temp->next=NULL;
	if(s->begin==NULL) s->begin=temp;
	else s->end->next=temp;
	s->end=temp;
	return true;
}

bool Pop_data_from_stack(Stack s, Item *value)
//if stack empty return false, result stored in value
{
	if(Is_stack_empty(s)) return false;
	Node temp=s->begin;
	s->begin=s->begin->next;
	*value=temp->value;
	free(temp);
	return false;
}

static inline bool Is_stack_empty(Stack s)
{
	return s->begin==NULL;
}
