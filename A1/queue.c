#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include "queue.h"

QUEUE createQueue(){
    return createList();
}

int isEmptyQueue(QUEUE Q){
    if(Q == NULL)
        return 1;
    return 0;
}

QUEUE enqueue(QUEUE Q, int k){
    Q = insertAtEnd(Q, k);
    return Q;
}

QUEUE dequeue(QUEUE Q, int *k){
    Q = deleteFromFront(Q, k);
    return Q;
}

void printQueue(QUEUE Q){
    if(isEmptyQueue(Q)){
        printf("Queue is Empty.\n");
        return;
    }
    else if(isEmptyQueue(Q->next)){
        printf("Front, Back: %d\n", Q->value);
        return;
    }
    printf("Front: %d\n", Q->value);
    Q = Q->next;
    while(Q->next != NULL){
        printf("Val: %d\n", Q->value);
        Q = Q->next;
    }
    printf("Back: %d\n", Q->value);
}