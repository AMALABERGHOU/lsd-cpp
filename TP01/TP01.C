#include<stdio.h>
#include <stdlib.h>
#include "liste.h"

// in the following: an undirected edge is considered as two separate edges each representing a direction 

struct graph{
    int numNodes;
    int ** head; // adjacency Matrix
};
typedef struct graph graph;
// creating an initialized graph:
graph createGraph(int n){
    graph G={0,NULL};
    G.numNodes=n;
    //initializing the adjacency matrix
    G.head=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<G.numNodes;i++)
        G.head[i]=(int *)malloc(n*sizeof(int));
    for(int i=0;i<G.numNodes;i++){
        for(int j=0;j<G.numNodes;j++)
            G.head[i][j] = 0;
    }
    return G;
}
void printMatrix(graph G){
    int n=G.numNodes;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ", G.head[i][j]);
        }
        printf("\n");
    }
    return ;
}
// adding edge to a graph:
void edge(graph *G, int i, int j) {
    if(i==j){
        return ; // we can't have a path from a node to itself
    }
    G->head[i][j] = 1; // the graphs are undirected!
    G->head[j][i]=1; //the edge of opposite direction is added
    return ;
}
//priting a graph:
void printGraph(graph G)
{
    for (int i = 0; i <G.numNodes; i++)
    {   
        for(int j=0;j<G.numNodes;j++){
            if(G.head[i][j]==1){
            printf("(%d —> %d)\t", i, j);
                
            }
        }
        printf("\n");
    }
    return ;
}
//check if a node was visited in a given path:
int isVisited(int i,stackList path){
    stackList temp=path;
    while(temp!=NULL){
        if(temp->element==i){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int main(){
    graph G=createGraph(3);
    edge(&G,0,1);
    edge(&G,0,2);
    printMatrix(G);
    printf("visualization of the graph: \n"); 
    // each printed line represents the adjacency list of each of the nodes,
    // we consider the undirected edge as two separate edges each representing a direction 
    printGraph(G);
    
    return 0;
}
