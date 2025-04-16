/*Seja o seguinte trecho de programa:
int i=3,j=5;
int *p, *q;
p = &i;
q = &j;
Qual é o valor das seguintes expressões ?
a) p == &i; b) *p - *q c) **&p d) 3* - *p/(*q)+7*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Na a o valor expresso True, pois p armagena o enderco de i, logo p == &i\n");
    printf("Na b o valor expresso -2, pois *p = 3 e *q = 5, logo 3 - 5 = -2\n");
    printf("Na c o valor expresso 3, pois **&p = *p = 3\n");
    printf("Na d o valor expresso 3, pois 3 * -3 / (5) + 7 = 6, pois 3 veze -3 e igual a -9 que divide por 5 entrega -1, samado com 7 e 6.\n");
}