#include <stdio.h>
#include <stdlib.h>

float *acima_da_media(int n, float *vet, int *tam);

int main()
{
    int n, tam;
    float *vet, *vet2;
    printf("Digite quantas medias tem:");
    scanf("%d",&n);
    vet=(float*)malloc(n*sizeof(float));
    if(vet==NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    for(int i=0;i<n;i++){
        printf("Digite uma media\n");
        scanf("%f",&vet[i]);
    }
    vet2=acima_da_media(n,vet,&tam);
    printf("\nAs notas acima da media sao: ");
    for(int i=0;i<tam;i++){
        printf("%.1f ",vet2[i]);
    }
    free(vet2);
    return 0;
}

float *acima_da_media(int n, float *vet, int *tam){
    float media=0;
    int maior=0, j=0;
    for(int i=0;i<n;i++){
        media+=vet[i];
    }
    media/=n;
    for(int i=0;i<n;i++){
        if(vet[i]>=media){
            maior+=1;
        }
    }
    float *vetresposta=(float*)malloc(maior*sizeof(float));
    if(vetresposta==NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    for(int i=0;i<n;i++){
        if(vet[i]>=media){
            vetresposta[j]=vet[i];
            j++;
        }
    }
    *tam=maior;
    return vetresposta;
}

