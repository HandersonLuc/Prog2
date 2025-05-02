/*Implemente a função maiores, que recebe como parâmetro um vetor de números inteiros (vet) de
tamanho n e um valor x. A função deve retornar quantos números maiores do que x existem nesse
vetor. Essa função deve obedecer ao protótipo:
int maiores(int n, int * vet, int x);*/


#include <stdio.h>
#include <stdlib.h>
int maiores(int n, int * vet, int x);

int main(){
    int n, x;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int vet[n];
    for (int i = 0; i < n; i++){
        printf("Digite o elemento %d do vetor: ", i+1);
        scanf("%d", &vet[i]);
    }
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Existem %d numeros maiores que %d no vetor.\n", maiores(n, vet, x), x);
    return 0;
}

int maiores(int n, int * vet, int x){
    int cont = 0;
    for (int i = 0; i < n; i++){
        if (vet[i] > x){
            cont++;
        }
    }
    return cont;
}