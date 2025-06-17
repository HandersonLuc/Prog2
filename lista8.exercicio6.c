/*Vamos supor que várias pedras do jogo de xadrez estão no tabuleiro. Para facilitar a
indicação das peças, vamos convencionar:
1 – peões 3 – torres 5 – reis 0 – ausência de peças
2 – cavalos 4 – bispos 6 – rainhas
O tabuleiro é o seguinte:

1 3 0 5 4 0 2 1
1 0 1 0 0 1 0 0
0 0 0 0 1 0 6 0
1 0 0 1 1 0 0 1
0 1 0 4 0 0 1 0
0 0 3 1 0 0 1 1
1 0 6 6 0 0 1 0
1 0 5 0 1 1 0 6

a) Construa um programa que determine a soma total de peões e bispos e a quantidade
de posições com ausência de peças;
b) Escreva outro programa que determine qual a quantidade de cada tipo de peça no
tabuleiro.*/


#include <stdio.h>

int main() {
    int tabuleiro[8][8] = {
        {1, 3, 0, 5, 0, 4, 2, 1},
        {1, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 4, 0, 3, 0, 0},
        {0, 0, 4, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 5, 0, 1, 0, 1, 6}
    };

    int peoes = 0, bispos = 0, ausencias = 0;
    int pecas[7] = {0};  // índice 0 a 6

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int valor = tabuleiro[i][j];
            if (valor == 1) peoes++;
            if (valor == 4) bispos++;
            if (valor == 0) ausencias++;
            if (valor >= 0 && valor <= 6) {
                pecas[valor]++;
            }
        }
    }

    // a)
    printf("a)\n");
    printf("Total de peões: %d\n", peoes);
    printf("Total de bispos: %d\n", bispos);
    printf("Total de posições vazias: %d\n", ausencias);

    // b)
    printf("\nb)\n");
    printf("Ausência (0): %d\n", pecas[0]);
    printf("Peões (1): %d\n", pecas[1]);
    printf("Cavalos (2): %d\n", pecas[2]);
    printf("Torres (3): %d\n", pecas[3]);
    printf("Bispos (4): %d\n", pecas[4]);
    printf("Reis (5): %d\n", pecas[5]);
    printf("Rainhas (6): %d\n", pecas[6]);

    return 0;
}
