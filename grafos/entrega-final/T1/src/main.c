#include "graph.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
O programa começa solicitando ao usuário o número de vértices do grafo.
Em um loop do-while, o programa oferece um menu de opções para o usuário, permitindo que ele execute várias operações no grafo.
O loop continua até que o usuário escolha a opção de sair (-1).
Após sair do loop, o programa libera a memória alocada para o grafo e encerra.

Decisões de Desing:
- O '-1' representa, na matriz de adjacência, a ausência de aresta;
- O '1' representa uma aresta sem peso;
- Qualquer número maior que 1 representa o peso da aresta;
- Na função 'remover aresta de menos peso' se todas as arestas não tiverem peso, a função remove uma aresta qualquer;
*/

int main() {
    int tamanho_grafo = 0;
    printf("Por favor, diga o número de vértices do seu grafo:\n");
    scanf(" %d", &tamanho_grafo);

    // tamanho_grafo + 1 pois não existe vértice 0
    GRAPH *G = create_graph(tamanho_grafo + 1);

    int comando = 0;
    int param1, param2;
    int executando = 1;

    do {

        // printf("\n[digite '0' para ver os comandos]\nDigite o comando: ");

        scanf("%d", &comando);
        switch (comando) {
        case 0:

            printf("\nMenu:\n");
            printf("0. Ver comandos\n");
            printf("1. Adicionar Aresta sem peso\n");
            printf("2. Adicionar Aresta com peso\n");
            printf("3. Remover Aresta\n");
            printf("4. Obter Vértices Adjacentes\n");
            printf("5. Verificar se Aresta Existe\n");
            printf("6. Imprimir Informações do Grafo\n");
            printf("7. Obter Número de Vértices\n");
            printf("8. Remover Aresta Mais Leve\n");
            printf("9. Imprimir Matriz de Adjacência\n");
            printf("-1. Sair\n");
            break;

        case 1:

            printf("Digite os vértices de início e fim da aresta: ");
            scanf("%d %d", &param1, &param2);

            if (!add_edge(G, param1, param2))
                printf("ERRO: um dos vértices não existe\n");
            else
                printf("Adicionada a aresta %d-%d sem peso.\n", param1, param2);
            break;

        case 2:

            printf("Digite os vértices de início e fim da aresta: ");
            scanf("%d %d", &param1, &param2);

            printf("Digite o peso da aresta: ");
            int peso;
            scanf(" %d", &peso);

            if (!add_weighted_edge(G, param1, param2, peso))
                printf("ERRO: um dos vértices não existe\n");
            else
                printf("Adicionada a aresta %d-%d com peso %d.\n", param1, param2, peso);
            break;

        case 3:

            printf("Digite os vértices da aresta para remover: \n");
            scanf("%d %d", &param1, &param2);

            if (!remove_edge(G, param1, param2))
                printf("ERRO: um dos vértices não existe\n");
            else
                printf("Removida a aresta %d-%d\n", param1, param2);
            break;

        case 4:

            printf("\n");
            printf("Digite o vértice que deseja ver a adjacência: \n");
            scanf(" %d", &param1);

            int grau = get_qtd_adj_vertex(G, param1);
            if (grau == 0) {
                printf("O vértice %d não possui nenhum vértice adjacente à ele\n", param1);
                break;
            }
            int *lista_adj = get_adj_vertex(G, param1);

            printf("Os vértices adjacentes à %d são: ", param1);
            for (int i = 0; i < grau; i++)
                printf("%d ", lista_adj[i]);
            printf("\n");

            free(lista_adj);
            break;

        case 5:

            printf("\n");
            printf("Digite os vértices da aresta que deseja verificar se existe:\n");
            scanf(" %d %d", &param1, &param2);
            if (exist_edge(G, param1, param2))
                printf("A aresta %d-%d existe!\n", param1, param2);
            else
                printf("A aresta %d-%d não existe!\n", param1, param2);
            break;

        case 6:

            printf("\n");
            printf("Informações do grafo:\n");
            print_info(G);
            break;

        case 7:

            printf("\n");
            printf("Número de vértices: %d\n", number_of_vertex(G));
            break;

        case 8:

            delete_lightest_edge(G);
            break;

        case 9:

            printf("\n");
            int tam = number_of_vertex(G);
            int **matrix = adjacency_matrix(G);
            printf("Matriz de adjascência:\n");
            for (int i = 1; i <= tam; i++) {
                for (int j = 1; j <= tam; j++) {
                    if (matrix[i][j] != -1)
                        printf(" "); // ajusta o espaçamento na hora de imprimir

                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            for (int i = 0; i <= tam; i++)
                free(matrix[i]);
            free(matrix);
            break;

        case -1:

            executando = 0;
            break;

        default:
            printf("Comando inválido!\n");
            break;
        }

    } while (executando);

    remove_graph(&G);
    return 0;
}
