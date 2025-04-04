/*Implemente uma função que calcule as raízes de uma equação do segundo grau, do
tipo ax2 + bx + c = 0. Observação: para o cálculo da raiz quadrada de um número, utilize
a função sqrt. Consulte a documentação de como usá-la no programa.*/

#include <stdio.h>
#include <math.h>

int main (){
    double a, b, c, x1=0.0, x2=0.0, delta;
    printf("Escolha os valores para a, b, c: ax^2 + bx + c = 0 \n");
    scanf("%lf %lf %lf", &a, &b, &c);
    delta = b*b - 4*a*c;
    printf("%lf \n", delta);
    x1 = (-b + sqrt(delta))/(2*a);
    x2 = (-b - sqrt(delta))/(2*a);
    printf("As raizes sao : %.2f e %.2f", x1, x2);
    return 0;
}