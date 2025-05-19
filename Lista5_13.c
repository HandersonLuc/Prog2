#include <stdio.h>
#include <string.h>

#define MAX 80

void treze(char *s1, char *s2);

int main()
{
    char s1[MAX],s2[MAX];
    printf("Digite uma string:");
    scanf(" %[^\n]", s1);
    printf("Digite outra string:");
    scanf(" %[^\n]", s2);
    treze(s1,s2);
    return 0;
}

void treze(char *s1, char *s2){
    int a=strcmp(s1,s2);
    if(a>=0){
        s1[strlen(s1)]=' ';
        strcat(s1,s2);
        printf("%s\n",s1);
    }
    else{
        s2[strlen(s2)]=' ';
        strcat(s2,s1);
        printf("%s\n",s2);
    }
}