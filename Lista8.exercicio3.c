#include <stdio.h>
#include <stdlib.h>

float **allocmatrix(int m, int n);

float **transposta(int m,int n,float **mat);

void igual(int m,int n, float **mat,float **tmat);

float **freematrix(int m,float **mat);

int main()
{
    float **mat,**tmat;
    int m,n;
    printf("Digite o numero de linhas e colunas:");
    scanf("%d %d", &m,&n);
    mat=allocmatrix(m,n);
    tmat=transposta(m,n,mat);
    igual(m,n,mat,tmat);
    freematrix(m,mat);
    freematrix(m,tmat);
    return 0;
}

float **allocmatrix(int m, int n){
    float **mat;
    mat=(float**)malloc(m*sizeof(float*));
    if(mat==NULL){
        printf("Memoria Insuficiente!");
        exit(1);
    }
    for(int i=0;i<m;i++){
        mat[i]=(float*)malloc(n*sizeof(float));
        if(mat[i]==NULL){
            printf("Memoria Insuficiente!");
            exit(1);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("Mtrix[%d][%d]=",i,j);
            scanf("%f",&mat[i][j]);
        }
    }
    return mat;
}

float **transposta(int m, int n,float **mat){
    float **tmat;
    tmat=(float**)malloc(m*sizeof(float*));
    if(tmat==NULL){
        printf("Memoria Insuficiente!");
        exit(1);
    }
    for(int i=0;i<m;i++){
        tmat[i]=(float*)malloc(n*sizeof(float));
        if(tmat[i]==NULL){
            printf("Memoria Insuficiente!");
            exit(1);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            tmat[i][j]=mat[j][i];
        }
    }
    return tmat;
}

void igual(int m,int n, float **mat,float **tmat){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=tmat[j][i]){
                printf("A matrix nao é simetrica!");
                return;
            }
        }
    }
    printf("Matrix simetrica");
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