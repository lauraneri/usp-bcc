#ifndef GRAPH_H
    #define GRAPH_H
    #define vertex int

    typedef struct graph_ GRAPH;

    vertex** create_matrix(int n);
    GRAPH *create_graph(int v);

#endif