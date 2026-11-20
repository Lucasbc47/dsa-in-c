#include "fila.h"

void constroi_fila(t_fila *f)
{
    f->primeiro = NULL;
    f->ultimo = NULL;
}

int fila_vazia(t_fila *f)
{
    return f->primeiro == NULL;
}

void enfileira(int i, t_fila *f)
{
    t_no *novo = constroi_no(i);
    if (fila_vazia(f))
    {
        f->primeiro = novo;
    }
    else
    {
        f->ultimo->proximo = novo;
    }
    f->ultimo = novo;
}

int desenfileira(t_fila *f)
{
    int i = -1;
    if (!fila_vazia(f))
    {
        i = f->primeiro->info;
        t_no *aux = f->primeiro;
        f->primeiro = f->primeiro->proximo;
        if (f->primeiro == NULL)
            f->ultimo = NULL; // esvaziou a fila
        free(aux);
    }
    return i;
}
void exibe_fila(t_fila *f)
{
    if (fila_vazia(f))
        printf("fila vazia");
    else
    {
        t_no *aux = f->primeiro;
        while (aux != NULL)
        {
            printf("%d ", aux->info);
            aux = aux->proximo;
        }
    }
}

int remove_todas_ocorrencias(t_fila *f, int x)
{
    int removidos = 0;
    t_no *anterior = NULL;
    t_no *atual = f->primeiro;

    while (atual != NULL)
    {
        // Encontrou o valor?
        if (atual->info == x)
        {
            t_no *temp = atual;

            // CASO 1: Remover do início
            if (anterior == NULL)
            {
                f->primeiro = atual->proximo;
                atual = f->primeiro;
            }
            // CASO 2: Remover do meio/fim
            else
            {
                anterior->proximo = atual->proximo;
                atual = atual->proximo;
            }

            // IMPORTANTE: Se removeu o último, atualiza f->ultimo
            if (temp == f->ultimo)
            {
                f->ultimo = anterior;
            }

            free(temp);
            removidos++;
        }
        // Não encontrou, avança
        else
        {
            anterior = atual;
            atual = atual->proximo;
        }
    }

    return removidos;
}