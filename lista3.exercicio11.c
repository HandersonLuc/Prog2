/*Escreva um programa que realize a leitura da idade, da altura e do sexo de n pessoas. Ao final,
mostre o número de mulheres com idade entre 20 e 35 anos e o número de homens com altura
maior que 1,80m. Calcule e mostre também a variância da altura.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para calcular a variância das alturas
float varianciaAltura(float *alturas, int n) {
    float soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += alturas[i];
    }
    float media = soma / n;
    float somaQuadrados = 0.0;
    for (int i = 0; i < n; i++) {
        somaQuadrados += (alturas[i] - media) * (alturas[i] - media);
    }
    return somaQuadrados / n;
}

int main() {
    int n, i, idade, numMulheres = 0, numHomens = 0;
    float altura;
    
    printf("Digite o numero de pessoas: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Numero de pessoas deve ser maior que zero.\n");
        return 1;
    }
    
    // Alocação dinâmica de memória para armazenar as alturas
    float *alturas = (float *)malloc(n * sizeof(float));
    if (alturas == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &idade);
        printf("Digite a altura da pessoa %d: ", i + 1);
        scanf("%f", &altura);
        printf("Digite o sexo da pessoa %d (M/F): ", i + 1);
        char sexo;
        scanf(" %c", &sexo);
        
        if (sexo == 'F' || sexo == 'f') {
            if (idade >= 20 && idade <= 35) {
                numMulheres++;
            }
        } else if (sexo == 'M' || sexo == 'm') {
            if (altura > 1.80) {
                numHomens++;
            }
        }
        alturas[i] = altura;
    }
    
    // Cálculo da variância das alturas
    float variancia = varianciaAltura(alturas, n);
    
    // Exibição dos resultados
    printf("\nNumero de mulheres com idade entre 20 e 35 anos: %d\n", numMulheres);
    printf("Numero de homens com altura maior que 1,80m: %d\n", numHomens);
    printf("Variancia das alturas: %.2f\n", variancia);
    
    // Liberação da memória alocada
    free(alturas);
    
    return 0;
}