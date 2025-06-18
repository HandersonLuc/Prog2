/*Um cadastro de pessoas é representado por um vetor de ponteiros para o tipo Pessoa, conforme
descrito a seguir:
Considere que esse vetor está em ordem crescente de código, e, além disso, o código é a
identificação única da pessoa. Aplicando a técnica de busca binária, implemente uma função que
verifique se um código fornecido como parâmetro existe no vetor. A função retorna o ponteiro
para esta pessoa (Pessoa *). Caso contrário, a função deve retornar NULL. A função recebe como
parâmetros o ponteiro vet, para o primeiro elemento do vetor, o inteiro n, que representa o
tamanho do vetor, e o código. Seu protótipo é:
Pessoa* busca(int n, Pessoa** vet, int codigo);
Faça também um programa para testar essa função.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct Pessoa
struct pessoa {
    int codigo;
    char nome[81];
};
typedef struct pessoa Pessoa;

// Protótipo da função
Pessoa* busca(int n, Pessoa** vet, int codigo);

// Implementação da função de busca binária
Pessoa* busca(int n, Pessoa** vet, int codigo) {
    int inicio = 0, fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vet[meio]->codigo == codigo) {
            return vet[meio]; // Pessoa encontrada
        } else if (vet[meio]->codigo < codigo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return NULL; // Pessoa não encontrada
}

// Função principal para testar
int main() {
    int n = 5; // Número de pessoas
    Pessoa* pessoas[n];

    // Criando pessoas manualmente com códigos ordenados
    for (int i = 0; i < n; i++) {
        pessoas[i] = malloc(sizeof(Pessoa));
        if (pessoas[i] == NULL) {
            printf("Erro de alocação.\n");
            return 1;
        }
        pessoas[i]->codigo = (i + 1) * 10;  // Códigos: 10, 20, 30, 40, 50
        sprintf(pessoas[i]->nome, "Pessoa %d", i + 1);
    }

    // Código a ser buscado
    int codigoBuscado;
    printf("Digite o código que deseja buscar: ");
    scanf("%d", &codigoBuscado);

    // Realiza a busca
    Pessoa* resultado = busca(n, pessoas, codigoBuscado);

    if (resultado != NULL) {
        printf("Pessoa encontrada: %s (Código: %d)\n", resultado->nome, resultado->codigo);
    } else {
        printf("Pessoa com código %d não encontrada.\n", codigoBuscado);
    }

    // Libera memória alocada
    for (int i = 0; i < n; i++) {
        free(pessoas[i]);
    }

    return 0;
}
