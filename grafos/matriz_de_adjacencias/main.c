#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include  "graph.h"

int main(int argc, char *argv[]){
    GRAPH *g = create_graph(10);
    print_info(g, 10);
    bool exist = exist_edge(g, 1, 2);
    printf("\nexist: %b\n", exist);
    int *lista = get_adj_vertex(g, 2);
    print_list(lista, get_qtd_adj_vertex(g, 2));
    free(lista);
    remove_graph(&g);
    return 0;
}