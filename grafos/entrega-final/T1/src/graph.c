#include "graph.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define vertex int

struct graph_ {
    int V;
    int A;
    vertex **matrix;
};

vertex **create_matrix(int n) {
    vertex **m = (vertex **)malloc(n * sizeof(vertex *));

    if (m == NULL) {
        // printf("Erro de alocação de memória.");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        m[i] = (vertex *)malloc(n * sizeof(vertex));

        if (m[i] == NULL) {
            // printf("Erro de alocação de memória.");
            return NULL;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
        }
    }

    return m;
}

void delete_matrix(vertex ***m, int n) {
    if (*m != NULL) {
        for (int i = 0; i < n; i++) {
            if ((*m)[i] != NULL) {
                free((*m)[i]);
            }
        }
        free(*m);
    }
}

GRAPH *create_graph(int v) {
    GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH));

    if (g == NULL) {
        // printf("Erro de alocação de memória.");
        return NULL;
    }

    g->V = v;
    g->A = 0;
    g->matrix = create_matrix(v);

    return g;
}

void remove_graph(GRAPH **g) {
    if (*g != NULL) {
        delete_matrix(&((*g)->matrix), (*g)->V);
        free(*g);
    }
}

void print_info(GRAPH *g) {
    printf("Número de vértices: %d\n", g->V - 1);
    printf("Número de arestas: %d\n", g->A);

    for (int i = 0; i < number_of_vertex(g); i++) {
        if (get_qtd_adj_vertex(g, i) > 0) {
            int *lista_adj = get_adj_vertex(g, i);
            printf("vértice %d:", i);
            for (int j = 0; j < get_qtd_adj_vertex(g, i); j++) {
                printf("{%d %d} ", i, lista_adj[j]);
            }
            free(lista_adj);
            printf("\n");
        }
    }
}

bool exist_edge(GRAPH *g, int r, int c) {
    if (r < 0 || r >= g->V) return false;
    if (c < 0 || c >= g->V) return false;

    bool exist;
    if (g->matrix[r][c] > 0) {
        exist = true;
    } else {
        exist = false;
    }

    return exist;
}

int get_qtd_adj_vertex(GRAPH *g, int v) {
    int qtd = 0;

    for (int i = 0; i < g->V; i++) {
        if (g->matrix[v][i] > 0) {
            qtd++;
        }
    }

    return qtd;
}

int *get_adj_vertex(GRAPH *g, int v) {
    int qtd = 0;
    int *adjs = (int *)malloc(qtd * sizeof(int));

    for (int i = 0; i < g->V; i++) {
        if (g->matrix[v][i] > 0) {
            qtd++;
            adjs = (int *)realloc(adjs, qtd * sizeof(int));
            adjs[qtd - 1] = i;
        }
    }

    return adjs;
}

void print_list(int *list, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

bool remove_edge(GRAPH *g, int r, int c) {
    if (r < 0 || r >= g->V) return false; // O vértice não existe
    if (c < 0 || c >= g->V) return false;

    g->matrix[r][c] = -1;
    g->matrix[c][r] = -1;
    g->A--;

    return true;
}

int number_of_vertex(GRAPH *g) {
    return g->V - 1;
}

bool add_edge(GRAPH *g, int r, int c) {
    if (r < 0 || r >= g->V) return false; // O vértice não existe
    if (c < 0 || c >= g->V) return false;
    g->matrix[r][c] = 1;
    g->matrix[c][r] = 1;
    g->A++;
    return true;
}

bool add_weighted_edge(GRAPH *g, int r, int c, int p) {
    if (r < 0 || r >= g->V) return false; // O vértice não existe
    if (c < 0 || c >= g->V) return false;
    g->matrix[r][c] = p;
    g->matrix[c][r] = p;
    g->A++;
    return true;
}

vertex **adjacency_matrix(GRAPH *g) {
    int n = number_of_vertex(g);
    vertex **copy_matrix = create_matrix(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            copy_matrix[i][j] = g->matrix[i][j];
        }
    }

    return copy_matrix;
}

void delete_lightest_edge(GRAPH *g) {
    if (g == NULL)
        return; // verificação de segurança

    int no_1 = -1;
    int no_2 = -1;
    int peso_aresta_mais_leve = 10000000;

    int n = number_of_vertex(g);

    for (int i = 0; i < n; i++) { // acha a aresta de menor peso
        for (int j = 0; j < n; j++) {
            if (g->matrix[i][j] > 0 && g->matrix[i][j] < peso_aresta_mais_leve) {
                peso_aresta_mais_leve = g->matrix[i][j];
                printf("\ndebug: %d ", peso_aresta_mais_leve);
                no_1 = i;
                no_2 = j;
            }
        }
    }

    if (no_1 == -1)
        return; // nesse caso, grafo não tem arestas

    printf("Removi aresta %d-%d de peso %d.\n", no_1, no_2, g->matrix[no_1][no_2]);
    remove_edge(g, no_1, no_2); // remove aresta mais de menor peso
}
