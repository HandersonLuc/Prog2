#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *compactar(char *s);

int main() {
    char str[100];
    printf("Digite uma string (maximo 100 caracteres): ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0'; // Remove o caractere de nova linha
    }

    char *resultado = compactar(str);
    if (resultado != NULL) {
        printf("String compactada: '%s'\n", resultado);
        free(resultado);
    } else {
        printf("Erro ao alocar memoria.\n");
    }

    return 0;
}

char *compactar(char *s) {
    if (s == NULL) return NULL;

    // Avança até o primeiro caractere diferente de espaço
    char *inicio = s;
    while (*inicio == ' ') {
        inicio++;
    }
    char *fim = s + strlen(s) - 1;
    while (fim > inicio && *fim == ' ') {
        fim--;
    }

    int tamanho = fim - inicio + 1; // Inclui o último caractere
    char *resultado = (char *)malloc((tamanho + 1) * sizeof(char));
    if (resultado == NULL) {
        return NULL;
    }

    strncpy(resultado, inicio, tamanho);
    resultado[tamanho] = '\0'; // Termina a string

    return resultado;
}
