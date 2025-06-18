#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario {
    char nome[81];       // nome do funcionário
    float valor_hora;    // valor da hora de trabalho
    int horas_mes;       // horas trabalhadas no mês
};
typedef struct funcionario Funcionario;

/**
 * Carrega os dados de funcionários de um arquivo e preenche o vetor vet.
 * Cada funcionário ocupa 2 linhas no arquivo:
 * Linha 1: nome
 * Linha 2: valor_hora horas_mes
 */
void carrega(int n, Funcionario** vet, char* arquivo) {
    FILE* f = fopen(arquivo, "r");
    if (f == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    char linha[100];
    int i = 0;

    while (i < n && fgets(linha, sizeof(linha), f) != NULL) {
        // Aloca memória para o funcionário
        vet[i] = (Funcionario*)malloc(sizeof(Funcionario));
        if (vet[i] == NULL) {
            printf("Erro de alocação.\n");
            exit(1);
        }

        // Remove o \n do final do nome, se existir
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(vet[i]->nome, linha);

        // Lê a linha seguinte com valor_hora e horas_mes
        if (fgets(linha, sizeof(linha), f) == NULL) {
            printf("Formato de arquivo inválido.\n");
            exit(1);
        }

        sscanf(linha, "%f %d", &vet[i]->valor_hora, &vet[i]->horas_mes);
        i++;
    }

    fclose(f);
}


int main() {
    int n = 10; // Capacidade do vetor
    Funcionario* funcionarios[10] = {NULL}; // Inicializados com NULL

    // Nome do arquivo de entrada
    char nome_arquivo[] = "funcionarios.txt";

    // Carrega dados do arquivo
    carrega(n, funcionarios, nome_arquivo);

    // Mostra dados lidos
    printf("Funcionários carregados:\n");
    for (int i = 0; i < n && funcionarios[i] != NULL; i++) {
        printf("Nome: %s\n", funcionarios[i]->nome);
        printf("Valor da hora: %.2f\n", funcionarios[i]->valor_hora);
        printf("Horas no mês: %d\n", funcionarios[i]->horas_mes);
        printf("Salário do mês: R$ %.2f\n\n",
               funcionarios[i]->valor_hora * funcionarios[i]->horas_mes);
    }

    // Liberação de memória
    for (int i = 0; i < n; i++) {
        free(funcionarios[i]);
    }

    return 0;
}
