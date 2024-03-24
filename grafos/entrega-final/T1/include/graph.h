#include <stdbool.h>
#ifndef GRAPH_H
    #define GRAPH_H
    #define vertex int

    /*
    ## Estrutura do grafo 

    Estrutura criada para representar o grafo. */
    typedef struct graph_ GRAPH;

    /*
    ## Criar matriz

    Retorna `vertex **`: Matriz de adjacência a ser criada. Possui dimensões 
    de `n` x `n`. */
    vertex** create_matrix(int n);

    /*
    ## Deletar matriz

    Deleta matriz `m` e libera seus recursos de memória. */
    void delete_matrix(vertex ***m, int n);

    /*
    ## Criar grafo

    Retorna `GRAPH *`: grafo criado e alocado com `v` vértices. */
    GRAPH *create_graph(int v);

    /*
    ## Remover grafo

    Deleta o grafo `g` e libera seus recursos de memória, incluindo sua matriz de adjacência. */
    void remove_graph(GRAPH **g);

    /*
    ## Imprime informações do grafo

    Imprime informação a respeito das vértices e arestas do grafo, como
    o número de vértices e arestas, assim como a descrição de cada uma. */
    void print_info(GRAPH *g);

    /*
    ## Imprime informação sobre a existência de uma aresta

    Retorna `bool` a respeito da informação solicitada. */
    bool exist_edge(GRAPH *g, int r, int c);

    /*
    ## Obter quantidade vértices adjacentes

    Retorna `int`: quantidade de vértices adjacents ao vértice `v` do grafo `g`. */
    int get_qtd_adj_vertex(GRAPH *g, int v);

    /*
    ## Obter lista de vértices adjacentes

    Retorna `int *` (lista): lista de inteiros dos ids de vértices adjacents ao vértice `v` do grafo `g`. */
    int* get_adj_vertex(GRAPH *g, int v);

    /*
    Função auxílio para imprimir os elementos da lista `*list` que tem `qtd` elementos. */
    void print_list(int *list, int qtd);

    /*
    ## Remover uma aresta do grafo

    Retorna `bool`: Resultado da operação de remover a resta que conecta os vértices de id `r` e `c`. */
    bool remove_edge(GRAPH *g, int r, int c);

    /*
    ## Obter o número de vértices

    Retorna `int`: número de vértices do grafo `g`. */
    int number_of_vertex(GRAPH *g);

    /*
    ## Adicionar aresta

    Retorna `bool`: Resultado da operação de adicionar uma aresta que conecta os vértices de id `r` e `c` do grafo `g`.  */
    bool add_edge(GRAPH *g, int r, int c);

    /* 
    ## Adicionar aresta com peso
    
    Adiciona uma aresta no grafo `g` entre os vértices `r` e `c` de peso `p`. Retorna `bool` : Resultado da operação. */
    bool add_weighted_edge(GRAPH *g, int r, int c,int p);

    /*
    ## Obter a matriz de adjacência

    Retorna `vertex **`: Matriz de adjacência do grafo `g`. */
    vertex** adjacency_matrix(GRAPH *G);
    
    /*
    ## Deeltar aresta de menor peso
    
    Deleta a aresta do grafo `g` que possui o menor peso entre todas. */
    void delete_lightest_edge(GRAPH *G);
#endif
