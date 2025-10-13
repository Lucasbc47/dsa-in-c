#include <stdio.h>

int main()
{
    int soma = 0;
    int limite = 1000;
    for (int i = 0; i < limite; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            soma += i;
    }
    printf("soma dos numeros naturais abaixo de 1000 que sao multiplos de 3 ou 5: %d", soma);
}