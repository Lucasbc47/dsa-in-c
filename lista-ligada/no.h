#include <stdio.h>
#include <stdlib.h>

// head: sempre o primeiro nó, que aponta para o primeiro valor.
// tail: sempre o ultimo nó, que aponta para null.

typedef struct t_no
{
    int info;
    struct t_no *proximo;
} t_no;

t_no *constroi_no(int);

/*

head                                          tail
 │                                             │
 ▼                                             ▼
┌──────────┐    ┌──────────┐    ┌──────────┐
│ info: 10 │    │ info: 20 │    │ info: 30 │
│ proximo ─┼───>│ proximo ─┼───>│ proximo ─┼──> NULL
└──────────┘    └──────────┘    └──────────┘
   primeiro        meio           último
*/

// t_no *head;
// head->info : 10
// head->proximo->info : 20
// head->proximo->proximo->info : 30
// head->proximo->proximo->proximo : NULL