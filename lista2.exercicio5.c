/*Escreva um programa em C para ler um valor X e um valor Z (se Z for menor que X
deve ser lido um novo valor para Z). Contar quantos números inteiros devemos somar em
sequência (a partir do X inclusive) para que a soma ultrapasse a Z o mínimo possível.
Escrever o valor final da contagem.
Exemplo:
X Z Resposta
3 20 5 (3+4+5+6+7=25)
2 10 4 (2+3+4+5=14)
30 40 2 (30+31=61)*/

#include <stdio.h>

int main(){
    int x, z, cont = 1, soma = 0, aux; /*Tenho que começa o cont em 1 pq eu perco um no while*/
    printf("Digite o valor de X e Z: \n");
    scanf("%d %d", &x, &z);
    if (z < x)
    {
        aux = x;
        x = z;
        z = aux;
    };
    soma = x;
    while (soma < z)
    {
        cont++;
        x++;
        soma += x;
    }
    printf("Soma: %d \n", soma);
    printf("Resposta: %d \n", cont);
    return 0;
}
