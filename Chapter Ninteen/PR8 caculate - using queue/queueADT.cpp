#include <stdlib.h>
#include <string.h>

struct queue
{
	void *data;
	size_t size;
	size_t len;
	size_t present_amount;
};

#include "queueADT.h"


static void Moving_queue_one_step_right(Queue q);
static void Moving_queue_one_step_left(Queue q);
static void *Locate_data_pointer(Queue q, size_t order);

/******************************************************
 *Create_queue generate a queue by allocation
 *return a queue pointer
 *if allocation failed return NULL
 *MACRO_Safe_mode: if size or len equals to zero return NULL
 ******************************************************/
Queue Create_queue(size_t size, size_t len)
{
	#ifdef Safe_mode
	if(size==0||len==0) return NULL;
	#endif
	void *new_data=malloc(size*len);
	Queue new_queue=(Queue)malloc(sizeof(struct queue));
	if(new_data==NULL||new_queue==NULL)
	{
		free(new_data);
		free(new_queue);
		return NULL;
	}
	new_queue->size=size;
	new_queue->len=len;
	new_queue->present_amount=0;
	new_queue->data=new_data;
	return new_queue;
}

/******************************************************
 *Destroy_queue will destroy a queue
 *client must make sure it points to a queue
 *MACRO_Safe_mode: if unlucky_queue==NULL do nothing
 ******************************************************/
void Destroy_queue(Queue unlucky_queue)
{
	
	#ifdef Safe_mode
	if(unlucky_queue==NULL) return;
	#endif
	free(unlucky_queue->data);
	free(unlucky_queue);
}

/******************************************************
 *Insert_front_queue will insert an item to front
 *Please make sure they match in type
 *if the queue is full return false else return true
 ******************************************************/
bool Insert_front_queue(Queue q, void *data_store)
{
	if(Is_queue_full(q)) return false;
	Moving_queue_one_step_right(q);
	memcpy(q->data, data_store, q->size);
	q->present_amount++;
	return true;
}

/******************************************************
 *Insert_back_queue will insert it to the back of the queue
 *Please make sure they match in type
 *if the queue is full return false else return true
 ******************************************************/
bool Insert_back_queue(Queue q, void *data_store)
{
	if(Is_queue_full(q)) return false;
	memcpy(Locate_data_pointer(q, q->present_amount+1), data_store, q->size);
	q->present_amount++;
	return true;
}

/******************************************************
 *Pop_from_the_front will pop from the front
 *if queue is empty return false and do nothing
 ******************************************************/
bool Pop_from_the_front(Queue q, void *data_store)
{
	if(Is_queue_empty(q)) return false;
	memcpy(data_store, q->data, q->size);
	Moving_queue_one_step_left(q);
	q->present_amount--;
	return true;
}

/******************************************************
 *Pop_from_the_back will pop from the back
 *if queue is empty then return false do nothing
 ******************************************************/
bool Pop_from_the_back(Queue q, void *data_store)
{
	if(Is_queue_empty(q)) return false;
	memcpy(data_store, Locate_data_pointer(q, q->present_amount), q->size);
	q->present_amount--;
	return true;
}
 

/******************************************************
 *Enlarge_queue will enlarge the len of data
 *it won't change the data type
 *if failed in reallocation return false
 *MACRO_Safe_mode: if len==0 return queue
 ******************************************************/
bool Enlarge_queue(Queue q, size_t extra_len)
{
	#ifdef Safe_mode
	if(len==0) return q;
	#endif
	void *new_data=realloc(q->data, (q->len+extra_len)*q->size);
	if (new_data==NULL) return false;
	q->data=new_data;
	q->len=q->len+extra_len;
	return true;
}

/******************************************************
 *Trim_queue_proper will decrease the len of queue
 *as possible
 *depending on the present_amount
 *if present_amount==0 it will at least remain len==1
 *MACRO_Safe_mode: if realloc failed do nothing
 ******************************************************/
void Trim_queue_proper(Queue q)
{
	size_t new_len;
	if(q->present_amount==0)
		new_len=1;
	else
		new_len=q->present_amount;
	#ifdef Safe_mode
	void *temp=
	#endif
	realloc(q->data, new_len*q->size);
	#ifdef Safe_mode
	if(temp==NULL) return;
	#endif
	q->len=new_len;
}

/******************************************************
 *Moving_queue_one_step_right will move one step right
 *MACRO_Safe_mode: if full do nothing
 ******************************************************/
static void Moving_queue_one_step_right(Queue q)
{
	#ifdef Safe_mode
	if(Is_queue_full(q)) return;
	#endif
	for(size_t i=q->present_amount;i>=1;i--)
		memcpy(Locate_data_pointer(q,i+1),Locate_data_pointer(q,i),q->size);
}

/******************************************************
 *Moving_queue_one_step_left will move one step left
 *MACRO_Safe_mode: if empty do nothing
 ******************************************************/
static void Moving_queue_one_step_left(Queue q)
{
	#ifdef Safe_mode
	if(Is_queue_empty(q)) return;
	#endif
	for(size_t i=1;i<=q->present_amount-1;i++)
		memmove(Locate_data_pointer(q, i), Locate_data_pointer(q, i+1), q->size);
}

/******************************************************
 *Locate_data_pointer will locate the data by order
 *Safe_mode: if order goes beyong len return NULL
 ******************************************************/
static void *Locate_data_pointer(Queue q, size_t order)
{
	#ifdef Safe_mode
	if(order>q->len) return NULL;
	#endif
	return (void *)((char *)q->data+((order-1)*q->size));
}

bool Is_queue_full(Queue q)
{
	return q->present_amount==q->len;
}

bool Is_queue_empty(Queue q)
{
	return q->present_amount==0;
}
