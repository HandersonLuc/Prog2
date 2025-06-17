/*Implemente um programa que leia do usuário vários nomes completos de pessoas,
até que o usuário digite a palavra “fim”. Esses nomes devem ser armazenados em um
vetor. Imprima no final a média e a variância do tamanho dos nomes.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NOMES 100
#define MAX_TAM 100

int main() {
    char nomes[MAX_NOMES][MAX_TAM];
    int qtd = 0;
    double soma = 0.0, soma_quadrados = 0.0;

    printf("Digite nomes completos (digite 'fim' para encerrar):\n");
    while (qtd < MAX_NOMES) { //enquanto houver espaço no vetor
        fgets(nomes[qtd], MAX_TAM, stdin); // Lê sa entrada
        nomes[qtd][strcspn(nomes[qtd], "\n")] = '\0'; // remove o \n

        if (strcmp(nomes[qtd], "fim") == 0) // se o nome for "fim", encerra a leitura
            break;

        int tam = strlen(nomes[qtd]); // calcula o tamanho do nome
        soma += tam;
        soma_quadrados += tam * tam;
        qtd++;
    }

    if (qtd == 0) {
        printf("Nenhum nome foi inserido.\n");
        return 0;
    }

    double media = soma / qtd;
    double variancia = (soma_quadrados / qtd) - (media * media);

    printf("Média do tamanho dos nomes: %.2lf\n", media);
    printf("Variância do tamanho dos nomes: %.2lf\n", variancia);

    return 0;
}