/*Modifique o programa anterior da seguinte forma:
a) Passo igual ao da questão 1.
b) Ao invés de calcular e imprimir na main as repetições, crie uma
função 'repeticao' para fazer esse trabalho. A função deve seguir o
protótipo
void repeticao(int *vet, int tam);
Onde 'vet' e 'tam' foram lidos no passo a).

- Exemplo de execução: idêntico ao anterior.
- Obs.: A impressão é feita dentro da função 'repeticao'.*/

#include <stdio.h>
#include <stdlib.h>

void repeticao(int *vet, int tam);

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

    repeticao(vet, tam);

    // Libera a memória alocada
    free(vet);
    return 0;
}

void repeticao(int *vet, int tam) {
    int contagem[10] = {0};
    for (int i = 0; i < tam; i++) {
        contagem[vet[i]]++;
    }

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
        printf("Nenhum valor se repete.");
    }
    printf("\n");
}