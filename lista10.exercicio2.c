int main() {
    char nomeArquivo[] = "alunos.txt";
    char matriculaBuscada[20];

    printf("Digite a matrícula do aluno: ");
    scanf("%s", matriculaBuscada);

    float cr = busca(nomeArquivo, matriculaBuscada);

    if (cr >= 0) {
        printf("CR do aluno %s: %.2f\n", matriculaBuscada, cr);
    } else {
        printf("Matrícula %s não encontrada.\n", matriculaBuscada);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float busca(char* arquivo, char* matricula) {
    FILE* f = fopen(arquivo, "r");
    if (f == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    char mat[20];
    float cr;

    while (fscanf(f, "%s %f", mat, &cr) == 2) {
        if (strcmp(mat, matricula) == 0) {
            fclose(f);
            return cr;
        }
    }

    fclose(f);
    return -1.0; // Matrícula não encontrada
}
