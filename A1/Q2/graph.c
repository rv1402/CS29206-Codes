#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct set{
    unsigned int i;
    unsigned int j;
}set;

//takes a pointer to a 2D array and returns
//it after initializing it to a given size
int **init_arr(int **dd_array, int size){
    dd_array = malloc(size * sizeof(int *));
    for(int i=0; i<size; i++)
        dd_array[i] = malloc(size * sizeof(int));
    
    return dd_array;
}

void swap_edge(set *x, set *y){
    set t = *x;
    *x = *y;
    *y = t;
}

void heapify(int weights[], set edges[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    //if left child is larger than root
    if(left < n && weights[left] > weights[largest])
        largest = left;
    
    //if right child is larger than root
    if(right < n && weights[right] > weights[largest])
        largest = right;
    
    //if root is not largest
    if(largest != i){
        //swap edges and weights accordingly
        swap(&(weights[i]), &(weights[largest]));
        swap_edge(&(edges[i]), &(edges[largest]));

        heapify(weights, edges, n, largest);
    }
}

void heapSort(int weights[], set edges[], int n){
    for(int i=n/2 - 1; i>=0; i--)
        heapify(weights, edges, n, i);

    //extract min element from heap
    for(int i=n-1; i>=0; i--){
        swap(&(weights[0]), &(weights[i]));
        swap_edge(&(edges[0]), &(edges[i]));

        heapify(weights, edges, i, 0);
    }
}

int isDisconnectedGraph(GRAPH G){
    int sum=0, i, j;
    for(i=0; i<G->num_nodes; i++){
        for(j=0; j<G->num_nodes; j++){
            if((G->adj_mat)[i][j] != 0)
                break;
        }
        
        //if j has reached the end, then graph is disconnected
        if(j == G->num_nodes)
            return 1;
    }
    return 0;
}

GRAPH readGraph(char *FName){
    FILE *fptr;
    fptr = fopen(FName, "r");

    //initialize a graph
    GRAPH G = (GRAPH)malloc(sizeof(GRAPH_OBJ));

    //line stores the next line in input,
    //len is for resizing the buffer,
    //num_read give the number of characters in the line read
    char *line = NULL;
    size_t len = 0;
    ssize_t num_read = 0;
    
    //file couldn't be opened
    if(fptr == NULL){
        printf("Error!\n");
        exit(1);
    }
    
    int num_nodes, num_edges;
    int line_counter = 0;

    //getline returns -1 when EOF is reached
    while((num_read = getline(&line, &len, fptr)) != -1){
        line_counter++;
        //first line contains the number of nodes
        if(line_counter == 1){
            sscanf(line, "%d", &num_nodes);
            if(num_nodes > 100){
                printf("Max size of graph is 100 nodes.");
                exit(1);
            }
            G->num_nodes = num_nodes;
            //initialize adjacency matrix using number of nodes
            G->adj_mat = init_arr(G->adj_mat, num_nodes);
        }
        //second line contains the number of edges
        else if(line_counter == 2){
            sscanf(line, "%d", &num_edges);
            G->num_edges = num_edges;
        }
        //all subsequent lines contain the two vertices along with weight
        else{
            int vertex1, vertex2, weight;
            sscanf(line, "%d %d %d", &vertex1, &vertex2, &weight);
            (G->adj_mat)[vertex1][vertex2] = weight;
            (G->adj_mat)[vertex2][vertex1] = weight;
        }
    }

    return G;
}

//returns the value of next neighbour if it exists,
//else returns -1
//the neighbour is returned in ascending order
int next_neighbour(GRAPH G, int vertex, int *visited){
    for(int i=0; i<G->num_nodes; i++){
        if((G->adj_mat)[vertex][i] != 0){
            if(visited[i] == 0){
                return i;
            }
        }
    }
    return -1;
}

//do a DFS traversal using Stack
//print the nodes in DFS traversal
void DFS(GRAPH G){
    //initialize stack for keeping track of DFS
    STACK S = createStack();

    //a queue to store the order of visit
    QUEUE final = createQueue();

    //create a visited array
    //which stores 1 if node is visited
    //0 otherwise
    int *visited1 = malloc((G->num_nodes) * sizeof(int));

    //repeat over all nodes of the graph
    //so that disconnected nodes are also covered
    for(int i=0; i<G->num_nodes; i++){
        if(!visited1[i]){
            //mark i as visited if it has not been visited yet
            visited1[i] = 1;
            //add this node to final ordering
            final = enqueue(final, i);

            S = push(S, i);
            int prev = i, next;
            while(!isEmptyStack(S)){
                //get next neighbour of prev
                next = next_neighbour(G, prev, visited1);
                
                //if no neighbours exist
                if(next == -1){
                    //remove the top element from S
                    S = pop(S, &prev);
                    //set next to the popped element
                    //so that the neighbours of that element can be checked
                    //next is set to prev hence we are backtracking
                    next = prev;
                }
                else{
                    visited1[next] = 1;
                    final = enqueue(final, next);

                    S = push(S, next);
                    prev = next;
                }
            }
        }
    }

    //logic to print the final order
    printf("DFS:\n");
    while(final->next != NULL){
        int t;
        final = dequeue(final, &t);
        printf("%d -> ", t);
    }
    printf("%d\n", final->value);

    //free required variables
    // free(visited1);
    freeList(S);
    freeList(final);
}

void BFS(GRAPH G){
    //initialize queue to keep track of BFS
    QUEUE Q = createQueue();

    //a queue to store the order of visit
    QUEUE final = createQueue();

    //create a visited array
    //which stores 1 if node is visited
    //0 otherwise
    int *visited = malloc((G->num_nodes) * sizeof(int));

    for(int i=0; i<G->num_nodes; i++){
        if(!visited[i]){
            //mark i as visited if it has not been visited yet
            visited[i] = 1;
            //add this node to final ordering
            final = enqueue(final, i);

            Q = enqueue(Q, i);
            while(!isEmptyQueue(Q)){
                int j;
                Q = dequeue(Q, &j);

                for(int k=0; k < (G->num_nodes); k++){
                    if((G->adj_mat)[j][k] != 0){
                        if(!visited[k]){
                            visited[k] = 1;
                            final = enqueue(final, k);
                            
                            Q = enqueue(Q, k);
                        }
                    }
                }
            }
        }
    }

    //logic to print the final order
    printf("BFS:\n");
    while(final->next != NULL){
        int t;
        final = dequeue(final, &t);
        printf("%d -> ", t);
    }
    printf("%d\n", final->value);

    //free required variables
    // free(visited);
    freeList(Q);
    freeList(final);
}

void make_set(GRAPH G, QUEUE *edges_i, QUEUE *edges_j){
    int weights[G->num_edges];
    set edges[G->num_edges];
    unsigned int c=0;

    for(int i=0; i<G->num_nodes; i++){
        for(int j=i+1; j<G->num_nodes; j++){
            if((G->adj_mat)[i][j] != 0){
                weights[c] = (G->adj_mat)[i][j];
                edges[c].i = i;
                edges[c].j = j;
                c++;
            }
        }
    }

    heapSort(weights, edges, G->num_edges);

    //add the edge to the final queues
    for(int i=0; i<G->num_edges; i++){
        *edges_i = enqueue(*edges_i, edges[i].i);
        *edges_j = enqueue(*edges_j, edges[i].j);
    }
}

void MST(GRAPH G){
    printf("MST: \n");
    //check if graph is disconnected
    if(isDisconnectedGraph(G)){
        printf("Minimum spanning tree does not exist(Disconnected Graph).\n");
        return;
    }

    //create an empty Union-Find variable
    UNION_FIND F = createUF(G->num_nodes);
    //make all the nodes as individual sets
    for(int i=0; i<G->num_nodes; i++){
        int *p = malloc(sizeof(int));
        F = makeSetUF(F, i, p);
    }

    //queue for storing edges
    QUEUE edges_i = createQueue();
    QUEUE edges_j = createQueue();

    //create a set of edges, ordered by weights
    make_set(G, &edges_i, &edges_j);

    int total_weight = 0;
    while(!isEmptyQueue(edges_i) && !isEmptyQueue(edges_j)){
        int i, j;
        edges_i = dequeue(edges_i, &i);
        edges_j = dequeue(edges_j, &j);

        if(findUF(F, i) != findUF(F, j)){
            printf("Edge: x=%d, y=%d; Weight=%d\n", i, j, (G->adj_mat)[i][j]);
            total_weight += (G->adj_mat)[i][j];
            unionUF(F, i, j);
        }
    }
    printf("Total Weight of Minimum Spanning Tree = %d\n", total_weight);
}

void printGraph(GRAPH G){
    int size = G->num_nodes;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%d ", (G->adj_mat)[i][j]);
        }
        printf("\n");
    }
}