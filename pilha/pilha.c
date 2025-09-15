#include "pilha.h"

t_pilha inicializa_pilha(int capacidade)
{
    t_pilha pilha;
    pilha.capacidade = capacidade;
    pilha.topo = 0;
    pilha.v = malloc(capacidade * sizeof(int));
    return pilha;
}

int esta_vazia(t_pilha *pilha)
{
    return pilha->topo == 0;
}

int esta_cheia(t_pilha *pilha)
{
    return pilha->topo == pilha->capacidade;
}

void popula_pilha(t_pilha *pilha)
{
    for (int i = 0; i < pilha->capacidade; i++)
        pilha->v[pilha->topo++] = i + 1;
}

void mostra_pilha(t_pilha *pilha)
{
    printf("[ ");
    for (int i = 0; i < pilha->topo; i++)
    {
        printf("%d", pilha->v[i]);
        if (i < pilha->topo - 1)
            printf(", ");
    }
    puts("]");
}

int push(t_pilha *pilha, int elemento)
{
    if (esta_cheia(pilha))
    {
        puts("[ERRO] Pilha se encontra cheia...");
        return FALHA;
    }
    pilha->v[pilha->topo++] = elemento;
    // *(pilha->v + pilha->topo) = elemento;
    // pilha->topo++;
    return SUCESSO;
}

int pop(t_pilha *pilha, int *removido)
{
    if (esta_vazia(pilha))
    {
        puts("[AVISO] Pilha se encontra vazia...");
        return FALHA;
    }
    *removido = pilha->v[--pilha->topo];
    return SUCESSO;
}