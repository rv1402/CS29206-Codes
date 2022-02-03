typedef LLIST QUEUE;

extern QUEUE createQueue();
extern int isEmptyQueue(QUEUE);
extern QUEUE enqueue(QUEUE, int);
extern QUEUE dequeue(QUEUE, int *);
extern void printQueue(QUEUE);