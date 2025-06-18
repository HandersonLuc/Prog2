#include <stdio.h>
#include <stdlib.h>

#define MAX 80

char *nospace(char *s);
char *cryptic(char *s);

int main()
{
    char *s;
    s=(char*)malloc(MAX*sizeof(char));
    if(s==NULL){
        printf("\n\n!!Memoria Insuficiente!!\n\n");
        exit(1);
    }
    printf("Digite uma frase\n->");
    scanf(" %[^\n]",s);
    s=nospace(s);
    s=cryptic(s);
    printf("%s",s);
    free(s);
    return 0;
}

char *nospace(char *s){
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==' '){
            for(int j=i;s[j]!='\0';j++){
                s[j]=s[j+1];
            }
        }
    }
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='a'&&s[i]<='w'){
            s[i]-=32;
        }
    }
    return s;
}

char *cryptic(char *s){
    int cntrl=1;
    for(int i=0;s[i]!='\0';i++){
        if(cntrl==6){
            cntrl=1;
        }
        s[i]+=cntrl;
        cntrl+=1;
    }
    return s;
}



