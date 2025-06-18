#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    int mat; /* Matricula do aluno */
    char nome[81]; /* Nome do aluno */
};

typedef struct aluno Aluno;

struct prova {
    Aluno a; /* Aluno que fez a prova */
    float q1, q2, q3, q4; /* Nota em cada questao */
};

typedef struct prova Prova;

void aloca(Prova **p,int n);

void ordena(int n, Prova**v);

int compara(Prova *aluno1,Prova *aluno2);

void troca(Prova **aluno1,Prova **aluno2);

int main()
{
    Prova *v=NULL;
    int n;
    printf("Digite quantidade de alunos:");
    scanf("%d",&n);
    aloca(&v,n);
    ordena(n,&v);
    return 0;
}

void aloca(Prova **p,int n){
    *p=(Prova*)malloc(n*sizeof(Prova));
    if(*p==NULL) exit(1);
    for(int i=0;i<n;i++){
        printf("---Aluno %d---\n",i+1);
        
        printf("Digite Matricula:");
        scanf("%d",&((*p)[i].a.mat));
        
        printf("Digite Nome:");
        scanf(" %[^\n]",((*p)[i].a.nome));
        
        printf("Digite Notas:");
        scanf("%f %f %f %f",&((*p)[i].q1),&((*p)[i].q2),&((*p)[i].q3),&((*p)[i].q4));
    }
}

int compara(Prova *aluno1,Prova *aluno2){
    float m1=aluno1->q1 + aluno1->q2 + aluno1->q3 + aluno1->q4;
    float m2=aluno2->q1 + aluno2->q2 + aluno2->q3 + aluno2->q4;
    if(aluno1<aluno2){
        return 1;
    }
    else if(aluno2<aluno1){
        return 0;
    }
    else{
        if(strcmp(aluno1->a.nome,aluno2->a.nome)>0){
            return 1;
        }
        else{
            return 0;
        }
    }
}

void troca(Prova **aluno1,Prova **aluno2){
    Prova *temp= *aluno1;
    *aluno1=*aluno2;
    *aluno2=temp;
}

void ordena(int n, Prova**v)
{
    int fim,i;
    for(fim=n-1; fim>0; fim--)
        for(i=0; i<fim; i++)
            if(compara(v[i],v[i+1]))
                troca(&v[i],&v[i+1]);
}