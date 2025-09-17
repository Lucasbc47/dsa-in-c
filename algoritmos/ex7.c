#include <stdio.h>

int main()
{
    float C, F;
    printf("F:");
    scanf("%f", &F);
    C = 5.0 * (F - 32.0) / 9.0;
    printf("C: %.2f", C);

    return 0;
}