/*Faça um programa que informe quais são os números que se repetem em
um vetor. O programa deve seguir os seguintes passos:
a) Leia um inteiro do usuário e aloque um vetor de inteiros
dinamicamente com este tamanho. Depois, preencha todo o vetor de
inteiros com valores entre 0 e 9.
b) Imprima na tela os valores que se repetem no vetor.

- Exemplo de execução do programa:
> Entradas:
tam = 9
vet = |1|5|8|4|4|5|0|8|8|
> Saída:
5, 8, 4
- Obs.: Faça tudo na main.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    if (tam <= 0) {
        printf("Tamanho inválido.\n");
        return 1;
    }

    // Aloca o vetor
    int *vet = (int *)malloc(tam * sizeof(int));
    if (vet == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Preenche o vetor com valores entre 0 e 9
    printf("Digite %d numeros entre 0 e 9:\n", tam);
    for (int i = 0; i < tam; i++) {
        do {
            printf("vet[%d] = ", i);
            scanf("%d", &vet[i]);
            if (vet[i] < 0 || vet[i] > 9) {
                printf("Valor invalido. Digite um numero entre 0 e 9.\n");
            }
        } while (vet[i] < 0 || vet[i] > 9);
    }

    // Conta as ocorrências de cada número entre 0 e 9
    int contagem[10] = {0};
    for (int i = 0; i < tam; i++) {
        contagem[vet[i]]++;
    }

    // Imprime os números que se repetem
    printf("Valores que se repetem: ");
    int encontrou = 0;
    for (int i = 0; i < 10; i++) {
        if (contagem[i] > 1) {
            if (encontrou) {
                printf(", ");
            }
            printf("%d", i);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum.");
    }
    printf("\n");

    // Libera a memória
    free(vet);
    return 0;
}