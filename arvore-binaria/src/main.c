#include <stdio.h>
#include "bst.h"

int main() {
    Node* raiz = NULL;

    printf("=== Exemplo de Binary Search Tree ===\n\n");

    // Inserindo valores
    printf("Inserindo: 50, 30, 70, 20, 40, 60, 80\n");
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("\nArvore resultante:\n");
    printf("        50\n");
    printf("       /  \\\n");
    printf("      30   70\n");
    printf("     / \\   / \\\n");
    printf("    20 40 60 80\n\n");

    // Travessias
    printf("In-Order (crescente):  ");
    in_order(raiz);
    printf("\n");

    printf("Pre-Order:             ");
    pre_order(raiz);
    printf("\n");

    printf("Post-Order:            ");
    post_order(raiz);
    printf("\n\n");

    // Altura
    printf("Altura da arvore: %d\n\n", altura(raiz));

    // Busca
    int busca = 40;
    printf("Buscando %d... ", busca);
    Node* resultado = buscar(raiz, busca);
    if (resultado != NULL) {
        printf("Encontrado!\n");
    } else {
        printf("Nao encontrado!\n");
    }

    busca = 100;
    printf("Buscando %d... ", busca);
    resultado = buscar(raiz, busca);
    if (resultado != NULL) {
        printf("Encontrado!\n");
    } else {
        printf("Nao encontrado!\n");
    }

    // Remoção
    printf("\nRemovendo 20 (folha):\n");
    raiz = remover(raiz, 20);
    printf("In-Order: ");
    in_order(raiz);
    printf("\n");

    printf("\nRemovendo 30 (2 filhos):\n");
    raiz = remover(raiz, 30);
    printf("In-Order: ");
    in_order(raiz);
    printf("\n");

    // Limpa memória
    liberar_arvore(raiz);

    return 0;
}
