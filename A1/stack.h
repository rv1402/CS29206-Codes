#include "llist.h"

typedef LLIST STACK;

STACK createStack();
int isEmptyStack(STACK);
STACK push(STACK, int);
STACK pop(STACK, int *);
void printStack(STACK);