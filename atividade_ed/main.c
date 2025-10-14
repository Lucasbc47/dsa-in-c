// exclui importações inuteis. importamos somente o que utilizamos da API.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonte: https://github.com/amachion/2025_2_ipi_ed/
void selection_sort(int v[], int n);
void bubble_sort(int v[], int n);
void insertion_sort(int v[], int n);
void quick_sort(int v[], int inicio, int fim);

void salvar(const char *algoritmo, int n, double tempo_medio_ms);

#define REPETICOES 10
/*
    "Repetir a ordenação 10 vezes sobre vetores gerados randomicamente,
    para cada tamanho e calcular o tempo médio das 10 execuções."
*/
// macro simples para preenchimento do vetor
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
    int tamanhos[] = {2000, 4000, 8000, 12000, 16000};
    int num_tamanhos = 5;

    LARGE_INTEGER freq, inicio, fim;
    QueryPerformanceFrequency(&freq);

    srand(time(NULL));

    for (int t = 0; t < num_tamanhos; t++)
    {
        int tam = tamanhos[t];
        int *vetor = (int *)malloc(tam * sizeof(int));

        if (vetor == NULL)
        {
            printf("[ERRO]: Nao foi possivel alocar memoria....");
            continue;
        }

        printf(">>>>> %d <<<<<\n", tam);

        // bubble sort
        double tempo_total_bubble = 0.0;
        for (int rep = 0; rep < REPETICOES; rep++)
        {
            PREENCHER_VETOR(vetor, tam, 10000);
            QueryPerformanceCounter(&inicio);
            bubble_sort(vetor, tam);
            QueryPerformanceCounter(&fim);
            tempo_total_bubble += (fim.QuadPart - inicio.QuadPart) * 1000.0 / freq.QuadPart;
        }
        double tempo_medio_bubble = tempo_total_bubble / REPETICOES;
        printf("Media do (Bubble): %.3f ms\n", tempo_medio_bubble);
        salvar("Bubble", tam, tempo_medio_bubble);

        // insertion sort
        double tempo_total_insertion = 0.0;
        for (int rep = 0; rep < REPETICOES; rep++)
        {
            PREENCHER_VETOR(vetor, tam, 10000);
            QueryPerformanceCounter(&inicio);
            insertion_sort(vetor, tam);
            QueryPerformanceCounter(&fim);
            tempo_total_insertion += (fim.QuadPart - inicio.QuadPart) * 1000.0 / freq.QuadPart;
        }
        double tempo_medio_insertion = tempo_total_insertion / REPETICOES;
        printf("Media do (Insertion): %.3f ms\n", tempo_medio_insertion);
        salvar("Insertion", tam, tempo_medio_insertion);

        // selection sort
        double tempo_total_selection = 0.0;
        for (int rep = 0; rep < REPETICOES; rep++)
        {
            PREENCHER_VETOR(vetor, tam, 10000);
            QueryPerformanceCounter(&inicio);
            selection_sort(vetor, tam);
            QueryPerformanceCounter(&fim);
            tempo_total_selection += (fim.QuadPart - inicio.QuadPart) * 1000.0 / freq.QuadPart;
        }
        double tempo_medio_selection = tempo_total_selection / REPETICOES;
        printf("Media do (Selection): %.3f ms\n", tempo_medio_selection);
        salvar("Selection", tam, tempo_medio_selection);

        // quick sort
        double tempo_total_quick = 0.0;
        for (int rep = 0; rep < REPETICOES; rep++)
        {
            PREENCHER_VETOR(vetor, tam, 10000);
            QueryPerformanceCounter(&inicio);
            quick_sort(vetor, 0, tam - 1);
            QueryPerformanceCounter(&fim);
            tempo_total_quick += (fim.QuadPart - inicio.QuadPart) * 1000.0 / freq.QuadPart;
        }
        double tempo_medio_quick = tempo_total_quick / REPETICOES;
        printf("Media do (Quick): %.3f ms\n", tempo_medio_quick);
        salvar("Quick", tam, tempo_medio_quick);
        printf("\n");
        free(vetor);
    }
    puts(">> Fim dos testes. Confira resultados em 'resultados.csv'");
    system("pause");
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

        int part = i + 1;

        quick_sort(v, inicio, part - 1);
        quick_sort(v, part + 1, fim);
    }
}
void salvar(const char *alg, int n, double tempo_ms)
{
    // 'a': append e 'r': read
    FILE *arq = fopen("resultados.csv", "r");
    int header = (arq == NULL);
    if (arq != NULL)
        fclose(arq);
    arq = fopen("resultados.csv", "a");
    if (arq == NULL)
    {
        printf("[ERRO]: Nao foi possivel abrir o CSV!");
        return;
    }
    if (header)
        fprintf(arq, "algoritmo;n;tempo_medio_ms\n");
    fprintf(arq, "%s;%d;%.3f\n", alg, n, tempo_ms);
    fclose(arq);
}