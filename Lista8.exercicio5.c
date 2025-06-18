#include <stdio.h>
#include <stdlib.h>

float **allocmatrix(int m,int n);

float **somamatrix(int m,int n,float **mat1, float **mat2);

float **multiplicamtrix(int m1,int n1,int m2,int n2,float **mat1, float **mat2);

void **diagonal(int m,float **mat,float *d);

void imprimematrix(int m,int n,float **mat);

int main()
{
    float d1,d2,**mat1,**mat2,**smat, **mmat;
    int m1,n1,m2,n2;
    printf("Digite o numero de linhas e colunas da primeira matrix:");
    scanf("%d %d",&m1,&n1);
    mat1=allocmatrix(m1,n1);
    printf("Digite o numero de linhas e colunas da segunda matrix:");
    scanf("%d %d",&m2,&n2);
    mat2=allocmatrix(m2,n2);
    if(m1==m2&&n1==n2){
        smat=somamatrix(m1,n1,mat1,mat2);
    }
    else{
        printf("Não e possivel fazer a soma das matrizes!");
    }
    if(m1==n1){
        mmat=multiplicamtrix(m1,n1,m2,n2,mat1,mat2);
    }
    else{
        printf("Nao e possivel fazer a multiplicacao das matrizes!");
    }
    diagonal(m1,mat1,&d1);
    diagonal(m2,mat2,&d2);
    imprimematrix(m1,n1,mat1);
    imprimematrix(m2,n2,mat2);
    imprimematrix(m1,n1,smat);
    imprimematrix(m1,n2,mmat);
    printf("  %1.f  ",d1);
    printf("  %1.f  ",d2);
    return 0;
}

float **allocmatrix(int m,int n){
    float **mat;
    mat=(float**)malloc(m*sizeof(float*));
    if(mat==NULL){
        printf("Memoria Insuficiente!!");
        exit(1);
    }
    for(int i=0;i<m;i++){
        mat[i]=(float*)malloc(n*sizeof(float));
        if(mat[i]==NULL){
            printf("Memoria Insuficiente!!");
            exit(1);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("Matrix[%d][%d]=",i,j);
            scanf("%f",&mat[i][j]);
        }
    }
    return mat;
}

float **somamatrix(int m,int n,float **mat1, float **mat2){
    float **mat;
    mat=(float**)malloc(m*sizeof(float*));
    if(mat==NULL){
        printf("Memoria Insuficiente!!");
        exit(1);
    }
    for(int i=0;i<m;i++){
        mat[i]=(float*)malloc(n*sizeof(float));
        if(mat[i]==NULL){
            printf("Memoria Insuficiente!!");
            exit(1);
        }
    }
    for(int i=0;i<m;i++){
        int soma=0;
        for(int j=0;j<n;j++){
            mat[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    return mat;
}
float **multiplicamtrix(int m1,int n1,int m2,int n2,float **mat1, float **mat2){
    float **mat;
    mat=(float**)malloc(m1*sizeof(float*));
    if(mat==NULL){
        printf("Memoria Insuficiente!!");
        exit(1);
    }
    for(int i=0;i<m1;i++){
        mat[i]=(float*)malloc(n2*sizeof(float));
        if(mat[i]==NULL){
            printf("Memoria Insuficiente!!");
            exit(1);
        }
    }
    float aux=0;
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            mat[i][j]=0;
            for(int x=0;x<n1;x++){
                aux+=mat1[i][j]*mat2[i][j];
            }
            mat[i][j]=aux;
            aux=0;
        }
    }
    return mat;
}

void **diagonal(int m,float **mat,float *d){
    int j=0;
    for(int i=0;i<m;i++){
        *d+=mat[i][j];
        j++;
    }
}

void imprimematrix(int m,int n,float **mat){
    for(int i=0;i<m;i++){
        printf("\n");
        for(int j=0;j<n;j++){
            printf(" %1.f ",mat[i][j]);
        }
    }
    printf("\n");
}