/*4. Implemente uma função que receba como parâmetros um vetor de números inteiros v e seu
comprimento n, e verifique se os elementos do vetor correspondem aos termos de uma PA
(Progressão Aritmética), isto é, se existe um número inteiro k tal que v[i]=v[0]+k*i. Caso os
elementos do vetor correspondam aos termos de uma PA, a função deve retornar o valor
calculado para k. Por exemplo, se for passado para essa função o vetor {2,10,18,26,34} a função
deve retornar o valor 8. Caso o vetor não corresponda a uma PA, a função deve retornar o valor 0.
Assuma que o vetor sempre terá pelo menos 3 elementos. Essa função deve ter o seguinte
protótipo:
int testa_PA(int n, int* v)*/

#include <stdio.h>
#include <stdlib.h>

// Função que verifica se o vetor é uma PA e retorna o valor de k ou 0
int testa_PA(int n, int *v) {
    int k = v[1] - v[0]; // Calcula a diferença inicial (razão da PA)
    for (int i = 1; i < n; i++) {
        if (v[i] != v[0] + k * i) {
            return 0; // Não é uma PA
        }
    }
    return k; // Retorna a razão da PA
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Alocação dinâmica de memória para o vetor
    int *v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Leitura dos elementos do vetor
    for (int i = 0; i < n; i++) {
        printf("Digite o %d elemento do vetor: ", i + 1);
        scanf("%d", &v[i]);
    }

    // Verifica se o vetor é uma PA
    int k = testa_PA(n, v);
    if (k != 0) {
        printf("O vetor corresponde a uma PA com k = %d\n", k);
    } else {
        printf("O vetor nao corresponde a uma PA\n");
    }

    // Libera a memória alocada
    free(v);
    return 0;
}