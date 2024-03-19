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

void remove_graph(GRAPH **g){
    if(*g != NULL){
        delete_matrix(&((*g)->matrix), (*g)->V);
        free(*g);
    }
}

void print_info(GRAPH *g, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d", g->matrix[i][j]);
        }
        printf("\n");
    }
}

bool exist_edge(GRAPH *g, int r, int c){
    bool exist;
    if(g->matrix[r][c] > 0){
        exist = true;
    }else{
        exist = false;
    }

    return exist;
}

int get_qtd_adj_vertex(GRAPH *g, int v){
    int qtd = 0;

    for(int i=0; i<g->V; i++){
        if(g->matrix[v][i] > 0){
            qtd++;
        }
    }

    return qtd;
}

int* get_adj_vertex(GRAPH *g, int v){
    int qtd = 0;
    int *adjs = (int *) malloc(qtd*sizeof(int));
    

    for(int i=0; i<g->V; i++){
        if(g->matrix[v][i] > 0){
            qtd++;
            adjs = (int *) realloc (adjs, qtd * sizeof(int));
            adjs[qtd-1] = g->matrix[v][i];
        }
    }

    return adjs;
}

void print_list(int *list, int qtd){
    for (int i=0; i<qtd; i++){
        printf("%d ", list[i]);
    }
    printf("\n");

}

void remove_edge(GRAPH *g, int r, int c){
    g->matrix[r][c] = 0;
    g->matrix[c][r] = 0;
    g->A--;
}

int number_of_vertex(GRAPH *g){
    int n = g->V;
    return n;
}

void add_edge(GRAPH *g, int r, int c){
    g->matrix[r][c] = 1;
    g->matrix[c][r] = 1;
    g->A++;
}