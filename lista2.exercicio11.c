/*Faça um algoritmo para ler dois números inteiros e calcular e mostrar o valor
resultante se elevarmos a base representada pelo primeiro à potência representada pelo
segundo. Dica: busque qual a função que faz a potenciação.*/
#include <stdio.h>
#include <math.h>

int main(){
    int a, b;
    printf("Digite a base e o expoente: \n");
    scanf("%d %d", &a, &b);
    printf("Resultado: %.0f\n", pow(a, b));
    return 0;
}