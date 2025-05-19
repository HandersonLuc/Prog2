#include <stdio.h>

int main()
{
    int numbers[5];/**Cria um vetor com 5 posições**/
    int *p;/**Cria um ponteiro p**/
    int n;/**Cria uma variavel de controle**/
    p = numbers;
    *p = 10;/**Faz com que o p[0]receba 10**/
    p++;/**Faz com que p esteja apontando para p[1]**/
    *p = 20;/**Faz com que o p[1]receba 20**/
    p = &numbers[2];/**Faz com que p esteja apontando para o endereço de p[2]**/
    *p = 30;/**Faz com que o p[2]receba 30**/
    p = numbers + 3;/**Faz com que p esteja apontando para p[3]**/
    *p = 40;/**Faz com que o p[3]receba 40**/
    p = numbers;
    *(p + 4) = 50;/**Faz com que p esteja apontando para p[4] e que p[4] receba 50**/
    for (n = 0; n < 5; n++){/**Inicia um loop com n=0 que vai ate n=4**/
        printf("%d", numbers[n]);/**Da um print no vetor numbers**/
    }
}