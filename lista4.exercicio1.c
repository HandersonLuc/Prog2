/*Escreva um programa em C para ler um vetor X de 10 elementos inteiros. Logo após copie os
elementos do vetor X para um vetor Y fazendo com que o 1o. elemento de X seja copiado para o
10o. de Y, o 2o. de X para o 9o. de Y e assim sucessivamente. Após o término da cópia, imprimir o
vetor Y.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int x[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Digite o %d elemento do vetor X: ", i + 1);
        scanf("%d", &x[i]);
    }
    int *y = (int *)malloc(10 * sizeof(int));
    if (y == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    int len = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < len; i++)
    {
        y[len - i - 1] = x[i];
    }
    printf("Vetor Y: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", y[i]);
    }
    printf("\n");
    free(y);
    return 0;
}