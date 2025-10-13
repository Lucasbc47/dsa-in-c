#include <stdio.h>

int main()
{
    int idade = 0;
    float altura_chico = 1.50;
    float altura_ze = 1.10;

    while (altura_ze <= altura_chico)
    {
        altura_ze += 0.03;
        altura_chico += 0.02;
        idade++;
    }

    printf("daqui %d anos ze sera maior que chico", idade);
    return 0;
}