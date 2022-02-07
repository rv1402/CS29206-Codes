typedef struct{
    int size;
    //the first cell is kept empty
    //so that numbering starts from 1
    int arr[101];
}HEAP_OBJ;

typedef HEAP_OBJ* HEAP;

extern void swap(int *, int *);
extern HEAP createHeap();
extern int findMin(HEAP H);
extern HEAP extractMin(HEAP H);
extern HEAP insertHeap(HEAP H, int k);
extern int isFullHeap(HEAP H);
extern int isEmptyHeap(HEAP H);
extern void printHeap(HEAP);