/*Implemente a função max_vet, que recebe como parâmetro um vetor de números de ponto
flutuante (vet) de tamanho n e retorna o maior número armazenado nesse vetor. Essa função deve
obedecer o protótipo: float max_vet (int n, float * vet);
Faça também a função main.*/

#include <stdio.h>
#include <stdlib.h>

float max_vet(int n, float *vet);

int main(){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    float vet[n];
    for (int i = 0; i < n; i++)
    {
        printf("Digite o elemento %d do vetor: ", i+1);
        scanf("%f", &vet[i]);
    }
    printf("O maior elemento do vetor e: %.2f\n", max_vet(n, vet));
    return 0;
}

float max_vet(int n, float *vet){
    float maior = vet[0];
    for (int i = 1; i < n; i++){
        if (vet[i] > maior){
            maior = vet[i];
        }
    }
    return maior;
}