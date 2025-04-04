/*Fazer um programa que sorteie um número de 0 a 100 e que permita que o usuário
(sem conhecer o número sorteado) tente acertar. Caso não acerte, o programa deve
imprimir uma mensagem informando se o número sorteado é maior ou menor que a
tentativa feita. Ao acertar o número, o programa deve imprimir a quantidade de tentativas
feitas.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int numsorteado, tentativas = 1, num; // Inicializa tentativas com 1 para contar a primeira tentativa
    numsorteado = rand() % 101; // Sorteia um número entre 0 e 100
    printf("Adivinhe o número sorteado (de 0 a 100): ");
    do{
    scanf("%d", &num);
    if (num < numsorteado) {
        printf("O número sorteado é maior. Tente novamente: ");
    } else if (num > numsorteado) {
        printf("O número sorteado é menor. Tente novamente: ");
    } else {
        printf("Parabéns! Você acertou o número: %d\n", numsorteado);
        printf("Tentativas: %d\n", tentativas);
    }
    tentativas++;
    } while (num != numsorteado);
    return 0;
}