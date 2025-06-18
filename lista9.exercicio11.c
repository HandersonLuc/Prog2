#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PROVAS 5

// Definições de tipos
typedef struct Aluno {
    int matricula;
    float *vNotas; 
    char nome[100];
} Aluno;

typedef struct Materia {
    Aluno *V;           
    float media[NUM_PROVAS]; 
    int nAlunos;         
} Materia;

Aluno* fillAluno() {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if (!novo) {
        printf("Erro ao alocar memória para aluno.\n");
        exit(1);
    }

    novo->vNotas = (float*)malloc(NUM_PROVAS * sizeof(float));
    if (!novo->vNotas) {
        printf("Erro ao alocar memória para notas.\n");
        exit(1);
    }

    printf("Digite o nome do aluno: ");
    fgets(novo->nome, 100, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0'; 

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &novo->matricula);

    printf("Digite as %d notas:\n", NUM_PROVAS);
    for (int i = 0; i < NUM_PROVAS; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &novo->vNotas[i]);
    }

    getchar(); 
    return novo;
}

// (B)
Materia* fillMateria(int numAlunos) {
    Materia* m = (Materia*)malloc(sizeof(Materia));
    if (!m) {
        printf("Erro ao alocar memória para matéria.\n");
        exit(1);
    }

    m->V = (Aluno*)malloc(numAlunos * sizeof(Aluno));
    if (!m->V) {
        printf("Erro ao alocar vetor de alunos.\n");
        exit(1);
    }

    m->nAlunos = numAlunos;

    for (int i = 0; i < numAlunos; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        Aluno* a = fillAluno();
        m->V[i] = *a;
        free(a); 
    }

    return m;
}

// (C) 
void mediaMateria(Materia *m1) {
    for (int i = 0; i < NUM_PROVAS; i++) {
        float soma = 0.0;
        for (int j = 0; j < m1->nAlunos; j++) {
            soma += m1->V[j].vNotas[i];
        }
        m1->media[i] = soma / m1->nAlunos;
    }
}

// (D) 
void mostraMateria(Materia *m1) {
    printf("\n==== Alunos Matriculados ====\n");
    for (int i = 0; i < m1->nAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", m1->V[i].nome);
        printf("Matrícula: %d\n", m1->V[i].matricula);
        printf("Notas: ");
        for (int j = 0; j < NUM_PROVAS; j++) {
            printf("%.2f ", m1->V[i].vNotas[j]);
        }
        printf("\n");
    }

    printf("\n==== Médias das Provas ====\n");
    for (int i = 0; i < NUM_PROVAS; i++) {
        printf("Média da Prova %d: %.2f\n", i + 1, m1->media[i]);
    }
}

void liberaMateria(Materia* m1) {
    for (int i = 0; i < m1->nAlunos; i++) {
        free(m1->V[i].vNotas);
    }
    free(m1->V);
    free(m1);
}

// (E)
int main() {
    int numAlunos;

    printf("Digite o número de alunos na matéria: ");
    scanf("%d", &numAlunos);
    getchar(); 

    Materia* minhaMateria = fillMateria(numAlunos);
    mediaMateria(minhaMateria);
    mostraMateria(minhaMateria);
    liberaMateria(minhaMateria);

    return 0;
}
