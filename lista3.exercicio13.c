/*Fazer um programa para:
a. declarar variáveis a, b, c, d do tipo int.
b. declarar variáveis e, f, g, h do tipo float.
c. declarar vetor v de 10 elementos do tipo char.
d. declarar variável x do tipo int.
e. criar um ponteiro apontando para o endereço de a.
f. incrementar o ponteiro, mostrando o conteúdo do endereço apontado (em forma de número).
Caso o endereço coincida com o endereço de alguma outra variável, informar o fato.*/

#include <stdio.h>

int main(){
    int a, b, c, d;
    float e, f, g, h;
    char v[10];
    int x;
    
    // Declarando um ponteiro para a variável a
    int *ponteiro = &a;

    // Incrementando o ponteiro
    ponteiro++;

    // Mostrando o conteúdo do endereço apontado
    printf("Conteudo do endereco apontado pelo ponteiro: %d\n", *ponteiro);

    // Verificando se o endereço coincide com o de outra variável
    if (ponteiro == &b || ponteiro == &c || ponteiro == &d ||
        ponteiro == &e || ponteiro == &f || ponteiro == &g || ponteiro == &h) {
        printf("O endereco coincide com o endereco da variavel b.\n");
    } else {
        printf("O endereco nao coincide com o endereco de nenhuma outra variavel.\n");
    }
    return 0;
}