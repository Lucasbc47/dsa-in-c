#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArray
{
    int capacity; // numero de elementos
    int size;     // estado atual;
    int *data;    // pointer to the array;
} DynamicArray;

DynamicArray *init_array(int);
void destroy_array(DynamicArray *);

int insert_element(int, DynamicArray *);
int remove_element(int *, DynamicArray *);

int is_full(DynamicArray *);
int is_empty(DynamicArray *);

int resize_arr(DynamicArray *);

void mostra_vetor(DynamicArray *);
void preenche_vetor(DynamicArray *);
void libera_memoria(DynamicArray *);

// sorting
void bubble_sort(DynamicArray *);
void selection_sort(DynamicArray *);
void insertion_sort(DynamicArray *);