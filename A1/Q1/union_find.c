#include <stdio.h>
#include <stdlib.h>
#include "union_find.h"

int isFull(UNION_FIND F){
    if(F->last_filled_index == F->size)
        return 1;
    return 0;
}

UNION_FIND createUF(int n){
    UNION_FIND F = (UNION_FIND)malloc(sizeof(UNION_FIND_OBJ));
    //allocate memory for n node pointers
    F->arr = (NODE_PTR *)malloc(n * sizeof(NODE_PTR));
    //set all node pointers to null
    for(int i=0; i<n; i++){
        F->arr[i] = NULL;
    }
    F->last_filled_index = -1;
    F->size = n;
    return F;
}

UNION_FIND makeSetUF(UNION_FIND F, int x, int *i){
    NODE_PTR P = (NODE_PTR)malloc(sizeof(UF_NODE));
    P->value = x;
    P->num_nodes = 1;
    P->next = NULL;
    //numbering follows 0, 1, 2...
    (F->last_filled_index++);
    if(isFull(F))
        return F;
    //add P to F
    F->arr[F->last_filled_index] = P;
    //update 'i'
    *i = F->last_filled_index;
    return F;
}

NODE_PTR findUF(UNION_FIND F, int i){
    //if index accessed is out of bounds
    if(i >= F->size)
        return NULL;
    NODE_PTR P = F->arr[i];
    //find root node of tree
    while(P->next != NULL){
        P = P->next;
    }
    return P;
}

void unionUF(UNION_FIND F, int i, int j){
    if(i == j)
        return;
    NODE_PTR P = findUF(F, i);
    NODE_PTR Q = findUF(F, j);
    //if subtree sizes are the same
    if(P->num_nodes == Q->num_nodes){
        //set i to be parent of j
        Q-> next = P;
        P->num_nodes += Q->num_nodes;
    }
    else if(P->num_nodes > Q->num_nodes){
        Q->next = P;
        P->num_nodes += Q->num_nodes;
    }
    else{
        P->next = Q;
        Q->num_nodes += P->num_nodes;
    }
}

void printUF(UNION_FIND F){
    int limit = F->last_filled_index;
    if(limit == -1){
        printf("Union-Find data structure is empty.");
        return;
    }
    for(int i=0; i<=limit; i++){
        NODE_PTR P = F->arr[i];
        //print the subtree starting
        //from leaf node P to root node
        while(P != NULL){
            printf("%d ", P->value);
            P = P->next;
        }
        printf("\n");
    }
}