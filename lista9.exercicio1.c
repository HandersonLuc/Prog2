#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct local {
    char ender[81]; // endereço do local de provas
    int sala;       // número da sala
} Local;

typedef struct notas {
    float geral;      // prova de conhecimentos gerais
    float especifica; // prova de conhecimentos específicos
} Notas;

typedef struct candidato {
    int inscr;        // número de inscrição
    char nome[81];    // nome do candidato
    Data nasc;        // data de nascimento
    Local *loc;       // ponteiro para local da prova
    Notas nt;         // notas de prova
} Candidato;

void lerCandidato(Candidato *cand) {
    printf("Número de inscrição: ");
    scanf("%d", &cand->inscr);
    getchar();

    printf("Nome: ");
    fgets(cand->nome, 81, stdin);
    cand->nome[strcspn(cand->nome, "\n")] = 0;

    printf("Data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &cand->nasc.dia, &cand->nasc.mes, &cand->nasc.ano);

    cand->loc = (Local *)malloc(sizeof(Local));
    if (cand->loc == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    getchar();
    printf("Endereço do local de prova: ");
    fgets(cand->loc->ender, 81, stdin);
    cand->loc->ender[strcspn(cand->loc->ender, "\n")] = 0;

    printf("Número da sala: ");
    scanf("%d", &cand->loc->sala);

    printf("Nota geral: ");
    scanf("%f", &cand->nt.geral);
    printf("Nota específica: ");
    scanf("%f", &cand->nt.especifica);
}

void imprimirCandidato(Candidato *cand) {
    printf("\n--- Candidato %d ---\n", cand->inscr);
    printf("Nome: %s\n", cand->nome);
    printf("Nascimento: %02d/%02d/%04d\n", cand->nasc.dia, cand->nasc.mes, cand->nasc.ano);
    printf("Local de Prova: %s, Sala %d\n", cand->loc->ender, cand->loc->sala);
    printf("Nota Geral: %.2f, Nota Específica: %.2f\n", cand->nt.geral, cand->nt.especifica);
}


void alterarLocal(Candidato *vet[], int n) {
    int inscricao, i, encontrado = 0;
    printf("Informe o número de inscrição do candidato: ");
    scanf("%d", &inscricao);
    getchar(); 

    for (i = 0; i < n; i++) {
        if (vet[i]->inscr == inscricao) {
            printf("Novo endereço: ");
            fgets(vet[i]->loc->ender, 81, stdin);
            vet[i]->loc->ender[strcspn(vet[i]->loc->ender, "\n")] = 0;

            printf("Nova sala: ");
            scanf("%d", &vet[i]->loc->sala);
            printf("Dados atualizados com sucesso.\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
        printf("Candidato não encontrado.\n");
}

int main() {
    Candidato **vet = NULL;
    int n = 0, i, opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Ler dados dos candidatos\n");
        printf("2 - Imprimir dados dos candidatos\n");
        printf("3 - Alterar local de prova\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Quantos candidatos deseja cadastrar? ");
                scanf("%d", &n);
                getchar();

                vet = (Candidato **)malloc(n * sizeof(Candidato *));
                if (vet == NULL) {
                    printf("Erro de alocação!\n");
                    exit(1);
                }

                for (i = 0; i < n; i++) {
                    vet[i] = (Candidato *)malloc(sizeof(Candidato));
                    if (vet[i] == NULL) {
                        printf("Erro de alocação!\n");
                        exit(1);
                    }
                    printf("\nCadastro do candidato %d:\n", i + 1);
                    lerCandidato(vet[i]);
                }
                break;

            case 2:
                for (i = 0; i < n; i++) {
                    imprimirCandidato(vet[i]);
                }
                break;

            case 3:
                alterarLocal(vet, n);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    for (i = 0; i < n; i++) {
        free(vet[i]->loc);
        free(vet[i]);
    }
    free(vet);

    return 0;
}
