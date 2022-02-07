#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int main(){
    char *input;
    printf("Enter the path to the input file:\n");
    scanf("%s", input);

    GRAPH G = readGraph(input);

    DFS(G);
    BFS(G);
    MST(G);

    return 0;
}