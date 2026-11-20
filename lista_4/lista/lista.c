#include "lista.h"

void inicializa_lista(t_lista *lista)
{
    lista->primeiro = NULL;
    lista->tamanho = 0;
}

t_no *inicializa_no(int info)
{
    t_no *node = (t_no *)malloc(sizeof(t_no));
    if (node != NULL)
    {
        node->info = info;
        node->proximo = NULL;
    }
    return node;
}

void libera_no(t_no *no)
{
    free(no);
}

int vazia(t_lista *lista)
{
    return lista->tamanho == 0;
}

int adicionar_fim(t_lista *lista, int valor)
{
    t_no *novo = inicializa_no(valor);
    if (novo == NULL)
        return FALHA;

    if (vazia(lista))
    {
        lista->primeiro = novo;
    }
    else
    {
        t_no *atual = lista->primeiro;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    lista->tamanho++;
    return SUCCESSO;
}

int remover_fim(t_lista *lista)
{
    if (vazia(lista))
        return FALHA;

    if (lista->primeiro->proximo == NULL)
    {
        libera_no(lista->primeiro);
        lista->primeiro = NULL;
    }
    else
    {
        t_no *atual = lista->primeiro;
        while (atual->proximo->proximo != NULL)
        {
            atual = atual->proximo;
        }
        libera_no(atual->proximo);
        atual->proximo = NULL;
    }
    lista->tamanho--;
    return SUCCESSO;
}

int remover_n_primeiros(t_lista *lista, int n)
{
    // Validacoes
    if (vazia(lista))
        return FALHA;

    if (n <= 0)
        return FALHA;

    if (n > lista->tamanho)
        return FALHA;

    // Remover N vezes
    for (int i = 0; i < n; i++)
    {
        // Guardar referencia ao primeiro no
        t_no *temp = lista->primeiro;

        // Avancar o ponteiro primeiro para o proximo
        lista->primeiro = lista->primeiro->proximo;

        // Liberar o no antigo
        libera_no(temp);

        // Decrementar tamanho
        lista->tamanho--;
    }

    return SUCCESSO;
}

int contar_n_positivos(t_lista *lista, int *pares)
{
    // Considere uma lista contendo numeros inteiros positivos.
    // Faca uma funcao que retorne
    // quantos numeros pares existem na lista.

    // Validacoes
    if (vazia(lista))
        return FALHA;

    if (pares == NULL)
        return FALHA;

    // Inicializar contador
    *pares = 0;

    // Ponteiro auxiliar para percorrer (NAO modifica a lista!)
    t_no *atual = lista->primeiro;

    // Percorrer toda a lista
    while (atual != NULL)
    {
        // Se o valor for par
        if (atual->info % 2 == 0)
        {
            (*pares)++;  // Incrementa o valor apontado
        }
        atual = atual->proximo;  // Avanca o ponteiro auxiliar
    }

    return SUCCESSO;
}