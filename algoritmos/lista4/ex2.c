#include <stdio.h>

int main()
{
    int vetor[6];

    printf("Insira os 6 valores:\n");

    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &vetor[i]);
    };

    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", vetor[i]);
    };

    return 0;
}