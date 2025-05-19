/*Fazer um programa para receber uma string do usuário (máx. 50 caracteres) e fazer uma
estatística dos caracteres digitados. Por exemplo, para a string "O EXERCICIO E FACIL"”, a
estatística mostrada será 'O' = 2, ' '=3, 'E' = 3, 'X' = 1, 'R' = 1, 'C' = 3, 'I' = 3, 'F' = 1, 'A' = 1, 'L' = 1*/


#define MAX 50

#include <stdio.h>

int main(){
    char str[MAX];
    int cont[256] = {0}; // Inicializa o vetor de contagem com 0
    printf("Digite uma string (maximo 50 caracteres): ");
    fgets(str, sizeof(str), stdin); // Lê a string do usuário
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\r'){
            cont[(unsigned char)str[i]]++; // Incrementa a contagem do caractere
        }
    }
    printf("Estatistica dos caracteres:\n");
    for (int i = 0; i < 256; i++) {
        if (cont[i] > 0) { // Verifica se o caractere apareceu
            printf("'%c' = %d\n", i, cont[i]); // Imprime o caractere e sua contagem
        }
    }
    return 0;
}