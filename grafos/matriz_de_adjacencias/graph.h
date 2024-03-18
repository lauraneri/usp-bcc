#include <stdbool.h>
#ifndef GRAPH_H
    #define GRAPH_H
    #define vertex int

    typedef struct graph_ GRAPH;

    vertex** create_matrix(int n);
    void delete_matrix(vertex ***m, int n);
    GRAPH *create_graph(int v);
    void delete_graph(GRAPH **g);
    void print_graph(GRAPH *g, int n);
    bool exist_edge(int r, int c);

#endif