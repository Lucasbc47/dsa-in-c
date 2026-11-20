#include <stdio.h>
#include <stdlib.h>

#define FRACASSO 0 
#define SUCESSO 1

typedef struct no
{
    int info;
    struct no *proximo;
} t_no;

t_no *constroi_no(int);