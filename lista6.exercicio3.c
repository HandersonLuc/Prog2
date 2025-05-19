#include <stdio.h>
#include <stdlib.h>

int *aprovados(int n, int *mat, float *notas, int *tam);



int main()
{
    int n, tam, *mat, *ap;
    float *notas;
    printf("Digite quantos alunos tem na turma:");
    scanf("%d",&n);
    mat=(int*)malloc(n*sizeof(int));
    if(mat==NULL){
        printf("\nMemoria insuficiente.\n");
        exit(1);
    }
    for(int i=0;i<n;i++){
        printf("Digite uma matricula\n");
        scanf("%d",&mat[i]);
    }
    notas=(float*)malloc(n*sizeof(float));
    if(notas==NULL){
        printf("\nMemoria insuficiente.\n");
        exit(1);
    }
    for(int i=0;i<n;i++){
        printf("Digite uma media\n");
        scanf("%f",&notas[i]);
    }
    ap=aprovados(n,mat,notas,&tam);
    for(int i=0;i<tam;i++){
        printf("\nMatricula do Aluno aprovado:%d",ap[i]);
    }
    free(ap);
    return 0;
}

int *aprovados(int n, int *mat, float *notas, int *tam){
    int j=0, qtd=0;
    for(int i=0;i<n;i++){
        if(notas[i]>=5.0){
            qtd+=1;
        }
    }
    int *vet=(int*)malloc(qtd*sizeof(int));
    if(vet==NULL){
        printf("\nMemoria Insuficiente!\n");
        exit(1);
    }
    for(int i=0;i<n;i++){
        if(notas[i]>=5.0){
            vet[j]=mat[i];
            j++;
        }
    }
    *tam=qtd;
    return vet;
}




