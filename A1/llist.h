typedef struct NODE{
    int value;
    struct NODE *next;
}NODE;

//pointer to the head of the linked list
typedef NODE *LLIST;
//Node Pointer
typedef NODE *NODEP;

LLIST createList();
int searchList(LLIST, int);
LLIST insertAtFront(LLIST, int);
LLIST insertAtEnd(LLIST, int);
LLIST deleteFromFront(LLIST, int *);
LLIST deleteFromEnd(LLIST, int *);
LLIST deleteList(LLIST, int);