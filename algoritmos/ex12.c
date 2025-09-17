/*
    - Lista C02 -
    Ler um número inteiro. Se o número lido for negativo, escreva a mensagem “Número inválido”.
    Se o número for positivo, calcular o logaritmo deste número.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int numero;
    puts("Insira um numero:");
    scanf("%d", &numero);

    if (numero < 0)
    {
        puts("Numero invalido");
    }
    else if (numero == 0)
    {
        puts("Nao tem");
    }
    else
    {
        double logaritmo = log(numero);
        printf("log de %d: %.5f\n", numero, logaritmo);
    }

    return 0;
}