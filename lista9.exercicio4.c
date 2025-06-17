#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void atribui(char **nomes, int indice, char *nome);
char * get_sobrenome(char *nome);
main() {
    int i;
    char **nomes;
    char *sobrenome;
    nomes = (char **) malloc(MAX*sizeof(char *));
    for ( i=0 ; i<MAX ; i++) {
        nomes[i] = (char *) malloc(sizeof(char)*MAXNOME);
    }
    atribui(nomes,0,"Fulano Silva"); atribui(nomes,1,"Maria do Carmo");
    atribui(nomes,2,"Beltrano Belmonte"); atribui(nomes,3,"Pedro dos Santos");
    for (i=0 ; i<MAX ; i++) {
        sobrenome = get_sobrenome(nomes[i]);
        printf("\n%s ", sobrenome);
        printf(" %d",strlen(sobrenome)>5?i:0); // 2o printf
    }
    printf("\n%c", nomes[0][3]); // 3o printf
}

void atribui(char **nomes, int indice, char *nome) {
    strcpy(nomes[indice], nome); // Copia o nome para o vetor de nomes na posição indicada
}

char * get_sobrenome(char *nome) {
    char *sobrenome = strrchr(nome, ' '); // Encontra o último espaço no nome
    return sobrenome ? sobrenome + 1 : nome; // Retorna a parte após o último espaço ou o nome completo se não houver espaço
}

/*a. Implemente a função atribui, conforme o seu protótipo (dica: somente 1 linha de
código no corpo da função).
b. Implemente a função get_sobrenome, conforme o seu protótipo, que retorna a última
palavra do nome.
c. O que será impresso no segundo printf?
d. O que será impresso no terceiro printf?*/

//resposta c: O segundo printf imprimirá o índice do nome se o sobrenome tiver mais de 5 caracteres, caso contrário imprimirá 0. No caso dos nomes fornecidos, "Silva", "do Carmo", "Belmonte" e "dos Santos" têm 5, 8, 8 e 9 caracteres respectivamente, então os valores impressos serão: 0, 1, 2 e 3.
// resposta d: O terceiro printf imprimirá o quarto caractere do primeiro nome, que é 'n' de "Fulano Silva".