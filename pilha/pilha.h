#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define FALHA 1

// LIFO: last in, first out
typedef struct t_pilha
{
    int capacidade;
    // quantos cabem
    int topo;
    // quantos elementos tem
    int *v;
} t_pilha;

t_pilha inicializa_pilha(int);

int esta_vazia(t_pilha *);
int esta_cheia(t_pilha *);

void popula_pilha(t_pilha *);
void mostra_pilha(t_pilha *);

int push(t_pilha *, int);
int pop(t_pilha *, int *);