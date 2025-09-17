/*
    - Lista C02 -
    Faça um programa que leia 2 notas de um aluno, verifique se as notas são ao válidas e
    exiba na tela a média destas notas. Uma nota válida deve ser, obrigatoriamente, um
    valor entre 0.0 e 10.0, onde caso a nota não possua um valor válido, este fato deve ser
    informado ao usuário e o programa termina.
*/

#include <stdio.h>

int main()
{
    float nota_um, nota_dois, media;
    puts("Caro aluno, insira as notas:");
    scanf("%f%f", &nota_um, &nota_dois);

    if ((nota_um < 0.0 || nota_um > 10.0) || (nota_dois < 0.0 || nota_dois > 10.0))
    {
        puts("Nota invalida! Saindo do programa!");
        return 1;
    }
    media = (nota_um + nota_dois) / 2.0;
    printf("A media do aluno eh: %.1f\n", media);

    return 0;
}
