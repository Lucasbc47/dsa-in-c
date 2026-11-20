#include <stdio.h>

int main()
{
    int arr[10];
    int pares = 0;
    printf("insira os 10 elementos:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
            pares++;
    }
    printf("pares: %d\n", pares);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}