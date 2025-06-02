
#include <stdio.h>
#include <string.h>

int main () {
    char *frase = "Otimo teste";
    char *p , misterio[80];
    int i = 0;
    int j = 0;
    p = frase + strlen ( frase ) - 1; // aponta para o ultimo caracter da string
    while (*p != ' ') { // percorre a string de tras para frente
        misterio[i] = *p;
        i ++; p --;
    }
    misterio[i] = ' '; i ++; // adiciona o espaco
    while ( frase[j] != ' ') {
        misterio [i] = frase[j]; // adiciona os caracteres da string original
        j ++; i ++;
        }
    misterio[i] = '\0'; // adiciona o terminador de string
    puts (misterio); // imprime a string resultante
    return 0;
}