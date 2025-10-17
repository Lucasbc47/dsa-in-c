// exclui importações inuteis. importamos somente o que utilizamos da API.
// exclui importações inuteis. importamos somente o que utilizamos da API.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonte: https://github.com/amachion/2025_2_ipi_ed/
// obs: o bubble sort parecia mais com variação de selection sort, portanto foi alterado
void selection_sort(int v[], int n);
void bubble_sort(int v[], int n);
void insertion_sort(int v[], int n);
void quick_sort(int v[], int inicio, int fim);

void salvar(int tamanhos[], double bubble[], double insertion[], double selection[], double quick[], int num_tamanhos);

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
    
    double tempos_bubble[5];
    double tempos_insertion[5];
    double tempos_selection[5];
    double tempos_quick[5];

    LARGE_INTEGER freq, inicio, fim;
    QueryPerformanceFrequency(&freq);

    srand(time(NULL));

    puts("Bubble Sort: O(n^2)");
    puts("Insertion Sort: O(n^2)");
    puts("Selection Sort: O(n^2)");
    puts("Quick Sort: O(n log n)");
    puts("");

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
        tempos_bubble[t] = tempo_total_bubble / REPETICOES;
        printf("Media do (Bubble): %.3f ms\n", tempos_bubble[t]);

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
        tempos_insertion[t] = tempo_total_insertion / REPETICOES;
        printf("Media do (Insertion): %.3f ms\n", tempos_insertion[t]);

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
        tempos_selection[t] = tempo_total_selection / REPETICOES;
        printf("Media do (Selection): %.3f ms\n", tempos_selection[t]);

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
        tempos_quick[t] = tempo_total_quick / REPETICOES;
        printf("Media do (Quick): %.3f ms\n", tempos_quick[t]);
        
        printf("\n");
        free(vetor);
    }
    
    salvar(tamanhos, tempos_bubble, tempos_insertion, tempos_selection, tempos_quick, num_tamanhos);
    puts(">> Fim dos testes. Confira resultados em 'resultados.csv'");
    system("pause");
    return 0;
}

void salvar(int tamanhos[], double bubble[], double insertion[], double selection[], double quick[], int num_tamanhos)
{
    FILE *arq = fopen("resultados.csv", "w");
    // w -> write
    if (arq == NULL)
    {
        printf("[ERRO]: Nao foi possivel criar o arquivo CSV!");
        return;
    }
    
    // cabecalhos
    fprintf(arq, "n;Bubble;Insertion;Selection;Quick\n");
    for (int i = 0; i < num_tamanhos; i++)
    {
        fprintf(arq, "%d;%.3f;%.3f;%.3f;%.3f\n",
                tamanhos[i],
                bubble[i],
                insertion[i],
                selection[i],
                quick[i]);
    }
    
    fclose(arq);
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
    // obs: o bubble sort parecia mais com variação de selection sort, portanto foi alterado
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
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