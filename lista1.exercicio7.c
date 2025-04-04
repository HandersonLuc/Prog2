#include <stdio.h>
#include <math.h>

int main(){
    float n;
    printf("Give me a number: \n");
    scanf("%f", &n);
    printf(" Arredondando para cima de %.2f e: %.0f \n", n, ceil(n));
    printf(" Arredondando para baixo de %.2f e: %.0f \n", n, floor(n));
}