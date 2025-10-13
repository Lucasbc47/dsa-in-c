#include <stdio.h>

int main()
{
    int n = 0, a = 0, b = 1;

    printf("n: ");
    scanf("%d", &n);

    printf("sequencia ate -> %d:\n", n);
    printf("%d ", a);

    while (b <= n)
    {
        printf("%d ", b);
        int y = a + b;
        a = b;
        b = y;
    }

    printf("%d", b);
    return 0;
}