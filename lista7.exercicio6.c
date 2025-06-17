/*Considere que você digitou o seu nome para o programa abaixo. O que será impresso?
Indique o que você digitou. Justifique sua resposta. (não vale ponto para apresentação)*/

#include <stdio.h>
#include <string.h>
#define MAX 50
int main (void) {
char texto[MAX +2], temp; // +2 pq o get não lê o \n e o \0
    int tam , i;
    gets(texto); // get: lê até o \n, mas não o armazena
    tam = strlen (texto);
    for (i = 0; i < tam ; i ++) {
        temp = texto[i];
        texto[i] = texto[ tam -1 - i ];
        texto[strlen(texto) -1 - i] = temp ;
    } // em cada loop é alterado 2 caracteres, o primeiro e o último, depois o segundo e o penúltimo, e assim por diante.
    // O loop inverte o texto duas vezes, então o resultado final é o mesmo que o digitado.
puts (texto);
return 0;
}