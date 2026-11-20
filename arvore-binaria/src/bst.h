#ifndef BST_H
#define BST_H

// Estrutura do nó da BST
typedef struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
} Node;

// Funções principais
Node *criar_no(int valor);
Node *inserir(Node *raiz, int valor);
Node *buscar(Node *raiz, int valor);
Node *remover(Node *raiz, int valor);

// Travessias
void in_order(Node *raiz);
void pre_order(Node *raiz);
void post_order(Node *raiz);

// Utilidades
int altura(Node *raiz);
int min_valor(Node *raiz);
void liberar_arvore(Node *raiz);

#endif
