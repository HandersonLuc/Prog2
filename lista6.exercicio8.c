/*Modifique novamente o seu programa da seguinte forma:
a) Passo igual aos das questões 1 e 2.
b) A sua função repeticao não mais imprimirá o resultado, mas sim a
main. Para isso, será necessário que a sua função 'repeticao' siga o
seguinte protótipo:
int *repeticao(int *vet, int tam, int *n);
A sua função 'repeticao' agora alocará um novo vetor de inteiros
dinamicamente que deverá ser preenchido com os valores que se repetem.
O tamanho desse vetor deve ser gravado na variável n, que referencia
uma variável na main (crie uma variável na main para isso). A função
'repeticao' retornará para a main este novo vetor resposta.
c) Imprima na main o vetor retornado pela função 'repeticao'.

- Exemplo de execução do programa:
> Entradas:
tam = 9
vet = |1|5|8|4|4|5|0|8|8|
> Valores contidos nas variáveis após a execução da função 'repeticao'
(não devem ser exibidos):
n = 3
resposta = |5|8|4|
> Saída:
5, 8, 4*/

#include <stdio.h>
#include <stdlib.h>

int *repeticao(int *vet, int tam, int *n);

int main() {
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    if (tam <= 0) {
        printf("Tamanho inválido.\n");
        return 1;
    }

    // Aloca o vetor
    int *vet = (int *)malloc(tam * sizeof(int));
    if (vet == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Preenche o vetor com valores entre 0 e 9
    printf("Digite %d numeros entre 0 e 9:\n", tam);
    for (int i = 0; i < tam; i++) {
        do {
            printf("vet[%d] = ", i);
            scanf("%d", &vet[i]);
            if (vet[i] < 0 || vet[i] > 9) {
                printf("Valor invalido. Digite um numero entre 0 e 9.\n");
            }
        } while (vet[i] < 0 || vet[i] > 9);
    }

    int n;
    int *resposta = repeticao(vet, tam, &n);

    // Imprime os números que se repetem
    printf("Valores que se repetem: ");
    if (n == 0) {
        printf("Nenhum valor se repete.");
    } else {
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(", ");
            printf("%d", resposta[i]);
        }
    }
    printf("\n");

    // Libera a memória alocada
    free(vet);
    free(resposta);

    return 0;
}

int *repeticao(int *vet, int tam, int *n) {
    int contagem[10] = {0};
    for (int i = 0; i < tam; i++) {
        contagem[vet[i]]++;
    }

    // Conta quantos números se repetem
    int qtd = 0;
    for (int i = 0; i < 10; i++) {
        if (contagem[i] > 1) {
            qtd++;
        }
    }

    // Aloca o vetor resposta
    int *resposta = NULL;
    if (qtd > 0) {
        resposta = (int *)malloc(qtd * sizeof(int));
        if (resposta == NULL) {
            *n = 0;
            return NULL;
        }

        // Preenche o vetor resposta com os números que se repetem
        int j = 0;
        for (int i = 0; i < 10; i++) {
            if (contagem[i] > 1) {
                resposta[j++] = i;
            }
        }
    }
    *n = qtd; // Atualiza o tamanho do vetor resposta
    return resposta;
}