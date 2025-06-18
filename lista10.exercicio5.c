#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int main()
{
    char arq[100];
    FILE *fp;
    float vet[MAX];
    int i=0;
    float n,media=0;
    printf("Digite o nome do arquivo:");
    scanf(" %s",arq);
    fp= fopen(arq,"r");
    if(fp==NULL){
        printf("ERRO");
        exit(1);
    }
    while(fscanf(fp,"%f",&n)==1&&i<MAX){
        vet[i]=n;
        media+=n;
        i++;
    }
    fclose(fp);
    if(i==0) printf("Nenhum numero foi lido!\n");
    else{
        media/=i;
        printf("A media e:%.2f",media);
    }
    return 0;
}