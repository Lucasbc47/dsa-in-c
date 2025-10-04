#include "no.h"

int main()
{
    t_no *n1 = (t_no *)malloc(sizeof(t_no));
    if (n1 == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    n1->info = 10;
    n1->proximo = NULL;

    t_no *n2 = (t_no *)malloc(sizeof(t_no));
    if (n2 == NULL)
    {
        printf("Memory allocation failed!\n");
        free(n1);
        return 1;
    }
    n2->info = 20;
    n2->proximo = NULL;

    n1->proximo = n2;

    printf("<n1: info=%d proximo_info=%d>\n",
           n1->info,
           n1->proximo != NULL ? n1->proximo->info : -1); // -1 if NULL

    printf("<n2: info=%d proximo_info=%s>\n",
           n2->info,
           n2->proximo != NULL ? "has value" : "NULL");

    if (n1->proximo != NULL)
    {
        printf("\nn1->info = %d, n1->proximo->info = %d\n",
               n1->info,
               n1->proximo->info);
    }

    free(n2);
    free(n1);
    return 0;
}