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

void delete_matrix(vertex ***m, int n){
    if (**m != NULL){
        for(int i=0; i<n; i++){
            if((*m)[i] != NULL){
                free((*m)[i]);
            }
        }
        free(*m);
    }
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

void delete_graph(GRAPH **g){
    if(*g != NULL){
        delete_matrix(&((*g)->matrix), (*g)->V);
        free(*g);
    }
}

void print_graph(GRAPH *g, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d", g->matrix[i][j]);
        }
        printf("\n");
    }
}

bool exist_edge(int r, int c){

    return 0;
}