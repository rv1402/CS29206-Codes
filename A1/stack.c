#include <stdio.h>
#include <stdlib.h>
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
    if(isEmptyStack(S) == 1){
        printf("Stack is empty.\n");
    }
    else{
        S = deleteFromFront(S, k);
    }
    return S;
}