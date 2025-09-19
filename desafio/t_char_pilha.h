#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "string.h"

#define SUCESSO 0
#define FALHA 1

// LIFO: last in, first out
typedef struct t_char_pilha
{
    int capacidade;
    // quantos cabem
    int topo;
    // quantos elementos tem
    char *v;
} t_char_pilha;

t_char_pilha inicializa_pilha(int);

int esta_vazia(t_char_pilha *);
int esta_cheia(t_char_pilha *);

void popula_pilha(t_char_pilha *);
void mostra_pilha(t_char_pilha *);

int push(t_char_pilha *, char);
int pop(t_char_pilha *, char*);
// @TODO: metodo de visualizacao de pilha...