typedef struct{
    int size;
    //the first cell is kept empty
    //so that numbering starts from 1
    int arr[101];
}HEAP_OBJ;

typedef HEAP_OBJ* HEAP;

HEAP createHeap();
int findMin(HEAP H);
HEAP extractMin(HEAP H);
HEAP insertHeap(HEAP H, int k);
int isFullHeap(HEAP H);
int isEmptyHeap(HEAP H);
void printHeap(HEAP);