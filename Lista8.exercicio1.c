#include <stdio.h>
#include <stdlib.h>

float **allocMatrix(int m, int n);

int somamatrix(int m,int n, float **mat);

float **freematrix(int m,float **mat);

int main()
{
    float **mat;
    int m,n,igual;
    printf("Digite o numero de linhas e colunas:");
    scanf("%d %d",&m,&n);
    mat=allocMatrix(m,n);
    igual=somamatrix(m,n,mat);
    mat=freematrix(m,mat);
    if(igual==1){
        printf("A soma de todas as linhas é igual");
    }
    else{
        printf("A soma de todas as linhas é diferente");
    }
    return 0;
}

float **allocMatrix(int m, int n)
{
    float **a;
    a = (float **) malloc(m*sizeof(float *));
    if (a==NULL) exit(1);
    for (int i=0;i<m;i++){
        a[i]=(float*) malloc(n*sizeof(float));
        if (a[i]==NULL) exit(1);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("Matrix[%d][%d]=",i,j);
            scanf("%f",&a[i][j]);
        }
    }
    return a;
}

int somamatrix(int m,int n, float **mat){
    int soma=0,x;
    for(int j=0;j<n;j++){
        soma+=mat[0][j];
    }
    x=soma;
    for(int i=0;i<m;i++){
        soma=0;
        for(int j=0;j<n;j++){
            soma+=mat[i][j];
        }
        if(soma!=x){
            return 0;
        }
    }
    return 1;
}

float **freematrix(int m,float **mat){
    if(mat!=NULL){
        for(int i=0;i<m;i++){
            if(mat[i]!=NULL){
                free(mat[i]);
            }
        }
    }
    free(mat);
    return NULL;
}



