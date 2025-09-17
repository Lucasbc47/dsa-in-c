/*
    - Lista C02 -
    Usando switch, escreva um programa que leia um inteiro entre 1 e 7 e imprima o dia
    da semana correspondente a este numero. Isto e, domingo se ´ 1, segunda-feira se 2, e
    assim por diante.
*/

#include <stdio.h>

int main()
{
    int dia;
    puts("Insira um numero entre 1 e 7:");
    scanf("%d", &dia);

    switch (dia)
    {
    case 1:
        puts("Domingo");
        break;
    case 2:
        puts("Segunda-feira");
        break;
    case 3:
        puts("Terca-feira");
        break;
    case 4:
        puts("Quarta-feira");
        break;
    case 5:
        puts("Quinta-feira");
        break;
    case 6:
        puts("Sexta-feira");
        break;
    case 7:
        puts("Sabado");
        break;
    default:
        puts("Numero invalido!");
        break;
    }

    return 0;
}