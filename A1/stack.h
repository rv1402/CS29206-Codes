typedef LLIST STACK;

extern STACK createStack();
extern int isEmptyStack(STACK);
extern STACK push(STACK, int);
extern STACK pop(STACK, int *);
extern void printStack(STACK);