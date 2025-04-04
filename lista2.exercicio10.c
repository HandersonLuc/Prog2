/*O maior divisor comum (MDC) de dois números inteiros é o maior número inteiro
que faz uma divisão exata (com resto zero) desses dois números. Por exemplo, o MDC de
32 e 40 é 8, o MDC de 9 e 27 é 9 e o MDC de 13 e 25 é 1. Implemente uma função que
receba como parâmetros dois números inteiros x e y e calcule o MDC desses números.
Essa função deve ter o seguinte protótipo:
int mdc (int x, int y);*/

#include <stdio.h>

int mdc (int x, int y);

int main(){
    int x, y;
    printf("Digite dois numeros inteiros: \n");
    scanf("%d %d", &x, &y);
    printf("MDC: %d\n", mdc(x, y));
    return 0;
}

int mdc (int x, int y){
    while (y != 0) {
        int temp = y;
        y = x % y; 
        x = temp; 
    }
    return x; 
}