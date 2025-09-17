/*
    - Lista C02 -
    Escreva um programa que, dados dois numeros inteiros, mostre na tela o maior deles,
    assim como a diferença existente entre ambos.
*/
#include <stdio.h>

int main()
{
    int numero_um, numero_dois;
    puts("Insira dois numeros:");
    scanf("%d%d", &numero_um, &numero_dois);

    printf("%d eh o maior\n%d eh a diferenca entre eles\n",
           (numero_um > numero_dois ? numero_um : numero_dois),
           (numero_um > numero_dois ? numero_um - numero_dois : numero_dois - numero_um));
    return 0;
}
