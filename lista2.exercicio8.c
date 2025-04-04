/* O número 3025 possui a seguinte característica: 30 + 25 = 55 -> 55*55 = 3025. Fazer
um programa para obter todos os números de 4 algarismos com a mesma característica do
número 3025.*/

#include <stdio.h>

int main(){
    int num, parte1, parte2, soma, quadrado;
    for (num = 1000; num <= 9999; num++) {
        parte1 = num / 100;
        parte2 = num % 100;
        soma = parte1 + parte2;
        quadrado = soma * soma;
        if (quadrado == num) {
            printf("%d\n", num);
        }
    }
    return 0;
}