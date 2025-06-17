/*Escreva uma função em C que receba um vetor de caracteres e faça a ordenação
desses elementos usando os métodos da Bolha e do QuickSort. Após finalizar esses
programas, utilize a função qsort do C para realizar a ordenação.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bubble Sort simples
void bubbleSort(char v[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1]) {
                char temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
}

// QuickSort simples
void quickSort(char v[], int ini, int fim) {
    if (ini < fim) {
        char pivo = v[fim];
        int i = ini - 1;
        for (int j = ini; j < fim; j++) {
            if (v[j] < pivo) {
                i++;
                char temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
        char temp = v[i + 1];
        v[i + 1] = v[fim];
        v[fim] = temp;
        int p = i + 1;
        quickSort(v, ini, p - 1);
        quickSort(v, p + 1, fim);
    }
}

// Para qsort
int compara(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    char texto[101];
    printf("Digite uma palavra: ");
    scanf("%100s", texto);
    int n = strlen(texto);
    char v1[101], v2[101], v3[101];
    strcpy(v1, texto);
    strcpy(v2, texto);
    strcpy(v3, texto);

    bubbleSort(v1, n);
    quickSort(v2, 0, n - 1);
    qsort(v3, n, sizeof(char), compara);

    printf("Bubble Sort: %s\n", v1);
    printf("Quick Sort: %s\n", v2); 
    printf("qsort: %s\n", v3);

    return 0;
}