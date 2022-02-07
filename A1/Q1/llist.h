typedef struct NODE{
    int value;
    struct NODE *next;
}NODE;

//pointer to the head of the linked list
typedef NODE *LLIST;
//Node Pointer
typedef NODE *NODEP;

extern LLIST createList();
extern int searchList(LLIST, int);
extern LLIST insertAtFront(LLIST, int);
extern LLIST insertAtEnd(LLIST, int);
extern LLIST deleteFromFront(LLIST, int *);
extern LLIST deleteFromEnd(LLIST, int *);
extern LLIST deleteList(LLIST, int);
extern void freeList(LLIST);