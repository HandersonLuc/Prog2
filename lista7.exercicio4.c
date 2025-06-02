/*Escreva um programa para declarar um vetor de caracteres de tamanho 26 e imprimir o
seu conteúdo. O vetor deve ser inicializado com as letras minúsculas do alfabeto. A
inicialização do vetor e a sua impressão devem ser feitas por funções.*/

#include <stdio.h>
#include <string.h>


void imprimirVetor(char *vetor, int tamanho);

int main(){
    char letras[26];
    int i;
    for (i = 0; i < 26; i++) {
        letras[i] = 'a' + i; 
    }
    letras[26] = '\0'; // Adiciona o terminador de string
    printf("Vetor de letras minusculas: ");
    imprimirVetor(letras, 26);
    return 0;
}

void imprimirVetor(char *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%c ", vetor[i]);
    }
    printf("\n");
}