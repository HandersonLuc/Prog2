#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

float media (char* mat, char* nome_arquivo);

int main()
{
    float med;
    char s[MAX];
    char nome_arquivo[]= "3.txt";
    printf("Digite a matricula:");
    scanf(" %[^\n]",s);
    med=media(s,"3.txt");
    if(med==-1) printf("matricula nao encontrada!");
    else printf("media do aluno %s:%2.f",s,med);
    return 0;
}

float media (char* mat, char* nome_arquivo){
    FILE *fp=fopen(nome_arquivo,"r");
    if(fp==NULL){
        printf("!!ERRO!!");
        exit(1);
    }
    char matricula[9];
    float p1,p2,p3;
    while(fscanf(fp,"%s %f %f %f",matricula,&p1,&p2,&p3)==4){
        if(strcmp(matricula,mat)==0){
            fclose(fp);
            return (p1+p2+p3)/3;
        }
    }
    fclose(fp);
    return -1;
}