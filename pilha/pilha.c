#include "pilha.h"

t_pilha inicializa_pilha(int capacidade)
{
    t_pilha pilha;
    pilha.capacidade = capacidade;
    pilha.topo = 0;
    pilha.v = malloc(capacidade * sizeof(int));
    if (pilha.v == NULL)
    {
        printf("[ERRO] Falha ao alocar memoria para a pilha...\n");
        pilha.capacidade = 0;
    }
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
void popula_pilha(t_pilha *pilha)
{
    if (pilha->v == NULL)
    {
        printf("[ERRO] Pilha não foi inicializada corretamente!\n");
        return;
    }

    pilha->topo = 0;

    for (int i = 0; i < pilha->capacidade; i++)
    {
        pilha->v[pilha->topo++] = i + 1;
    }
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

void exibe_post_elem_top(t_pilha *p)
{
    if (esta_vazia(p))
    {
        printf("Pilha vazia - não há elemento no topo\n");
        return;
    }
    printf("topo: %d - elemento: %d\n", p->topo - 1, p->v[p->topo - 1]);
}

char *string_pilha(t_pilha *p)
{
    if (esta_vazia(p))
    {
        char *s = (char *)malloc(15);
        if (s == NULL)
            return NULL;
        strcpy(s, "pilha vazia\n");
        return s;
    }

    // 11 chars (-2147483648)
    // " - " (3 chars each) plus brackets "{}" plus null terminator
    int estimated_size = (p->topo * 11) + (p->topo * 3) + 10;
    char *s = (char *)malloc(estimated_size);
    if (s == NULL)
        return NULL;

    char s_aux[32];
    s[0] = '\0';

    strcat(s, "{");
    for (int i = p->topo - 1; i >= 0; i--)
    {
        sprintf(s_aux, "%d", p->v[i]);
        strcat(s, s_aux);
        if (i > 0)
            strcat(s, " - ");
    }
    strcat(s, "}");

    return s;
}

void print_pilha(t_pilha *p)
{
    if (esta_vazia(p))
    {
        printf("pilha vazia\n");
    }
    else
    {
        printf("Topo da pilha:\n");
        for (int i = p->topo - 1; i >= 0; i--)
        {
            printf("[ %d ]\n", p->v[i]);
        }
        printf("Base da pilha\n");
    }
}