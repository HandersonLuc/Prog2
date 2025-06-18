#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 81

static int comp_reais(const void *p1, const void *p2){
    float *f1=(float*)p1;
    float *f2=(float*)p2;
    if(*f1<*f2) return -1;
    else if(*f1>*f2) return 1;
    else return 0;
}

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
    qsort(s,x,sizeof(char),comp_reais);
    printf("Ordenação Quick2:");
    printf("%s\n",s);
    return 0;
}




