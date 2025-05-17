/*Implemente um programa que chame a função média com o seguinte protótipo:
float media(int n, float *v)*/

#include <stdio.h>
#include <stdlib.h>

float media(int n, float *v);

int main(){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    float *v = (float *)malloc(n * sizeof(float));
    if (v == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &v[i]);
    }
    printf("A media dos elementos do vetor e: %.2f\n", media(n, v));
    free(v);
    return 0;
}
float media(int n, float *v) {
    float soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma / n;
}