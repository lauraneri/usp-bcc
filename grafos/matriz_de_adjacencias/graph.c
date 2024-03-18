#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

#define vertex int

struct graph_{
    int V;
    int A;
    vertex **matrix;
};

vertex** create_matrix(int n){
    vertex **m = (vertex **) malloc(n * sizeof(vertex*));

    if(m == NULL){
    //printf("Erro de alocação de memória.");
    return NULL;  
    }

    for (int i=0; i<n; i++){
        m[i] = (vertex*) malloc (n * sizeof(vertex));

        if(m[i] == NULL){
        //printf("Erro de alocação de memória.");
        return NULL;  
    }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            m[i][j] = 0;
        }
    }

    return m;
}

GRAPH *create_graph(int v){
    GRAPH *g = (GRAPH *) malloc(sizeof(GRAPH));

    if(g == NULL){
    //printf("Erro de alocação de memória.");
    return NULL;  
    }

    g->V = v;
    g->A = 0;
    g->matrix = create_matrix(v);

    return g;
}

bool exist_edge(int r, int c){

    return 0;
}