/*Escreva um programa em C para ler um vetor R (de 5 elementos) e um vetor S (de 10
elementos). Gere um vetor X que possua os elementos comuns a R e a S. Considere que pode
existir repetição de elementos no mesmo vetor. Nesta situação somente uma ocorrência do
elemento comum aos dois deve ser copiada para o vetor X. Após o término da cópia, escrever o
vetor X.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    float r[5], s[10], x[15];
    int tamanhoX = 0;

    // Leitura do vetor R
    for (int i = 0; i < 5; i++) {
        printf("Digite o %d elemento do vetor R: ", i + 1);
        scanf("%f", &r[i]);
    }

    // Leitura do vetor S
    for (int i = 0; i < 10; i++) {
        printf("Digite o %d elemento do vetor S: ", i + 1);
        scanf("%f", &s[i]);
    }

    // Encontrar elementos comuns entre R e S
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (r[i] == s[j]) {
                // Verificar se o elemento já está no vetor X
                int jaExiste = 0;
                for (int k = 0; k < tamanhoX; k++) {
                    if (x[k] == r[i]) {
                        jaExiste = 1;
                        break;
                    }
                }
                if (!jaExiste) {
                    x[tamanhoX++] = r[i];
                }
            }
        }
    }

    // Exibir o vetor X
    printf("Vetor X (elementos comuns a R e S): ");
    for (int i = 0; i < tamanhoX; i++) {
        printf("%.2f ", x[i]);
    }
    printf("\n");

    return 0;
}
