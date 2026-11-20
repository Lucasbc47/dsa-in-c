#include "no.h"

t_no *constroi_no(int n)
{
    t_no *novo = (t_no *)malloc(sizeof(t_no));
    if (novo != NULL)
    {
        novo->info = n;
        novo->proximo = NULL;
    }
    return novo;
}