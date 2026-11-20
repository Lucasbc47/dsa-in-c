#include "lista.h"

void inicia_lista(t_lista *l)
{
    l->primeiro = NULL;
    l->tamanho = 0;
}
int esta_vazia(t_lista *l)
{
    return l->tamanho == 0;
}
int insere_inicio(int i, t_lista *l)
{
    t_no *novo = constroi_no(i);
    if (novo == NULL)
        return FRACASSO;
    if (!esta_vazia(l))
    {
        novo->proximo = l->primeiro;
    }
    l->primeiro = novo;
    l->tamanho++;
    return SUCESSO;
}
int remove_inicio(t_lista *l, int *i)
{
    if (esta_vazia(l))
        return FRACASSO;
    *i = l->primeiro->info;
    struct no *temp = l->primeiro;
    l->primeiro = l->primeiro->proximo;
    l->tamanho--;
    free(temp);
    return SUCESSO;
}
void exibe_lista(t_lista *l)
{
    if (esta_vazia(l))
        printf("lista vazia");
    else
    {
        struct no *aux = l->primeiro;
        while (aux != NULL)
        { // até o final da lista
            printf("[%d] -> ", aux->info);
            aux = aux->proximo;
        }
        printf("//\n");
    }
}
int insere_fim(int i, t_lista *l)
{
    t_no *novo = constroi_no(i);
    if (novo == NULL)
        return FRACASSO;
    if (esta_vazia(l))
        l->primeiro = novo;
    else
    {
        t_no *aux = l->primeiro;
        while (aux->proximo != NULL) // vai até o último elemento
            aux = aux->proximo;
        aux->proximo = novo;
    }
    l->tamanho++;
    return SUCESSO;
}
int remove_fim(t_lista *l, int *i)
{
    if (esta_vazia(l))
        return FRACASSO;
    if (l->primeiro->proximo == NULL)
    { // tem um só
        *i = l->primeiro->info;
        free(l->primeiro);
        l->primeiro = NULL;
    }
    else
    { // tem pelo menos 2 elementos
        t_no *aux = l->primeiro;
        while (aux->proximo->proximo != NULL)
        {
            aux = aux->proximo;
        }
        *i = aux->proximo->info;
        free(aux->proximo);
        aux->proximo = NULL;
    }
    l->tamanho--;
    return SUCESSO;
}

int rem_ocorrencia(int n, t_lista *lista)

{
    // Se a lista está vazia, retorna 0 (fracasso)
    if (esta_vazia(lista))
    {
        return 0;
    }

    // Percorre a lista procurando o número
    t_no *atual = lista->primeiro;
    t_no *anterior = NULL;

    for (int i = 0; i < lista->tamanho; i++)
    {
        // Se encontrou o número
        if (atual->info == n)
        {
            // Se é o primeiro nó
            if (anterior == NULL)
            {
                lista->primeiro = atual->proximo;
            }
            else
            {
                // Remove do meio ou fim
                anterior->proximo = atual->proximo;
            }
            free(atual);
            lista->tamanho--;
            return 1; // Sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }

    return 0; // Não encontrou
}

int conta_nos(t_lista *lista)
{
    int i = 0;
    t_no *atual = lista->primeiro;
    while (lista != NULL)
    {
        i++;
        atual = atual->proximo;
    }
    return i;
}

int insere_posicao(t_lista *lista, int valor, int pos)
{
    t_no *novo = constroi_no(valor);
    if (novo == NULL)
        return FRACASSO;

    // CASO 1: inserir no inicio (pos = 0 )
    if (pos <= 0)
    {
        novo->proximo = lista->primeiro;
        lista->primeiro = novo;
    }

    // CASO 2 e 3: meio e fim
    t_no *anterior = lista->primeiro;
    int i;

    for (int i = 0; i < pos - 1 && anterior->proximo != NULL; i++)
    {
        anterior = anterior->proximo;
    }

    // Insere depois do "anterior"
    novo->proximo = anterior->proximo;
    anterior->proximo = novo;
    lista->tamanho++;
}

