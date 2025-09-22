#include <stdio.h>
#include "vetor.h"

void imprime_array(DynamicArray *arr)
{
    printf("<DynamicArray capacity=%d size=%d elements=[", arr->capacity, arr->size);
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1)
            printf(", ");
    }
    printf("]>\n"); 
}

int main()
{
    printf("=== Testes do Array Dinamico ===\n\n");

    // Teste 1: Criar array
    printf("1. Criando array com capacidade 3:\n");
    DynamicArray *arr = init_array(3);
    imprime_array(arr);
    printf("\n");

    // Teste 2: Adicionar elementos
    printf("2. Adicionando elementos:\n");
    insert_element(10, arr);
    printf("   Apos inserir 10: ");
    imprime_array(arr);

    insert_element(20, arr);
    printf("   Apos inserir 20: ");
    imprime_array(arr);

    insert_element(30, arr);
    printf("   Apos inserir 30: ");
    imprime_array(arr);
    printf("\n");

    // Teste 3: Forcar resize
    printf("3. Forcando resize ao adicionar 40:\n");
    printf("   Antes do resize: ");
    imprime_array(arr);
    insert_element(40, arr);
    printf("   Apos o resize:   ");
    imprime_array(arr);
    printf("\n");

    // Teste 4: Remover elementos
    printf("4. Removendo elementos:\n");
    int removido;

    remove_element(&removido, arr);
    printf("   Removeu %d: ", removido);
    imprime_array(arr);

    remove_element(&removido, arr);
    printf("   Removeu %d: ", removido);
    imprime_array(arr);

    remove_element(&removido, arr);
    printf("   Removeu %d: ", removido);
    imprime_array(arr);

    remove_element(&removido, arr);
    printf("   Removeu %d: ", removido);
    imprime_array(arr);
    printf("\n");

    // Teste 5: Array vazio
    printf("5. Testando array vazio:\n");
    printf("   Estado atual: ");
    imprime_array(arr);
    printf("   is_empty(): %s\n", is_empty(arr) ? "verdadeiro" : "falso");
    printf("   Tentando remover: %s\n",
           remove_element(&removido, arr) ? "sucesso" : "falhou");
    printf("\n");

    // Teste 6: Reencher e mostrar estado final
    printf("6. Reenchendo array:\n");
    insert_element(100, arr);
    insert_element(200, arr);
    insert_element(300, arr);
    printf("   Estado final: ");
    imprime_array(arr);

    destroy_array(arr);
    printf("\n=== Testes Completos ===\n");

    return 0;
}