#include "t_char_pilha.h"

t_char_pilha inicializa_pilha(int capacidade)
{
    t_char_pilha pilha;
    pilha.capacidade = capacidade;
    pilha.topo = 0;
    pilha.v = malloc(capacidade);
    return pilha;
}

int esta_vazia(t_char_pilha *pilha)
{
    return pilha->topo == 0;
}

int esta_cheia(t_char_pilha *pilha)
{
    return pilha->topo == pilha->capacidade;
}

void popula_pilha(t_char_pilha *pilha)
{
    for (int i = 0; i < pilha->capacidade; i++)
        pilha->v[pilha->topo++] = i + 1;
}

void mostra_pilha(t_char_pilha *pilha)
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

int push(t_char_pilha *pilha, char elemento)
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

int pop(t_char_pilha *pilha, char *removido)
{
    if (esta_vazia(pilha))
    {
        puts("[AVISO] Pilha se encontra vazia...");
        return FALHA;
    }
    *removido = pilha->v[--pilha->topo];
    return SUCESSO;
}

char *string_pilha(t_char_pilha *p){
    char *s = (char *) malloc(1000);
    char s_aux[32];
    s[0] = '\0'; 
    if (esta_vazia(p)){
        sprintf(s, "pilha vazia\n");
    }
    else {
        for (int i=p->topo-1; i>=0; i--){
            sprintf(s_aux, "%c\n", p->v[i]);
            strcat(s, s_aux);
        }
        strcat(s, "==========\n");
    }
    return s;

}