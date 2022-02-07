#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

HEAP createHeap(){
    HEAP H = (HEAP)malloc(sizeof(HEAP_OBJ));
    H->size = 0;
    return H;
}

int findMin(HEAP H){
    //minimum element is at top of min heap
    return H->arr[1];
}

int isFullHeap(HEAP H){
    if(H->size == 100)
        return 1;
    return 0;
}

int isEmptyHeap(HEAP H){
    if(H->size == 0)
        return 1;
    return 0;
}

//delete minimum value from Heap
HEAP extractMin(HEAP H){
    if(isEmptyHeap(H)){
        printf("Min-Heap is empty.\n");
        return H;
    }
    H->arr[1] = H->arr[H->size];
    (H->size)--;
    if(isEmptyHeap(H)){
        return H;
    }
    int nodeIndex = 1;
    while(1){
        int l = 2*nodeIndex;
        int r = 2*nodeIndex + 1;
        int min = r;
        if(l > H->size)
            return H;

        if(r > H->size)
            min = l;
        else if(H->arr[l] < H->arr[r])
            min = l;
        else
            min = r;

        if(H->arr[nodeIndex] < H->arr[min])
            return H;
        swap(&(H->arr[nodeIndex]), &(H->arr[min]));
        nodeIndex = min;
    }
}

//insert a value into the heap
HEAP insertHeap(HEAP H, int k){
    (H->size)++;
    if(isFullHeap(H)){
        printf("Min-Heap is full.\n");
        return H;
    }
    H->arr[H->size] = k;
    int nodeIndex = H->size;
    while(1){
        if(nodeIndex == 1)
            return H;
        int p = nodeIndex/2;
        if(H->arr[p] <= H->arr[nodeIndex])
            return H;
        swap(&(H->arr[p]), &(H->arr[nodeIndex]));
        nodeIndex = p;
    }
}

void printHeap(HEAP H){
    if(isEmptyHeap(H)){
        printf("Min-Heap is empty.\n");
        return;
    }
    for(int i=1; i<=H->size; i*=2){
        int limit = (H->size < (2*i-1))? H->size : (2*i-1);
        for(int j=i; j<=limit; j++){
            printf("%d ", H->arr[j]);
        }
        printf("\n");
    }
}