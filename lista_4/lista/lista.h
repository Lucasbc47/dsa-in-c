#include <stdlib.h>
#include <stdio.h>

#define SUCCESSO 0
#define FALHA 1

typedef struct t_no
{
    int info;
    struct t_no *proximo;
} t_no;
typedef struct t_lista
{
    int tamanho;
    struct t_no *primeiro;

} t_lista;

// no functions (auxiliares internas)
t_no *inicializa_no(int info);
void libera_no(t_no *no);

// lista functions (operacoes principais)
void inicializa_lista(t_lista *lista);
int vazia(t_lista *lista);

// operacoes de insercao
int adicionar_fim(t_lista *lista, int valor);

// operacoes de remocao
int remover_fim(t_lista *lista);
int remover_n_primeiros(t_lista *lista, int n);

// operacoes de consulta
int contar_n_positivos(t_lista *lista, int *pares);