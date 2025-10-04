#include "no.h"

t_no *constroi_no(int numero)
{
    t_no *no = (t_no *)malloc(sizeof(t_no));
    if (no != NULL)
    {
        no->info = numero;
        no->proximo = NULL;
    }
    return no;
}
