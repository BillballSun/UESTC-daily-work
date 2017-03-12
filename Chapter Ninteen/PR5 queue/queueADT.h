#ifndef HEAD_queueADT
#define HEAD_queueADT
typedef struct queue *Queue;

extern Queue Create_queue(size_t element_size, size_t element_len);
//If failed return NULL
//(a) allocation failed

extern void Destroy_queue(Queue);
//Client must make sure q is the pointer to queue

extern bool Insert_to_front_queue(Queue, void *your_data_pointer);
//Client must make sure data match the data in the queue
//If failed return false
//(a) queue is full

extern bool Pop_from_back_queue(Queue, void *your_data_pointer);
//Client must make sure data match the data in the queue
//If failed return false
//(a) queue is empty

extern bool Get_the_front(Queue, void *your_data_pointer);
//Client must make sure data match the data in the queue
//If failed return false
//(a) queue is empty

extern bool Get_the_back(Queue, void *your_data_pointer);
//Client must make sure data match the data in the queue
//If failed return false
//(a) queue is empty

extern bool Is_queue_full(Queue);

extern inline bool Is_queue_empty(Queue);
#endif
