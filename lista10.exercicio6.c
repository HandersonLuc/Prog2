#include <stdio.h>

int main() {
    FILE *f;
    char nomeArquivo[20];

    for (int i = 1; i <= 10; i++) {
        sprintf(nomeArquivo, "teste%02d.txt", i);

        f = fopen(nomeArquivo, "w");
        if (f == NULL) {
            printf("Erro ao criar o arquivo %s\n", nomeArquivo);
            return 1;
        }

        fprintf(f, "Texto do arquivo %d\n", i);

        fclose(f);
    }

    printf("Arquivos gerados com sucesso.\n");
    return 0;
}
