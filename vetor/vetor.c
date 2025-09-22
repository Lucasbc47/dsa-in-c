#include "vetor.h"

DynamicArray *init_array(int initial_capacity)
{
    // only use arrows when acessing a struct ptr;
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (!arr)
        return NULL;

    arr->data = malloc(sizeof(int) * initial_capacity);
    if (!arr->data)
    {
        free(arr);
        return NULL;
    }

    arr->capacity = initial_capacity;
    arr->size = 0;
    return arr;
}
void destroy_array(DynamicArray *arr)

{
    if (arr)
    {
        free(arr->data);
        free(arr);
    }
}

int insert_element(int number, DynamicArray *arr)
{
    if (is_full(arr) && !resize_arr(arr))
    {
        return 0;
    }

    arr->data[arr->size++] = number;
    return 1;
}

int remove_element(int *removed, DynamicArray *arr)
{
    if (is_empty(arr))
    {
        return 0;
    }
    *removed = arr->data[--arr->size];
    return 1;
}

int is_full(DynamicArray *arr)
{
    return arr->size == arr->capacity;
}

int is_empty(DynamicArray *arr)
{
    return arr->size == 0;
}

int resize_arr(DynamicArray *arr)
{
    int new_capacity = arr->capacity * 2;
    int *new_data = realloc(arr->data, sizeof(int) * new_capacity);

    if (!new_data)
    {
        return 0;
    }

    arr->data = new_data;
    arr->capacity = new_capacity;
    return 1;
}