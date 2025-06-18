#include <stdio.h>
#include <stdlib.h>

int *aloc(int n, int *v);
int *preenche(int n, int *v);
void *imprime(int n,int *v);

int main()
{
    int n, *v;
    printf("Digite o tamanho do vetor:");
    scanf("%d",&n);
    v=aloc(n,v);
    imprime(n,v);
    free(v);
    return 0;
}

int *aloc(int n, int *v){
    int *vet;
    vet=(int*)malloc(n*sizeof(int));
    if(vet==NULL){
        printf("\n\n!!Memoria Insuficiente!!\n\n");
        exit(1);
    }
    vet=preenche(n,vet);
    return vet;
}

int *preenche(int n, int *v){
    int i=0,j=1,*vet2;
    vet2=(int*)malloc(n*sizeof(int));
    if(vet2==NULL){
        printf("\n\n!!Memoria Insuficiente!!\n\n");
        exit(1);
    }
    while(i<n){
        while(j%5!=0){
            j++;
        }
        vet2[i]=j;
        i++;
        j++;
    }
    return vet2;
}

void *imprime(int n,int *v){
    for(int i=0;i<n;i++){
        printf("[%d]=%d\n",i,v[i]);
    }
}





