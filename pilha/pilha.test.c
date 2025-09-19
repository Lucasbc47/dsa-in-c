 #include "pilha.h"

int main()
{
    int capacidade = 0;

    printf("Insira a capacidade da pilha:\n");
    scanf("%d", &capacidade);

    t_pilha stack = inicializa_pilha(capacidade);
    popula_pilha(&stack);
    mostra_pilha(&stack);

    int removido;
    pop(&stack, &removido);
    printf("-- Removido: %d\n", removido);
    mostra_pilha(&stack);

    int adicionar = 0;
    printf("Insira um valor para adicionar: ");
    scanf("%d", &adicionar);
    push(&stack, adicionar);
    printf("-- Adicionado: %d\n", adicionar);
    mostra_pilha(&stack);

    // printf("%p\n", &stack);
    free(stack.v);
    return 0;
}