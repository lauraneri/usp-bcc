#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include  "graph.h"

int main(int argc, char *argv[]){
    GRAPH *g = create_graph(10);
    print_graph(g, 10);
    delete_graph(&g);
    return 0;
}