#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void gerarVetorAleatorio(int arr[], int n);
void copiarVetor(int origem[], int destino[], int n);

int main()
{
    int tamanhos[] = {2000, 4000, 8000, 12000, 16000};
    int numTamanhos = 5;
    int numRepeticoes = 10;

    srand(time(NULL));

    printf("Iniciando testes de desempenho...\n\n");
    printf("algoritmo,n,tempo_medio_ms\n");

    for (int i = 0; i < numTamanhos; i++)
    {
        int n = tamanhos[i];

        double temposBubble = 0;
        double temposInsertion = 0;
        double temposSelection = 0;
        double temposQuick = 0;

        for (int rep = 0; rep < numRepeticoes; rep++)
        {
            int *vetorOriginal = (int *)malloc(n * sizeof(int));
            int *vetorTeste = (int *)malloc(n * sizeof(int));
            LARGE_INTEGER freq, inicio, fim;
            QueryPerformanceFrequency(&freq);

            gerarVetorAleatorio(vetorOriginal, n);

            copiarVetor(vetorOriginal, vetorTeste, n);
            QueryPerformanceCounter(&inicio);
            bubbleSort(vetorTeste, n);
            QueryPerformanceCounter(&fim);
            temposBubble += (fim.QuadPart - inicio.QuadPart) * 1000.0 / freq.QuadPart;

            copiarVetor(vetorOriginal, vetorTeste, n);
            QueryPerformanceCounter(&inicio);
            insertionSort(vetorTeste, n);
            QueryPerformanceCounter(&fim);
            temposInsertion += (fim.QuadPart - inicio.QuadPart) * 1000.0 / freq.QuadPart;

            copiarVetor(vetorOriginal, vetorTeste, n);
            QueryPerformanceCounter(&inicio);
            selectionSort(vetorTeste, n);
            QueryPerformanceCounter(&fim);
            temposSelection += (fim.QuadPart - inicio.QuadPart) * 1000.0 / freq.QuadPart;

            copiarVetor(vetorOriginal, vetorTeste, n);
            QueryPerformanceCounter(&inicio);
            quickSort(vetorTeste, 0, n - 1);
            QueryPerformanceCounter(&fim);
            temposQuick += (fim.QuadPart - inicio.QuadPart) * 1000.0 / freq.QuadPart;

            free(vetorOriginal);
            free(vetorTeste);
        }

        double mediaBubble = temposBubble / numRepeticoes;
        double mediaInsertion = temposInsertion / numRepeticoes;
        double mediaSelection = temposSelection / numRepeticoes;
        double mediaQuick = temposQuick / numRepeticoes;

        printf("Bubble Sort,%d,%.3f\n", n, mediaBubble);
        printf("Insertion Sort,%d,%.3f\n", n, mediaInsertion);
        printf("Selection Sort,%d,%.3f\n", n, mediaSelection);
        printf("QuickSort,%d,%.3f\n", n, mediaQuick);
    }

    printf("\n=== Copie a saida acima e cole em um arquivo .csv ===\n");

    return 0;
}

void gerarVetorAleatorio(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }
}

void copiarVetor(int origem[], int destino[], int n)
{
    for (int i = 0; i < n; i++)
    {
        destino[i] = origem[i];
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > chave)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}