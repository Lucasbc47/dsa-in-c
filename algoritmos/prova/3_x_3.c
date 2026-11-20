#include <stdio.h>

int main()
{
    const int size = 3;
    int A[3][3];

    printf("Insira a matriz 3x3:\n");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("{");
        for (int j = 0; j < size; j++)
        {
            printf(" %d ", A[i][j]);
            if (j < size - 1)
                printf(", ");
        }
        printf("}\n");
    }

    return 0;
}