#include <stdlib.h>
#include <string.h>

struct queue
{
	void *top;
	size_t size;
	size_t len;
	size_t present_amount;
};

#include "queueADT.h"

Public Queue Create_queue(size_t size, size_t len)
//If failed return NULL
//(a) allocation failed
{
	Queue p=(Queue)malloc(sizeof(struct queue));
	void *temp=malloc(size*len);
	if(p==NULL||temp==NULL) return NULL;
	p->top=temp;
	p->size=size;
	p->len=len;
	p->present_amount=0;
	return p;
}

public void Destroy_queue(Queue q)
//Client must make sure q is the pointer to queue
{
	free(q->top);
	free(q);
}

Public void Insert_to_front_queue(Queue q, void *data)
{
	if(Is_queue_full(q)) present_amount=0;
	void *temp=(void *)((char *)(q->top)+(q->size*p->present_amount));
	memcpy(temp, data, q->size);
	q->present_amount++;
	return true;
}

Public bool Pop_from_back_queue(Queue q, void *data)
//Client must make sure data match the data in the queue
//If failed return false
//(a) queue is empty
{
	if(Is_queue_empty(q)) return false;
	void *temp=(void *)((char *)(q->top)+(p->size*(p->present_amount-1)));
	memcpy(data, temp, p->size);
	q->present_amount--;
	return true;
}

Public bool Get_the_front(Queue q, void *data)
//Client must make sure data match the data in the queue
//If failed return false
//(a) queue is empty
{
	if(Is_queue_full(q)) return false;
	void *temp=q->top;
	memcpy(data, temp, q->size);
	return true;
}

Public bool Get_the_back(Queue q, void *data)
//Client must make sure data match the data in the queue
//If failed return false
//(a) queue is empty
{
	if(Is_queue_full(q)) return false;
	void *temp=(void *)((char *)(q->top)+(p->size*(p->present_amount-1)));
	memcpy(data, temp, q->size);
	return true;
}

Public bool Is_queue_full(Queue q)
{
	return q->present_amount==len;
}

Public inline bool Is_queue_empty(Queue q)
{
	return q->present_amount==0;
}
