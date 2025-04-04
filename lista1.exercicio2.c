#include <stdio.h>

int main(){
    int inteiros[3], maior = -1, menor = 1000000000, media = 0; /*há um problema, os inteiros também incluem os valores negativos, mas vamos atualizar esse valor depois*/
    printf("Give me three integers: \n"); /*Estou considerando tudo positivo*/
    for (int i = 0; i < 3; i++) /*Não funciona se todos os valores forem negativos*/
    {
        scanf("%d", &inteiros[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        if (inteiros[i] > maior)
        {
            maior = inteiros[i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (inteiros[i] < menor)
        {
            menor = inteiros[i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        media += inteiros[i];
    }
    media /= 3;
    printf("O maior valor e: %d\n", maior);
    printf("O menor valor e: %d\n", menor);
    printf("A media e: %d\n", media);
    return 0;
}