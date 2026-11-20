#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Cria um novo nó
Node *criar_no(int valor)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->info = valor;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

// Insere um valor na BST
Node *inserir(Node *raiz, int valor)
{
    // Caso base: árvore vazia
    if (raiz == NULL)
    {
        return criar_no(valor);
    }

    // Recursão: vai para esquerda ou direita
    if (valor < raiz->info)
    {
        raiz->left = inserir(raiz->left, valor);
    }
    else if (valor > raiz->info)
    {
        raiz->right = inserir(raiz->right, valor);
    }

    return raiz;
}

// Busca um valor na BST
Node *buscar(Node *raiz, int valor)
{
    // Caso base: não encontrado ou encontrado
    if (raiz == NULL || raiz->info == valor)
    {
        return raiz;
    }

    // Vai para esquerda ou direita
    if (valor < raiz->info)
    {
        return buscar(raiz->left, valor);
    }
    return buscar(raiz->right, valor);
}

// Encontra o menor valor (mais à esquerda)
int min_valor(Node *raiz)
{
    Node *atual = raiz;
    while (atual && atual->left != NULL)
    {
        atual = atual->left;
    }
    return atual->info;
}

// Remove um valor da BST
Node *remover(Node *raiz, int valor)
{
    if (raiz == NULL)
        return raiz;

    // Encontra o nó a ser removido
    if (valor < raiz->info)
    {
        raiz->left = remover(raiz->left, valor);
    }
    else if (valor > raiz->info)
    {
        raiz->right = remover(raiz->right, valor);
    }
    else
    {
        // Nó encontrado! Três casos:

        // Caso 1: Nó folha ou com apenas 1 filho
        if (raiz->left == NULL)
        {
            Node *temp = raiz->right;
            free(raiz);
            return temp;
        }
        else if (raiz->right == NULL)
        {
            Node *temp = raiz->left;
            free(raiz);
            return temp;
        }

        // Caso 2: Nó com 2 filhos
        // Pega o sucessor (menor da subárvore direita)
        int sucessor = min_valor(raiz->right);
        raiz->info = sucessor;
        raiz->right = remover(raiz->right, sucessor);
    }

    return raiz;
}

// In-Order: Esquerda → Raiz → Direita (ordem crescente)
void in_order(Node *raiz)
{
    if (raiz != NULL)
    {
        in_order(raiz->left);
        printf("%d ", raiz->info);
        in_order(raiz->right);
    }
}

// Pre-Order: Raiz → Esquerda → Direita
void pre_order(Node *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->info);
        pre_order(raiz->left);
        pre_order(raiz->right);
    }
}

// Post-Order: Esquerda → Direita → Raiz
void post_order(Node *raiz)
{
    if (raiz != NULL)
    {
        post_order(raiz->left);
        post_order(raiz->right);
        printf("%d ", raiz->info);
    }
}

// Calcula altura da árvore
int altura(Node *raiz)
{
    if (raiz == NULL)
        return -1;

    int altura_esq = altura(raiz->left);
    int altura_dir = altura(raiz->right);

    return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
}

// Libera toda a memória da árvore
void liberar_arvore(Node *raiz)
{
    if (raiz != NULL)
    {
        liberar_arvore(raiz->left);
        liberar_arvore(raiz->right);
        free(raiz);
    }
}
