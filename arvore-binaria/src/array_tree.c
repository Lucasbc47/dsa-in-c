#include <stdio.h>
#define MAX 100

typedef struct
{
    int info[MAX];
    int size;
} ArrayTree;

void init(ArrayTree *tree)
{
    tree->size = 0;
    tree->info[0] = -1; // Índice 0 não usado
}

int pai(int i)
{
    return (i == 1) ? -1 : i / 2;
}

int filho_esq(int i, int size)
{
    int esq = 2 * i;
    return (esq <= size) ? esq : -1;
}

int filho_dir(int i, int size)
{
    int dir = 2 * i + 1;
    return (dir <= size) ? dir : -1;
}

int eh_folha(int i, int size)
{
    return filho_esq(i, size) == -1;
}

void inserir(ArrayTree *tree, int valor)
{
    tree->size++;
    tree->info[tree->size] = valor;
}

void imprimir_array(ArrayTree *tree)
{
    printf("Array: [");
    for (int i = 1; i <= tree->size; i++)
    {
        printf("%d", tree->info[i]);
        if (i < tree->size)
            printf(", ");
    }
    printf("]\n");
}

void imprimir_info_no(ArrayTree *tree, int idx)
{
    printf("\nNo %d (indice %d):\n", tree->info[idx], idx);

    int p = pai(idx);
    if (p != -1)
        printf("  Pai: %d (indice %d)\n", tree->info[p], p);
    else
        printf("  Pai: nenhum (eh raiz)\n");

    int esq = filho_esq(idx, tree->size);
    if (esq != -1)
        printf("  Filho esquerdo: %d (indice %d)\n", tree->info[esq], esq);
    else
        printf("  Filho esquerdo: nenhum\n");

    int dir = filho_dir(idx, tree->size);
    if (dir != -1)
        printf("  Filho direito: %d (indice %d)\n", tree->info[dir], dir);
    else
        printf("  Filho direito: nenhum\n");

    if (eh_folha(idx, tree->size))
        printf("  >> Este no eh uma FOLHA!\n");
}

int main()
{
    ArrayTree tree;
    init(&tree);

    printf("=== Arvore Binaria - Representacao em Array ===\n\n");

    // Inserindo valores 1 a 9
    for (int i = 1; i <= 9; i++)
    {
        inserir(&tree, i);
    }

    imprimir_array(&tree);

    printf("\nArvore visualizada:\n");
    printf("              1\n");
    printf("            /   \\\n");
    printf("           2     3\n");
    printf("          / \\   / \\\n");
    printf("         4   5 6   7\n");
    printf("        / \\\n");
    printf("       8   9\n");

    // Informações de nós específicos
    imprimir_info_no(&tree, 1); // Raiz
    imprimir_info_no(&tree, 2); // Nó intermediário
    imprimir_info_no(&tree, 4); // Nó com filhos
    imprimir_info_no(&tree, 7); // Folha

    // Lista todas as folhas
    printf("\n=== Folhas da arvore ===\n");
    for (int i = 1; i <= tree.size; i++)
    {
        if (eh_folha(i, tree.size))
        {
            printf("No %d (indice %d)\n", tree->info[i], i);
        }
    }

    return 0;
}
