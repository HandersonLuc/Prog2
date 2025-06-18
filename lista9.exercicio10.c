/*Faça as funções que são invocadas pela função main.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Definindo o número máximo de alunos

struct aluno {
    char nome[81];
    float media;
}; 

typedef struct aluno Aluno;

// Função para ler os dados dos alunos
void le(Aluno* turma, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(turma[i].nome, sizeof(turma[i].nome), stdin);
        turma[i].nome[strcspn(turma[i].nome, "\n")] = 0; // Remove a nova linha
        printf("Digite a média do aluno %d: ", i + 1);
        scanf("%f", &turma[i].media);
        getchar(); // Limpa o buffer do stdin
    }
}

// Função para imprimir os dados dos alunos
void imprime(Aluno* turma, int n) {
    for (int i = 0; i < n; i++) {
        printf("Aluno: %s, Média: %.2f\n", turma[i].nome, turma[i].media);
    }
}

// Função para ordenar os alunos pela média (Bubble Sort)
void ordena_medias(Aluno* turma, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (turma[j].media > turma[j + 1].media) {
                // Troca os alunos
                Aluno temp = turma[j];
                turma[j] = turma[j + 1];
                turma[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    Aluno turma[MAX];
    int n;

    printf("Digite o número de alunos (max %d): ", MAX);
    scanf("%d", &n);
    getchar(); // Limpa o buffer do stdin

    le(turma, n);

    puts("Imprimindo dados lidos da turma.");
    puts("Digite qualquer coisa para continuar.");
    getchar();
    imprime(turma, n);

    ordena_medias(turma, n);
    puts("Imprimindo dados ordenados da turma.");
    puts("Digite qualquer coisa para continuar.");
    getchar();
    imprime(turma, n);

    return 0;
}
