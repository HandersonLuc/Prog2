#include <stdio.h>
#include <stdlib.h>

float **aloc(int m,int n);

void imprime(float **mat,int m,int n);

int main()
{
    float **mat;
    int m,n,x=1,y=1;
    printf("Digite as linhas e colunas da matriz:");
    scanf("%d %d",&m,&n);
    mat=aloc(m,n);
    do{
        imprime(mat,m,n);
        printf("Digite as cidades:");
        scanf("%d %d",&x,&y);
        printf("A distancia da cidade %d para a cidade %d e de:%1.f\n",x,y,mat[x-1][y-1]);
    }while(x!=0&&y!=0);
    return 0;
}

float **aloc(int m,int n){
    float **a;
    a=(float**)malloc(m*sizeof(float*));
    if(a==NULL) exit(1);
    for(int i=0;i<m;i++){
        a[i]=(float*)malloc(n*sizeof(float));
        if(a[i]==NULL) exit(1);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("Digite a distancia de %d %d",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }
    return a;
}

void imprime(float **mat,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%1.f ",mat[i][j]);
        }
        printf("|%d\n",i+1);
    }
    for(int i=0;i<m;i++){
        printf("-  ");
    }
    printf("\n");
    for(int i=0;i<m;i++){
        printf("%d  ",i+1);
    }
    printf("\n");
}