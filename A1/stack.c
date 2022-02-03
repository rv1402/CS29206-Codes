#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include "stack.h"

STACK createStack(){
    return createList();
}

int isEmptyStack(STACK S){
    if(S == NULL)
        return 1;
    return 0;
}

STACK push(STACK S, int k){
    S = insertAtFront(S, k);
    return S;
}

STACK pop(STACK S, int *k){
    if(isEmptyStack(S)){
        printf("Stack is empty.\n");
    }
    else{
        S = deleteFromFront(S, k);
    }
    return S;
}

void printStack(STACK S){
    if(isEmptyStack(S)){
        printf("Stack is Empty.\n");
        return;
    }
    printf("Top: %d\n", S->value);
    S = S->next;
    while(S != NULL){
        printf("Val: %d\n", S->value);
        S = S->next;
    }
}