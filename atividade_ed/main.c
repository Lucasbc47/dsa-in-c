#include <windows.h>
#include <stdio.h>
#include <time.h>

#define WIN32_LEAN_AND_MEAN
// Exclui funcionalidades raramente usadas do windows.h para acelerar a compilação

// Fonte: https://github.com/amachion/2025_2_ipi_ed/
void selection_sort(int v[], int n);
void bubble_sort(int v[], int n);
void insertion_sort(int v[], int n);
void quick_sort(int v[], int inicio, int fim);

void salvar(const char *algoritmo, int n, double tempo_medio_ms);

#ifndef TAM
#define TAM 2000
#endif
// 2000, 4000, 8000, 12000, 16000

#define PREENCHER_VETOR(vetor, tamanho, max_valor) \
    do                                             \
    {                                              \
        for (int i = 0; i < (tamanho); i++)        \
        {                                          \
            (vetor)[i] = rand() % (max_valor);     \
        }                                          \
    } while (0)

int main()
{
    int vetor[TAM];
    srand(time(NULL));

    PREENCHER_VETOR(vetor, TAM, 10000);
    LARGE_INTEGER freq, inicio, fim;
    QueryPerformanceFrequency(&freq);

    // ------------
    // bubble
    QueryPerformanceCounter(&inicio);
    bubble_sort(vetor, TAM);
    QueryPerformanceCounter(&fim);
    double tempo_ms = (fim.QuadPart - inicio.QuadPart) * 1000.0 / freq.QuadPart;
    printf("Tempo (bubble): %.3f ms\n", tempo_ms);
    salvar("Bubble", TAM, tempo_ms);
    // ------------

    PREENCHER_VETOR(vetor, TAM, 10000);

    // ------------
    // quick
    QueryPerformanceCounter(&inicio);
    quick_sort(vetor, 0, TAM - 1);
    QueryPerformanceCounter(&fim);
    tempo_ms = (fim.QuadPart - inicio.QuadPart) * 1000.0 / freq.QuadPart;
    printf("Tempo (quick): %.3f ms\n", tempo_ms);
    salvar("Quick", TAM, tempo_ms);
    // ------------

    PREENCHER_VETOR(vetor, TAM, 10000);

    // ------------
    // insertion
    QueryPerformanceCounter(&inicio);
    insertion_sort(vetor, TAM);
    QueryPerformanceCounter(&fim);
    tempo_ms = (fim.QuadPart - inicio.QuadPart) * 1000.0 / freq.QuadPart;
    printf("Tempo (insertion): %.3f ms\n", tempo_ms);
    salvar("Insertion", TAM, tempo_ms);
    // ------------

    PREENCHER_VETOR(vetor, TAM, 10000);

    // ------------
    // selection
    QueryPerformanceCounter(&inicio);
    selection_sort(vetor, TAM);
    QueryPerformanceCounter(&fim);
    tempo_ms = (fim.QuadPart - inicio.QuadPart) * 1000.0 / freq.QuadPart;
    printf("Tempo (selection): %.3f ms\n", tempo_ms);
    salvar("Selection", TAM, tempo_ms);
    // ------------

    return 0;
}
void selection_sort(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[pos])
                pos = j;
        }
        if (pos != i)
        {
            int aux = v[i];
            v[i] = v[pos];
            v[pos] = aux;
        }
    }
}
void bubble_sort(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[i])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}
void insertion_sort(int v[], int n)
{
    for (int j = 1; j < n; ++j)
    {
        int x = v[j];
        int i;
        for (i = j - 1; i >= 0 && v[i] > x; --i)
        {
            v[i + 1] = v[i];
        }
        v[i + 1] = x;
    }
}
void quick_sort(int v[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = v[fim];
        int i = inicio - 1;

        for (int j = inicio; j < fim; j++)
        {
            if (v[j] <= pivo)
            {
                i++;
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }

        int aux = v[i + 1];
        v[i + 1] = v[fim];
        v[fim] = aux;

        int particao = i + 1;

        quick_sort(v, inicio, particao - 1);
        quick_sort(v, particao + 1, fim);
    }
}
void salvar(const char *algoritmo, int n, double tempo_medio_ms)
{
    FILE *arq = NULL;
    int precisa_cabecalho = 0;
    arq = fopen("resultados.csv", "r");
    if (arq == NULL)
    {
        precisa_cabecalho = 1;
    }
    else
    {
        fclose(arq);
    }
    arq = fopen("resultados.csv", "a");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    if (precisa_cabecalho == 1)
    {
        fprintf(arq, "algoritmo;n;tempo_medio_ms\n");
    }

    fprintf(arq, "%s,%d,%.3f\n", algoritmo, n, tempo_medio_ms);
    fclose(arq);
}