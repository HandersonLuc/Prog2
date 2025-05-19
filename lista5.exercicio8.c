/*Faça um programa que dado 2 palavras, determine:
a. Se as palavras são iguais;
b. Verifique se a segunda palavra é uma sub string da primeira. Ex: casa e casamento.*/

#include <stdio.h>
#include <string.h>

void verificarPalavras(char palavra1[], char palavra2[]) {
    if (strcmp(palavra1, palavra2) == 0) { // Compara as duas palavras
        printf("As palavras são iguais.\n");
    } else {
        printf("As palavras são diferentes.\n");
    }

    if (strstr(palavra1, palavra2) != NULL) { // Verifica se palavra2 é substring de palavra1
        printf("A segunda palavra é uma substring da primeira.\n");
    } else {
        printf("A segunda palavra NÃO é uma substring da primeira.\n");
    }
}

int main() {
    char palavra1[100], palavra2[100];
    printf("Digite a primeira palavra: ");
    scanf("%s", palavra1);

    printf("Digite a segunda palavra: ");
    scanf("%s", palavra2);
    
    verificarPalavras(palavra1, palavra2);
    return 0;
}
