#include "lista/lista.h"

void imprimir_lista(t_lista *lista)
{
    if (vazia(lista))
    {
        printf("Lista vazia\n");

        return;
    }

    printf("Lista (tamanho %d): ", lista->tamanho);
    t_no *atual = lista->primeiro;
    while (atual != NULL)
    {
        printf("%d ", atual->info);
        if (atual->proximo != NULL)
            printf("-> ");
        atual = atual->proximo;
    }
    printf("\n");
}

void teste_basico()
{
    printf("=== TESTE BASICO: adicionar e imprimir ===\n");
    t_lista lista;
    inicializa_lista(&lista);

    adicionar_fim(&lista, 10);
    adicionar_fim(&lista, 20);
    adicionar_fim(&lista, 30);
    adicionar_fim(&lista, 40);
    adicionar_fim(&lista, 50);

    imprimir_lista(&lista);
    printf("\n");
}

void teste_remover_fim()
{
    printf("=== TESTE: remover_fim ===\n");
    t_lista lista;
    inicializa_lista(&lista);

    adicionar_fim(&lista, 10);
    adicionar_fim(&lista, 20);
    adicionar_fim(&lista, 30);

    printf("Lista original: ");
    imprimir_lista(&lista);

    remover_fim(&lista);
    printf("Apos remover_fim(): ");
    imprimir_lista(&lista);

    remover_fim(&lista);
    printf("Apos remover_fim(): ");
    imprimir_lista(&lista);
    printf("\n");
}

void teste_remover_n_primeiros()
{
    printf("=== TESTE: remover_n_primeiros ===\n");

    // Teste 1: remover 2 primeiros de uma lista com 5 elementos
    printf("\nTeste 1: Lista com 5 elementos, remover 2 primeiros\n");
    t_lista lista1;
    inicializa_lista(&lista1);
    adicionar_fim(&lista1, 1);
    adicionar_fim(&lista1, 2);
    adicionar_fim(&lista1, 3);
    adicionar_fim(&lista1, 4);
    adicionar_fim(&lista1, 5);
    printf("Antes:  ");
    imprimir_lista(&lista1);
    remover_n_primeiros(&lista1, 2);
    printf("Depois: ");
    imprimir_lista(&lista1);
    printf("Esperado: 3 -> 4 -> 5\n");

    // Teste 2: remover 1 primeiro
    printf("\nTeste 2: Lista com 4 elementos, remover 1 primeiro\n");
    t_lista lista2;
    inicializa_lista(&lista2);
    adicionar_fim(&lista2, 10);
    adicionar_fim(&lista2, 20);
    adicionar_fim(&lista2, 30);
    adicionar_fim(&lista2, 40);
    printf("Antes:  ");
    imprimir_lista(&lista2);
    remover_n_primeiros(&lista2, 1);
    printf("Depois: ");
    imprimir_lista(&lista2);
    printf("Esperado: 20 -> 30 -> 40\n");

    // Teste 3: remover todos os elementos
    printf("\nTeste 3: Lista com 3 elementos, remover 3 primeiros\n");
    t_lista lista3;
    inicializa_lista(&lista3);
    adicionar_fim(&lista3, 100);
    adicionar_fim(&lista3, 200);
    adicionar_fim(&lista3, 300);
    printf("Antes:  ");
    imprimir_lista(&lista3);
    remover_n_primeiros(&lista3, 3);
    printf("Depois: ");
    imprimir_lista(&lista3);
    printf("Esperado: Lista vazia\n");

    // Teste 4: remover mais elementos do que existem
    printf("\nTeste 4: Lista com 2 elementos, tentar remover 5 primeiros\n");
    t_lista lista4;
    inicializa_lista(&lista4);
    adicionar_fim(&lista4, 7);
    adicionar_fim(&lista4, 8);
    printf("Antes:  ");
    imprimir_lista(&lista4);
    int resultado = remover_n_primeiros(&lista4, 5);
    printf("Depois: ");
    imprimir_lista(&lista4);
    printf("Resultado: %s\n", resultado == SUCCESSO ? "SUCCESSO" : "FALHA");
    printf("Esperado: deve retornar FALHA ou remover todos\n");

    printf("\n");
}

void teste_contar_pares()
{
    printf("=== TESTE: contar_n_positivos (contar pares) ===\n");

    // Teste 1: Lista com alguns pares
    printf("\nTeste 1: Lista com valores [2, 5, 8, 11, 14]\n");
    t_lista lista1;
    inicializa_lista(&lista1);
    adicionar_fim(&lista1, 2);   // par
    adicionar_fim(&lista1, 5);   // impar
    adicionar_fim(&lista1, 8);   // par
    adicionar_fim(&lista1, 11);  // impar
    adicionar_fim(&lista1, 14);  // par
    printf("Antes:  ");
    imprimir_lista(&lista1);

    int pares1 = 0;
    contar_n_positivos(&lista1, &pares1);
    printf("Quantidade de pares: %d\n", pares1);
    printf("Esperado: 3 pares (2, 8, 14)\n");
    printf("Lista depois da contagem: ");
    imprimir_lista(&lista1);
    printf("Esperado: lista deve permanecer intacta\n");

    // Teste 2: Lista so com impares
    printf("\nTeste 2: Lista com valores [1, 3, 5, 7]\n");
    t_lista lista2;
    inicializa_lista(&lista2);
    adicionar_fim(&lista2, 1);
    adicionar_fim(&lista2, 3);
    adicionar_fim(&lista2, 5);
    adicionar_fim(&lista2, 7);
    printf("Antes:  ");
    imprimir_lista(&lista2);

    int pares2 = 0;
    contar_n_positivos(&lista2, &pares2);
    printf("Quantidade de pares: %d\n", pares2);
    printf("Esperado: 0 pares\n");
    printf("Lista depois: ");
    imprimir_lista(&lista2);

    // Teste 3: Lista so com pares
    printf("\nTeste 3: Lista com valores [2, 4, 6, 8]\n");
    t_lista lista3;
    inicializa_lista(&lista3);
    adicionar_fim(&lista3, 2);
    adicionar_fim(&lista3, 4);
    adicionar_fim(&lista3, 6);
    adicionar_fim(&lista3, 8);
    printf("Antes:  ");
    imprimir_lista(&lista3);

    int pares3 = 0;
    contar_n_positivos(&lista3, &pares3);
    printf("Quantidade de pares: %d\n", pares3);
    printf("Esperado: 4 pares\n");
    printf("Lista depois: ");
    imprimir_lista(&lista3);

    printf("\n");
}

int main()
{
    teste_basico();
    teste_remover_fim();
    teste_remover_n_primeiros();
    teste_contar_pares();

    printf("=== TESTES CONCLUIDOS ===\n");
    return 0;
}