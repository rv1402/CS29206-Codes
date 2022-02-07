#include <newlib/llist.h>
#include <newlib/stack.h>
#include <newlib/queue.h>
#include <newlib/union_find.h>
#include <newlib/heap.h>

typedef struct{
    int num_nodes;
    int num_edges;
    int **adj_mat;
}GRAPH_OBJ;

typedef GRAPH_OBJ *GRAPH;

extern GRAPH readGraph(char *);
extern void DFS(GRAPH);
extern void BFS(GRAPH);
extern void MST(GRAPH);
extern void printGraph(GRAPH);