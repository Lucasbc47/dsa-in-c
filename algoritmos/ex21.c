/*
    - Lista C02 -
    Escreva o menu de opcoes abaixo. Leia a opcao do usuario e execute a operacao esco
    lhida. Escreva uma mensagem de erro se a opcao for invalida.
    Escolha a opcão:
    1- Soma de 2 numeros.
    2- Diferenca entre 2 numeros (maior pelo menor).
    3- Produto entre 2 numeros.
    4- Divisão entre 2 numeros (o denominador não pode ser zero).
    Opcão
*/

#include <stdio.h>

int main()
{
    int opcao;
    float num1, num2, resultado;

    puts("Escolha a opcao:");
    puts("1- Soma de 2 numeros.");
    puts("2- Diferenca entre 2 numeros (maior pelo menor).");
    puts("3- Produto entre 2 numeros.");
    puts("4- Divisao entre 2 numeros (o denominador nao pode ser zero).");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        puts("Digite dois numeros:");
        scanf("%f %f", &num1, &num2);
        resultado = num1 + num2;
        printf("Soma: %.2f\n", resultado);
        break;
    case 2:
        puts("Digite dois numeros:");
        scanf("%f %f", &num1, &num2);
        if (num1 > num2)
        {
            resultado = num1 - num2;
        }
        else
        {
            resultado = num2 - num1;
        }
        printf("Diferenca: %.2f\n", resultado);
        break;
    case 3:
        puts("Digite dois numeros:");
        scanf("%f %f", &num1, &num2);
        resultado = num1 * num2;
        printf("Produto: %.2f\n", resultado);
        break;
    case 4:
        puts("Digite dois numeros:");
        scanf("%f %f", &num1, &num2);
        if (num2 != 0)
        {
            resultado = num1 / num2;
            printf("Divisao: %.2f\n", resultado);
        }
        else
        {
            puts("Denominador nao pode ser zero!");
        }
        break;
    default:
        puts("Opcao invalida!");
        break;
    }

    return 0;
}