/*Todo ano um concurso de programação premia os participantes que obtêm a maior
média ponderada em uma bateria de dois testes. Escreva uma função que recebe sete
parâmetros: o inteiro n indicando a quantidade de participantes do concurso, o ponteiro
inscr para o vetor de inteiros que contém as inscrições desses participantes, o ponteiro
t1 para o vetor de reais que contém a nota de cada participante no primeiro teste, o
inteiro p1 que indica o peso dessa nota na média ponderada, o ponteiro t2 para o vetor
de reais que contém a nota de cada participante no segundo teste, o inteiro p2 que
indica o peso dessa nota na média ponderada, e um ponteiro para a variável inteira tam.
A função deve:
● calcular a média ponderada de cada participante;
● criar um novo vetor de inteiros alocado dinamicamente com o tamanho exato
para conter apenas as inscrições dos participantes que obtiveram a maior média (pode
haver empate);
● armazenar no novo vetor as inscrições correspondentes (em qualquer ordem);
● armazenar o tamanho do novo vetor na variável tam; e
● retornar o ponteiro para o novo vetor.
Considere que para uma mesma posição do vetor (mesmo índice), a inscrição e as notas
se referem a um mesmo participante. O protótipo da função é:
int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam);*/

#include <stdio.h>
#include <stdlib.h>

int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam);

int main() {
    int inscritos[] = {101, 102, 103, 104};
    float notas1[] = {7.0, 9.0, 8.5, 9.0};
    float notas2[] = {8.0, 7.0, 9.5, 7.0};
    int p1 = 1, p2 = 2, tam;

    int *vencedores = premiados(4, inscritos, notas1, p1, notas2, p2, &tam);

    if (vencedores != NULL) {
        printf("Inscrições premiadas:\n");
        for (int i = 0; i < tam; i++) {
            printf("%d\n", vencedores[i]);
        }
        free(vencedores);
    } else {
        printf("Erro ao alocar memória.\n");
    }

    return 0;
}

int *premiados(int n, int *inscr, float *t1, int p1, float *t2, int p2, int *tam) {
    if (n <= 0 || !inscr || !t1 || !t2 || !tam) return NULL;

    float *medias = (float *)malloc(n * sizeof(float));
    if (medias == NULL) return NULL;

    float maior = -1.0;
    for (int i = 0; i < n; i++) {
        medias[i] = (t1[i] * p1 + t2[i] * p2) / (p1 + p2);
        if (medias[i] > maior) {
            maior = medias[i];
        }
    }

    // Conta quantos têm a maior média
    int qtd = 0;
    for (int i = 0; i < n; i++) {
        if (medias[i] == maior) {
            qtd++;
        }
    }

    int *vencedores = (int *)malloc(qtd * sizeof(int));
    if (vencedores == NULL) {
        free(medias);
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (medias[i] == maior) {
            vencedores[j++] = inscr[i];
        }
    }

    *tam = qtd;
    free(medias);
    return vencedores;
}
