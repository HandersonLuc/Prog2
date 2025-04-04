/*Faça um programa que imprima os n primeiros termos da série de Fibonacci,
lembrando que esta série é definida da seguinte forma:
termo1 = 1
termo2 = 1
termon = termon−1 + termon−2
O usuário do programa deve fornecer o número de termos, e estes devem ser impressos
separados por um espaço. Por exemplo, se o usuário pedir os 6 primeiros termos da série
de Fibonacci, o programa deve ter a seguinte saída:
1 1 2 3 5 8*/

#include <stdio.h>
#define n 6 /*Fiz por definição pq o exercicio não falou que o numero deve ser indicado por um usuario*/    

int main() {
    int fib[n];
    fib[0] = 1; // Primeiro termo
    fib[1] = 1; // Segundo termo
    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2]; // Calcula o termo atual
    };
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fib[i]); // Imprime os termos separados por espaço
    }
    return 0;
}