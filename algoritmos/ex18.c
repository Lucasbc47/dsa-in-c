#include <stdio.h>

int main()
{
    float L, M;
    printf("M:");
    scanf("%f", &M);
    L = M * 1000.0f;
    printf("L: %.2f", L);

    return 0;
}