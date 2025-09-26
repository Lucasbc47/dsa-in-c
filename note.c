#include <stdio.h>
#include <stdlib.h>
// struct:
/*
    - Uma `struct` é uma estrutura de dado heterogênea e palavra reservada em C.
    - Se trata de uma estrutura na qual contém dados de forma 'contígua' ("se enconsta")
    na memória;
    - Te dá liberdade de agrupar diferentes tipos de dados em C em um só espaço próximo.
*/
struct Pessoa
{
    // membros
    char nome[20];
    int idade;
    float altura;
};

// pode se usar `typedef` para sua simplificação
struct Pessoa pessoa;
// strcpy(pessoa.nome, "Lucas");
// é possível ter um `array de structs`
struct Node
{
    struct Node *node;
};

// ponteiros
/*
    - Um ponteiro é o nome que damos a uma variavel quando a mesma carrega um endereço de
    memória de outra variável.
    - São representadas por um asterisco '*' em sua declaração.
    - Eles são mais proximos de um int. Especificamente hexadecimais.
    - Eles tambem tem tamanho fixo: 8 bytes (64 bits). independente do tipo
*/
// para passarmos o endereço de uma variavel, usamos operador de referência, '&'
int var = 10;
int *ptr;
*ptr = &var; // *ptr -> 10; desreferenciamento

// Vetor / Array
/*
    -Arrays são estruturas de dados homogêneas em C
    - Todos os elementos devem ser do mesmo tipo
    - Tamanho final é calculado pelo tamanho do tipo de dado em C multiplicado
    pela quantidade de itens;
    */
int nums[6] = {3, 5, 6, 8, 9, 0};
// sizeof(int) = 4 bytes
// 4 x 6 : 24 bytes alocado

// Vetores (Arrays) Dinâmicos
typedef struct DynamicArray
{
    int capacity; // estado atual;
    int size;     // numero de elementos
    int *data;    // pointer to the array;
} DynamicArray;

DynamicArray init_array(int size)
{
    // only use arrows when acessing a struct ptr;
    DynamicArray new_arr;
    new_arr.size = size;
    new_arr.capacity = 0;
    new_arr.data = (int *)malloc(sizeof(int) * size);
    if (new_arr.data == NULL)
    {
        new_arr.size = 0;
        printf("[error]: failed while trying to aloocatingdata!\n");
    }
}
