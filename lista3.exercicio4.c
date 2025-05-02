/*Fazer uma função denominada divs() que:
a. recebe como parâmetro um número inteiro n por valor e dois números inteiros max e min por
referência;
b. retorna 0 se o número num é primo e 1 caso contrário. Se o número não for primo, as variáveis
max e min devem assumir os valores do menor e do maior divisores inteiros do número,
respectivamente, desconsiderando o número 1 e o próprio número num.*/
#include <stdio.h>

int div( int n, int *max, int *min);

int main(){
    int n, max, min;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    if (div(n, &max, &min) == 0){
        printf("O numero %d e primo\n", n);
    } else {
        printf("O numero %d nao e primo\n", n);
        printf("Maior divisor: %d\n", max);
        printf("Menor divisor: %d\n", min);
    }
    return 0;
}

int div(int n, int *max, int *min){
    int i;
    *max = 0;
    *min = n;
    for (i = 2; i < n; i++){
        if (n % i == 0){
            if (i > *max){
                *max = i;
            }
            if (i < *min){
                *min = i;
            }
        }
    }
    if (*max == 0){
        return 0;
    } else {
        return 1;
    }
}