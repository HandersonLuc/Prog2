#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort
int compara(const void *a, const void *b) {
    float fa = *(float*)a;
    float fb = *(float*)b;
    if (fa < fb) return -1;
    if (fa > fb) return 1;
    return 0;
}

int main() {
    FILE *txt = fopen("numeros.txt", "r");
    if (!txt) {
        printf("Erro ao abrir 'numeros.txt'\n");
        return 1;
    }

    float *valores = NULL;
    int capacidade = 10;
    int total = 0;

    // Aloca espaço inicial
    valores = (float*)malloc(capacidade * sizeof(float));
    if (!valores) {
        printf("Erro de memória\n");
        fclose(txt);
        return 1;
    }

    // Lê os números do arquivo
    float num;
    while (fscanf(txt, "%f", &num) == 1) {
        if (total >= capacidade) {
            capacidade *= 2;
            valores = realloc(valores, capacidade * sizeof(float));
            if (!valores) {
                printf("Erro ao realocar memória\n");
                fclose(txt);
                return 1;
            }
        }
        valores[total++] = num;
    }

    fclose(txt);

    // Ordena os números
    qsort(valores, total, sizeof(float), compara);

    // Grava no arquivo binário
    FILE *bin = fopen("numeros.bin", "wb");
    if (!bin) {
        printf("Erro ao criar 'numeros.bin'\n");
        free(valores);
        return 1;
    }

    fwrite(valores, sizeof(float), total, bin);
    fclose(bin);
    free(valores);

    printf("Arquivo 'numeros.bin' criado com %d números ordenados.\n", total);
    return 0;
}
