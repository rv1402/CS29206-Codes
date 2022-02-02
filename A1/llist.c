#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

typedef struct{
    int value;
    NODE *next;
}NODE;

//pointer to the head of the linked list
typedef NODE *LLIST;

LLIST createList(){
    LLIST L;
    L = (LLIST)malloc(sizeof(NODE));
    L->value = 0;
    L->next = NULL;
    return L;
}

LLIST insertAtFront(LLIST H, int k){
    //create new node and make it the head node
    NODE N;
    N.value = k;
    N.next = H;
    H = &N;
    return H;
}

LLIST insertAtEnd(LLIST H, int k){
    LLIST P = H;
    //create new node
    NODE N;
    N.value = k;
    N.next = NULL;
    //find last node
    while(P->next != NULL){
        P = P->next;
    }
    //link it to the end
    P->next = &N;
    return H;
}

LLIST deleteFromFront(LLIST H, int *k){
    *k = H->value;
    LLIST P = H;
    H = H->next;
    free(P);
    return H;
}

LLIST deleteFromEnd(LLIST H, int *k){
    LLIST P = H;
    //traverse to the second last node
    while(P->next->next != NULL){
        P = P->next;
    }
    //get the last node
    LLIST Q = P->next;
    P->next = NULL;
    *k = Q->value;
    free(Q);
    //return the head
    return H;
}

LLIST deleteList(LLIST H, int k){
    //P is current node, Q is previous node
    LLIST P = H, Q = H;
    //traverse the list
    while(P != NULL){
        if(P->value == k){
            if(P == H){
                H = P->next;
                free(P);
            }
            else{
                Q->next = P->next;
                P->next = NULL;
                free(P);
            }
            break;
        }
        Q = P;
        P = P->next;
    }
    //return the head
    return H;
}