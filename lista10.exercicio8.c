#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ALUNO {
    char nome[81];
    float nota1, nota2;
} ALUNO;

#define ARQUIVO "alunos.dat"

// Função para calcular média
float media(ALUNO a) {
    return (a.nota1 + a.nota2) / 2.0;
}

// Incluir aluno no final do arquivo
void incluirAluno() {
    FILE *f = fopen(ARQUIVO, "ab");
    if (!f) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    ALUNO a;
    printf("Nome do aluno: ");
    getchar(); // Limpa buffer
    fgets(a.nome, 81, stdin);
    a.nome[strcspn(a.nome, "\n")] = '\0'; // Remove \n

    printf("Nota 1: ");
    scanf("%f", &a.nota1);
    printf("Nota 2: ");
    scanf("%f", &a.nota2);

    fwrite(&a, sizeof(ALUNO), 1, f);
    fclose(f);
    printf("Aluno incluído com sucesso.\n");
}

// Alterar aluno por índice
void alterarAluno() {
    int pos;
    printf("Digite o índice do aluno a alterar: ");
    scanf("%d", &pos);

    FILE *f = fopen(ARQUIVO, "rb+");
    if (!f) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fseek(f, pos * sizeof(ALUNO), SEEK_SET);
    ALUNO a;
    if (fread(&a, sizeof(ALUNO), 1, f) != 1) {
        printf("Aluno não encontrado.\n");
        fclose(f);
        return;
    }

    printf("Aluno atual: %s (Nota1: %.1f, Nota2: %.1f)\n", a.nome, a.nota1, a.nota2);
    printf("Novo nome: ");
    getchar(); // Limpa buffer
    fgets(a.nome, 81, stdin);
    a.nome[strcspn(a.nome, "\n")] = '\0';
    printf("Nova nota 1: ");
    scanf("%f", &a.nota1);
    printf("Nova nota 2: ");
    scanf("%f", &a.nota2);

    fseek(f, pos * sizeof(ALUNO), SEEK_SET);
    fwrite(&a, sizeof(ALUNO), 1, f);
    fclose(f);
    printf("Aluno alterado com sucesso.\n");
}

// Consultar aluno por índice
void consultarAluno() {
    int pos;
    printf("Digite o índice do aluno a consultar: ");
    scanf("%d", &pos);

    FILE *f = fopen(ARQUIVO, "rb");
    if (!f) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fseek(f, pos * sizeof(ALUNO), SEEK_SET);
    ALUNO a;
    if (fread(&a, sizeof(ALUNO), 1, f) != 1 || a.nome[0] == '\0') {
        printf("Aluno não encontrado.\n");
    } else {
        printf("Nome: %s\nNota1: %.1f\nNota2: %.1f\nMédia: %.2f\n", a.nome, a.nota1, a.nota2, media(a));
    }

    fclose(f);
}

// Excluir aluno
void excluirAluno() {
    int pos;
    printf("Digite o índice do aluno a excluir: ");
    scanf("%d", &pos);

    FILE *f = fopen(ARQUIVO, "rb+");
    if (!f) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fseek(f, pos * sizeof(ALUNO), SEEK_SET);
    ALUNO a;
    if (fread(&a, sizeof(ALUNO), 1, f) != 1) {
        printf("Aluno não encontrado.\n");
        fclose(f);
        return;
    }

    a.nome[0] = '\0'; // Marca como excluído

    fseek(f, pos * sizeof(ALUNO), SEEK_SET);
    fwrite(&a, sizeof(ALUNO), 1, f);
    fclose(f);
    printf("Aluno excluído com sucesso.\n");
}

// Mostrar alunos com média > 6.0
void mostrarAprovados() {
    FILE *f = fopen(ARQUIVO, "rb");
    if (!f) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    ALUNO a;
    int i = 0, encontrados = 0;
    printf("\nAlunos com média maior que 6.0:\n");

    while (fread(&a, sizeof(ALUNO), 1, f) == 1) {
        if (a.nome[0] != '\0' && media(a) > 6.0) {
            printf("[%d] %s - Média: %.2f\n", i, a.nome, media(a));
            encontrados++;
        }
        i++;
    }

    if (encontrados == 0) {
        printf("Nenhum aluno encontrado.\n");
    }

    fclose(f);
}

int main() {
    int opcao;
    do {
        printf("\n===== MENU ALUNOS =====\n");
        printf("1. Incluir aluno\n");
        printf("2. Alterar aluno\n");
        printf("3. Consultar aluno\n");
        printf("4. Excluir aluno\n");
        printf("5. Mostrar aprovados (média > 6.0)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: incluirAluno(); break;
            case 2: alterarAluno(); break;
            case 3: consultarAluno(); break;
            case 4: excluirAluno(); break;
            case 5: mostrarAprovados(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
