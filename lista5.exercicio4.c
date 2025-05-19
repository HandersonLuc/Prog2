/*Escreva um programa em C para ler uma palavra e escrever:
-A primeira letra da palavra.
-A última letra da palavra.
-O número de letras existente na palavra (não usar a função strlen())*/

#include <stdio.h>

int main() {
    char c, primeira, ultima;
    int cont = 0;

    printf("Digite uma palavra: ");

    while (1) {
        c = getchar();
        if (c == '\n' || c == ' ' || c == EOF) break;
        if (cont == 0) primeira = c;
        ultima = c;
        cont++;
    }

    if (cont > 0) {
        printf("Primeira letra: %c\n", primeira);
        printf("Ultima letra: %c\n", ultima);
        printf("Numero de letras: %d\n", cont);
    } else {
        printf("Nenhuma letra digitada.\n");
    }

    return 0;
}