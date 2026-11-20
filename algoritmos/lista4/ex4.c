#include <stdio.h>

int main()
{
    int arr[8];
    printf("insira os 8 elementos:\n");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &arr[i]);
    }

    // avoid ub
    int x, y = 0;
    printf("insira x:\n");
    scanf("%d", &x);

    printf("insira y:\n");
    scanf("%d", &y);

    if (x < 0 || x >= 8 || y < 0 || y >= 8)
    {
        printf("indice fora de escopo!");
        return -1;
    }
    printf("x:%d, y:%d, soma:%d", arr[x], arr[y], (arr[x] + arr[y]));
    return 0;
}