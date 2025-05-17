/*Fazer um programa para receber uma frase do usuário, caracter a caracter usando getch() e
armazenando no vetor (máx. 80 caracteres). Quando o usuário digita enter (‘\r’) a recepção é
finalizada. Mostrar cada palavra da frase em uma linha separada*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    char frase[80];
    int i = 0;
    char c;

    printf("Digite uma frase (pressione Enter para finalizar):\n");

    while (1) {
        c = getch();
        if (c == '\r') { // Verifica se o caractere é Enter
            break;
        }
        frase[i] = c;
        i++;
    }
    frase[i] = '\0'; // Adiciona o caractere nulo ao final da string

    printf("\nPalavras da frase:\n");
    char *palavra = strtok(frase, " ");
    while (palavra != NULL) {
        printf("%s\n", palavra);
        palavra = strtok(NULL, " ");
    }

    return 0;
}