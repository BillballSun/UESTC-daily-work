#ifndef HEAD_queueADT
#define HEAD_queueADT

typedef struct queue *Queue;

/******************************************************
 *Safe_mode enable pointer
 *the effect will show in each box for functions
 ******************************************************/
#if 0
#define Safe_mode
#endif

/******************************************************
 *Create_queue generate a queue by allocation
 *return a queue pointer
 *if allocation failed return NULL
 *MACRO_Safe_mode: if size or len equals to zero return NULL
 ******************************************************/
Queue Create_queue(size_t data_size, size_t queue_len);

/******************************************************
 *Destroy_queue will destroy a queue
 *client must make sure it points to a queue
 *MACRO_Safe_mode: if unlucky_queue==NULL do nothing
 ******************************************************/
void Destroy_queue(Queue unlucky_queue);

/******************************************************
 *Insert_front_queue will insert an item to front
 *Please make sure they match in type
 *if the queue is full return false else return true
 ******************************************************/
bool Insert_front_queue(Queue target_queue, void *data_store);

/******************************************************
 *Insert_back_queue will insert it to the back of the queue
 *Please make sure they match in type
 *if the queue is full return false else return true
 ******************************************************/
bool Insert_back_queue(Queue target_queue, void *data_store);

/******************************************************
 *Pop_from_the_front will pop from the front
 *if queue is empty return false and do nothing
 ******************************************************/
bool Pop_from_the_front(Queue target_queue, void *data_store);

/******************************************************
 *Pop_from_the_back will pop from the back
 *if queue is empty then return false do nothing
 ******************************************************/
bool Pop_from_the_back(Queue target_queue, void *data_store);

/******************************************************
 *Enlarge_queue will enlarge the len of data
 *it won't change the data type
 *if failed in reallocation return false
 *MACRO_Safe_mode: if len==0 return queue
 ******************************************************/
bool Enlarge_queue(Queue target_queue, size_t extra_len);

/******************************************************
 *Trim_queue_proper will decrease the len of queue
 *as possible
 *depending on the present_amount
 *if present_amount==0 it will at least remain len==1
 *MACRO_Safe_mode: if realloc failed do nothing
 ******************************************************/
void Trim_queue_proper(Queue target_queue);

bool Is_queue_full(Queue target_queue);

bool Is_queue_empty(Queue target_queue);

#endif
