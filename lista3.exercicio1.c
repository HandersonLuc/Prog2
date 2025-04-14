/*Implemente a função calcula_circulo, que calcula a área e a circunferência de um círculo de raio
r. Essa função deve obedecer o protótipo:
void calc_circulo(float r, float * circunferencia, float * area);
Fórmulas:
A = π r
2 ; c = 2 π r ; π = 3.14159265
Note que essa passagem dos 2 últimos parâmetros é uma passagem por referência.*/

#include <stdio.h>
#include <stdlib.h>

void calc_circulo(float r, float * circunferencia, float * area);

int main (){
    float r, circunferencia, area;
    printf("Digite o raio do circulo: ");
    scanf("%f", &r);
    calc_circulo(r, &circunferencia, &area);
    return 0;
}

void calc_circulo(float r, float * circunferencia, float * area){
    const float pi = 3.14159265;
    *area = pi * r * r;
    *circunferencia = 2 * pi * r;
    printf("Area: %.2f\n", *area);
    printf("Circunferencia: %.2f\n", *circunferencia);
}