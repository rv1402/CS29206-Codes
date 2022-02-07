typedef struct UF_NODE{
    unsigned int value;
    struct UF_NODE *next;
    int num_nodes;
}UF_NODE;

typedef UF_NODE *NODE_PTR;

typedef struct{
    //array to store n node pointers
    NODE_PTR *arr;
    int size;
    int last_filled_index;
}UNION_FIND_OBJ;

typedef UNION_FIND_OBJ *UNION_FIND;

UNION_FIND createUF(int);
UNION_FIND makeSetUF(UNION_FIND, int, int *);
NODE_PTR findUF(UNION_FIND, int);
void unionUF(UNION_FIND F, int i, int j);
void printUF(UNION_FIND);