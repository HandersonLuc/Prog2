#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHA_MAX 1024

int contemComentarioLinha(char* linha) {
    // Ignora espaços iniciais e verifica se começa com //
    while (*linha == ' ' || *linha == '\t') {
        linha++;
    }
    return (strncmp(linha, "//", 2) == 0);
}

int main() {
    char nomeEntrada[100], nomeSaida[] = "saida.c";
    char linha[LINHA_MAX];

    printf("Digite o nome do arquivo .c de entrada: ");
    scanf("%s", nomeEntrada);

    FILE* entrada = fopen(nomeEntrada, "r");
    if (entrada == NULL) {
        printf("ERRO: não foi possível abrir o arquivo '%s'.\n", nomeEntrada);
        return 1;
    }

    FILE* saida = fopen(nomeSaida, "w");
    if (saida == NULL) {
        printf("ERRO: não foi possível criar o arquivo de saída.\n");
        fclose(entrada);
        return 1;
    }

    while (fgets(linha, LINHA_MAX, entrada) != NULL) {
        if (!contemComentarioLinha(linha)) {
            fputs(linha, saida);
        }
    }

    printf("Arquivo '%s' gerado com sucesso (linhas com // removidas).\n", nomeSaida);

    fclose(entrada);
    fclose(saida);
    return 0;
}
