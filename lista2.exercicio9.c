/*Implementar a função INVERTE que recebe um número unsigned int como parâmetro
e retorna este número escrito ao contrário. Ex: 431 <-> 134.*/

#include <stdio.h>

int main(){
    unsigned int num, numInvertido = 0;
    printf("Digite um numero: \n");
    scanf("%u", &num);
    while (num > 0)
    {
        numInvertido = (numInvertido * 10) + (num % 10); // Adiciona o último dígito de num ao final de numInvertido
        num /= 10; // Remove o último dígito de num
    }
    printf("Numero invertido: %u\n", numInvertido);
    return 0;
}