typedef struct{
    int value;
    NODE *next;
}NODE;

//pointer to the head of the linked list
typedef NODE *LLIST;

LLIST createList();
int searchList(LLIST, int);
LLIST insertAtFront(LLIST, int);
LLIST insertAtEnd(LLIST, int);
LLIST deleteFromFront(LLIST, int *);
LLIST deleteFromEnd(LLIST, int *);
LLIST deleteList(LLIST, int);