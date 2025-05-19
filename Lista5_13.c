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
        s1[strlen(s1)]= '2';
        strcat(s1,s2);
        s1=strtok(s1," ,.-");
        while(s1!=NULL){
            printf("%s\n",s1);
            s1=strtok(NULL," ,.-");
        }
}
