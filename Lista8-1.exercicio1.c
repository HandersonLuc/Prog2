#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 81

void bolha(int x,char *s);


int main()
{
    char *s;
    int x;
    s=(char*)malloc(MAX*sizeof(char));
    if(s==NULL){
        printf("Memoria Insuficiente!!");
        exit(1);
    }
    printf("Digite uma string:");
    scanf(" %[^\n]",s);
    x=strlen(s);
    bolha(x,s);
    printf("Ordenação Bolha:");
    printf("%s\n",s);
    return 0;
}

void bolha(int x,char *s){
    for(int fim=x-1;fim>0;fim--){
        int troca=0;
        for(int i=0;i<fim;i++){
            if(s[i]>s[i+1]){
                int cntrl=s[i];
                s[i]=s[i+1];
                s[i+1]=cntrl;
                troca=1;
            }
        }
        if(troca==0) return;
    }
}