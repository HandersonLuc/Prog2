#include <stdio.h>

#define MAX 7

void armazena(int *v);

void lista(int *v);

int pesq(int *v);

int troca(int *v);

int main()
{
    int n, v[MAX];
    armazena(v);
    lista(v);
    n=pesq(v);
    if(n==-1){
        printf("O numero nao esta presente no vetor!\n");
    }
    else{
        printf("O numero esta na posicao %d do vetor\n",n);
    }
    troca(v);
    for(int i=0;i<MAX;i++){
        printf("%d ",v[i]);
    }
    return 0;
}

void armazena(int *v){
    for(int i=0;i<MAX;i++){
        printf("Digite um numero:");
        scanf("%d",&v[i]);
    }
}

void lista(int *v){
    for(int i=0;i<MAX;i++){
        printf("%d=%d ",i,v[i]);
    }
}

int pesq(int *v){
    int n;
    printf("\nDigite um numero a ser pesquisado no vetor:");
    scanf("%d",&n);
    for(int i=0;i<MAX;i++){
        if(n==v[i]){
            return i;
        }
    }
    return -1;
}

int troca(int *v){
    int soma=0;
    for(int i=0;i<MAX;i++){
        soma+=v[i];
        v[i]=soma;
    }
}
