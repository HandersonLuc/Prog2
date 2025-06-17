/*Escreva um programa em linguagem C que faça a leitura e calcule a soma de duas
matrizes.*/

#include <stdio.h>

void ler_matriz(int linhas, int colunas, int matriz[linhas][colunas], int num)
{
    printf("Digite os elementos da matriz %d:\n", num);
    for (int j = 0; j < linhas; j++)
    {
        for (int k = 0; k < colunas; k++)
        {
            printf("Elemento [%d][%d]: ", j, k);
            scanf("%d", &matriz[j][k]);
        }
    }
}

void imprimir_matriz(int linhas, int colunas, int matriz[linhas][colunas])
{
    for (int j = 0; j < linhas; j++)
    {
        for (int k = 0; k < colunas; k++)
        {
            printf(" %2d ", matriz[j][k]);
        }
        printf("\n");
    }
}

int main()
{
    int linhas, colunas;
    printf("Digite o tamanho das matrizes (linhas e colunas): ");
    scanf("%d %d", &linhas, &colunas);

    int m1[linhas][colunas], m2[linhas][colunas], soma[linhas][colunas];

    ler_matriz(linhas, colunas, m1, 1);
    ler_matriz(linhas, colunas, m2, 2);

    for (int j = 0; j < linhas; j++)
        for (int k = 0; k < colunas; k++)
            soma[j][k] = m1[j][k] + m2[j][k];

    printf("Matriz 1:\n");
    imprimir_matriz(linhas, colunas, m1);
    printf("Matriz 2:\n");
    imprimir_matriz(linhas, colunas, m2); 
    printf("Matriz resultante da soma:\n");
    imprimir_matriz(linhas, colunas, soma);

    return 0;
}