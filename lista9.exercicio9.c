#include <stdio.h>

typedef struct {
    char nome[50];
    float media;
} ALUNO;

// Função de ordenação (Bubble Sort otimizado)
void ordena(ALUNO turma[], int tam) {
    int i, foraOrdem, jaOrdenados = 0;
    ALUNO temp;
    do {
        foraOrdem = 0;
        for (i = 0; i < tam - 1 - jaOrdenados; i++) {
            if (turma[i].media > turma[i+1].media) {
                temp = turma[i];
                turma[i] = turma[i+1];
                turma[i+1] = temp;
                foraOrdem = 1;
            }
        }
        jaOrdenados++;
    } while (foraOrdem);
}

// Função main
int main() {
    int tam = 5;
    ALUNO turma[5] = {
        {"Carlos", 7.5},
        {"Ana", 9.2},
        {"Bruno", 6.8},
        {"Daniela", 8.0},
        {"Eduarda", 7.0}
    };

    printf("Antes da ordenação:\n");
    for (int i = 0; i < tam; i++) {
        printf("%s - Média: %.2f\n", turma[i].nome, turma[i].media);
    }

    ordena(turma, tam);

    printf("\nDepois da ordenação:\n");
    for (int i = 0; i < tam; i++) {
        printf("%s - Média: %.2f\n", turma[i].nome, turma[i].media);
    }

    return 0;
}
