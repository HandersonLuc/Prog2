#include <stdio.h>

#define n 4 /*Fiz por definição pq o exercicio não falou que o numero deve ser indicado por um usuario*/

int main() {
    int cont = 0, soma = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            soma += i;
            cont++;
        }
    }
    printf("Soma dos impares: %d\n", soma);
    printf("Quantidade de impares: %d\n", cont);
    return 0;
}