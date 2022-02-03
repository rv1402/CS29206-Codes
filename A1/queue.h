#include "llist.h"

typedef LLIST QUEUE;

QUEUE createQueue();
int isEmptyQueue(QUEUE);
QUEUE enqueue(QUEUE, int);
QUEUE dequeue(QUEUE, int *);
void printQueue(QUEUE);