#include <stdio.h>
#include <string.h>

int main()
{
    char frase[80]="o rato roeu a roupa do rei de roma";
    char *p;
    p = frase;
    p[2]='m';/** Troca a letra r do indice 2 pela letra m**/
    p[6]='\0'; /** Troca o espaço em branco do indice 6 pelo \0 indicando o fim da string**/
    printf("%s\n", frase);/** Impre o mato**/
    p = p + 3;/** Faz com que o ponteiro inicial que era 0 seja somado com 3,
    assim tornando o inicio da string a partir do indice 3**/
    printf("%s\n",p);/** Impreme ato**/
    printf("%d\n",strlen(frase));/**Impre o tamanto total da frase que é int64_
    por causa do \0 no fim de mato**/
}