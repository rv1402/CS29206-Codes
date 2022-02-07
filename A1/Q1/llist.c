#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

LLIST createList(){
    LLIST L=NULL;
    return L;
}

LLIST insertAtFront(LLIST H, int k){
    //create new node and make it the head node
    NODEP N = (NODEP)malloc(sizeof(NODE));
    N->value = k;
    N->next = H;
    H = N;
    return H;
}

LLIST insertAtEnd(LLIST H, int k){
    //create new node
    NODEP N = (NODEP)malloc(sizeof(NODE));
    N->value = k;
    N->next = NULL;
    //if linked list is empty
    if(H == NULL){
        H = N;
    }
    else{
        LLIST P = H;
        //find last node
        while(P->next != NULL){
            P = P->next;
        }
        //link it to the end
        P->next = N;
    }
    return H;
}

LLIST deleteFromFront(LLIST H, int *k){
    //if linked list is not empty
    if(H != NULL){
        *k = H->value;
        LLIST P = H;
        H = H->next;
        free(P);
    }
    //return the head
    return H;
}

LLIST deleteFromEnd(LLIST H, int *k){
    //if linked list is not empty
    if(H != NULL){
        //P is current node, Q is previous node
        LLIST P = H, Q = H;
        //traverse to the last node
        while(P->next != NULL){
            Q = P;
            P = P->next;
        }
        //retrieve value
        *k = P->value;
        //if linked list contains only one node
        if(P == Q){
            H = NULL;
        }
        else{
            Q->next = NULL;
        }
        free(P);
    }
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

void freeList(LLIST H){
    NODEP tmp;
    while(H != NULL){
        tmp = H;
        H = H->next;
        free(tmp);
    }
}