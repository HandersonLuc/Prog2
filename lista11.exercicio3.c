#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[81];
    float nota;
    struct aluno* prox;
} Aluno;

Aluno* incluir(Aluno* lista, int matricula, const char* nome, float nota) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    novo->matricula = matricula;
    strcpy(novo->nome, nome);
    novo->nota = nota;
    novo->prox = NULL;

    if (lista == NULL)
        return novo;

    Aluno* atual = lista;
    while (atual->prox != NULL)
        atual = atual->prox;
    atual->prox = novo;
    return lista;
}

void imprimir(Aluno* lista) {
    while (lista != NULL) {
        printf("Matrícula: %d | Nome: %s | Nota: %.2f\n", lista->matricula, lista->nome, lista->nota);
        lista = lista->prox;
    }
}

void alterar(Aluno* lista, int matricula) {
    while (lista != NULL) {
        if (lista->matricula == matricula) {
            printf("Novo nome: ");
            getchar();
            fgets(lista->nome, 81, stdin);
            lista->nome[strcspn(lista->nome, "\n")] = '\0';

            printf("Nova nota: ");
            scanf("%f", &lista->nota);
            printf("Aluno atualizado com sucesso.\n");
            return;
        }
        lista = lista->prox;
    }
    printf("Aluno com matrícula %d não encontrado.\n", matricula);
}

Aluno* excluir(Aluno* lista, int matricula) {
    Aluno* ant = NULL;
    Aluno* atual = lista;

    while (atual != NULL && atual->matricula != matricula) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Aluno com matrícula %d não encontrado.\n", matricula);
        return lista;
    }

    if (ant == NULL) { // primeiro elemento
        lista = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
    printf("Aluno excluído com sucesso.\n");
    return lista;
}

Aluno* carregarArquivo(const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "r");
    if (!f) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    Aluno* lista = NULL;
    int matricula;
    char nome[81];
    float nota;

    while (fscanf(f, "%d %s %f", &matricula, nome, &nota) == 3) {
        lista = incluir(lista, matricula, nome, nota);
    }

    fclose(f);
    return lista;
}


int main() {
    Aluno* lista = carregarArquivo("alunos.txt");
    int opcao, matricula;
    char nome[81];
    float nota;

    do {
        printf("\nMenu:\n");
        printf("1 - Incluir aluno\n");
        printf("2 - Excluir aluno\n");
        printf("3 - Alterar aluno\n");
        printf("4 - Imprimir lista\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Matrícula: ");
                scanf("%d", &matricula);
                printf("Nome: ");
                getchar();
                fgets(nome, 81, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("Nota: ");
                scanf("%f", &nota);
                lista = incluir(lista, matricula, nome, nota);
                break;
            case 2:
                printf("Matrícula a excluir: ");
                scanf("%d", &matricula);
                lista = excluir(lista, matricula);
                break;
            case 3:
                printf("Matrícula a alterar: ");
                scanf("%d", &matricula);
                alterar(lista, matricula);
                break;
            case 4:
                imprimir(lista);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 0);

    // Libera memória
    Aluno* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}

