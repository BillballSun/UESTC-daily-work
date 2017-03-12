#ifndef HEAD_queueADT
#define HEAD_queueADT
typedef struct queue *Queue;

Public Queue Create_queue(size_t element_size, size_t element_len);
//If failed return NULL
//(a) allocation failed

#define Public /*Empty*/
#define Private static

Public void Destroy_queue(Queue);
//Client must make sure q is the pointer to queue

Public void Insert_to_front_queue(Queue, void *your_data_pointer);

Public bool Pop_from_back_queue(Queue, void *your_data_pointer);
//Client must make sure data match the data in the queue
//If failed return false
//(a) queue is empty

Public bool Get_the_front(Queue, void *your_data_pointer);
//Client must make sure data match the data in the queue
//If failed return false
//(a) queue is empty

Public bool Get_the_back(Queue, void *your_data_pointer);
//Client must make sure data match the data in the queue
//If failed return false
//(a) queue is empty

Public bool Is_queue_full(Queue);

Public inline bool Is_queue_empty(Queue);
#endif
