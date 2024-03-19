#include <stdbool.h>
#ifndef GRAPH_H
    #define GRAPH_H
    #define vertex int

    typedef struct graph_ GRAPH;

    vertex** create_matrix(int n);
    void delete_matrix(vertex ***m, int n);
    GRAPH *create_graph(int v);
    void remove_graph(GRAPH **g);
    void print_info(GRAPH *g, int n);
    bool exist_edge(GRAPH *g, int r, int c);
    int get_qtd_adj_vertex(GRAPH *g, int v);
    int* get_adj_vertex(GRAPH *g, int v);
    void print_list(int *list, int qtd);
    void remove_edge(GRAPH *g, int r, int c);
    int number_of_vertex(GRAPH *g);

#endif