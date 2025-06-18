#include <stdio.h>

int somaImpares(int* v, int n);

int somaImpares(int* v, int n) {
    if (n == 0) return 0; // Caso base: vetor vazio
    int atual = (v[n - 1] % 2 != 0) ? v[n - 1] : 0;
    return atual + somaImpares(v, n - 1);
}

int main() {
    int vet[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(vet) / sizeof(vet[0]);

    int soma = somaImpares(vet, n);
    printf("Soma dos ímpares: %d\n", soma);

    return 0;
}