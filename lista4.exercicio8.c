/*Inicialize um vetor de inteiros aleatoriamente e percorra o vetor usando dois ponteiros : um
começando do início do vetor e outro do final até se encontrarem no meio. Obs : O vetor deve
conter um número par de elementos.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n;
    printf("Digite o tamanho do vetor (deve ser par): ");
    scanf("%d", &n);
    if (n % 2 != 0) {
        printf("O tamanho do vetor deve ser par.\n");
        return 1;
    }
    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    // Inicializa o vetor com valores aleatórios
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100; // Valores aleatórios entre 0 e 99
    }
    // Percorre o vetor usando dois ponteiros
    int *inicio = vetor;
    int *fim = vetor + n - 1;
    printf("Vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\nPercorrendo o vetor com dois ponteiros:\n");
    while (inicio <= fim) {
        printf("Inicio: %d, Fim: %d\n", *inicio, *fim);
        inicio++;
        fim--;
    }
    printf("Os ponteiros se encontraram no meio do vetor.\n");
    printf("Inicio: %d, Fim: %d\n", *inicio, *fim);
    // Libera a memória alocada
    free(vetor);
    return 0;
}