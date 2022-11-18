// Optimized implementation of Bubble sort
#include <stdio.h>
#include <stdbool.h>

void swap(int *xp, int *yp)
{
    // Variaveis do código swap
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Otimização do código do bubble Sort
void bubbleSort(int arr[], int n)
{
    // Variáveis do código do bubble
    int i, j;
    bool swaps;
    for (i = 0; i < n - 1; i++)
    {
        swaps = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swaps = true;
            }
        }

        // Se não tiver dados trocados, parar o programa de vez
        if (swaps == false)
            break;
    }
}

// Função para printar um array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

// E por ultimo a Main function
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}