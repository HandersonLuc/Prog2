#include <stdio.h>

float media(float n);

int main() {
    float soma = 0, nota;
    int foi = 0, validade = 0;

    do {
        printf("Digite a nota: \n");
        scanf("%f", &nota);

        if (nota >= 0 && nota <= 10) {
            soma += nota;
            foi++;
        } else {
            printf("Nota inválida\n");
            validade = 1;
        }
    } while (nota >= 0 && nota <= 10 && foi < 3 && validade == 0);

    if (validade == 0) {
        printf("A média é: %.2f\n", media(soma));
    }

    return 0;
}

float media(float n){
    float media = n;
    media /= 3;
    return media;
}