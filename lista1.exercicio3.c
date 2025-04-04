#include <stdio.h>
#include <string.h>

int main(){
    char op[1];
    float a, b;

    printf("operacao: +, -, *, / \n");
    scanf("%s", op);

    if (strcmp(op, "+") == 0)
    {
        printf("operacao de soma: a b \n");
        scanf("%f %f", &a, &b);
        printf("%f + %f = %.2f\n", a, b, a + b);
    }
    if (strcmp(op, "-") == 0)
    {
        printf("operacao de subtracao: a b \n");
        scanf("%f %f", &a, &b);
        printf("%f - %f = %.2f\n", a, b, a - b);
    }
    if (strcmp(op, "*") == 0)
    {
        printf("operacao de multiplicacao: a b \n");
        scanf("%f %f", &a, &b);
        printf("%f * %f = %.2f\n", a, b, a * b);
    }
    if (strcmp(op, "/") == 0)
    {
        printf("operacao de divisao: a b \n");
        scanf("%f %f", &a, &b); /*testar de b é != 0*/
        if (b == 0)
        {
            printf("Divisao por zero\n");
        }
        else
        {
            printf("%f / %f = %.2f\n", a, b, a / b);
        }
    }
}