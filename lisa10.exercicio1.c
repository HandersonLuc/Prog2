#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario {
    char nome[81];        // Nome do funcionário
    float valor_hora;     // Valor da hora de trabalho
    int horas_mes;        // Horas trabalhadas no mês
};
typedef struct funcionario Funcionario;

void carrega(int n, Funcionario** vet, char* arquivo) {
    FILE* f = fopen(arquivo, "r");
    if (f == NULL) {
        printf("ERRO\n");
        exit(1); // Termina o programa com erro
    }

    char linha[100];
    int i = 0;

    while (i < n && fgets(linha, sizeof(linha), f) != NULL) {
        // Remove possível '\n' do final do nome
        linha[strcspn(linha, "\n")] = '\0';

        // Aloca memória para novo funcionário
        Funcionario* func = (Funcionario*)malloc(sizeof(Funcionario));
        if (func == NULL) {
            printf("Erro de alocação\n");
            exit(1);
        }

        // Copia o nome
        strncpy(func->nome, linha, 80);
        func->nome[80] = '\0'; // Garante terminação

        // Lê a linha com valor_hora e horas_mes
        if (fgets(linha, sizeof(linha), f) == NULL) break;
        sscanf(linha, "%f %d", &func->valor_hora, &func->horas_mes);

        // Atribui ponteiro ao vetor
        vet[i] = func;
        i++;
    }

    fclose(f);
}

int main() {
    int n = 3;
    Funcionario* vet[3] = {NULL, NULL, NULL};

    carrega(n, vet, "1.txt");

    for (int i = 0; i < n; i++) {
        printf("Nome: %s\n", vet[i]->nome);
        printf("Valor/hora: %.2f\n", vet[i]->valor_hora);
        printf("Horas/mês: %d\n", vet[i]->horas_mes);
        printf("Salário: %.2f\n\n", vet[i]->valor_hora * vet[i]->horas_mes);
        free(vet[i]);
    }

    return 0;
}