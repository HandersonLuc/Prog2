#include <stdio.h>
#include <string.h>

#define MAX 20

void invertido(char *s);

int main()
{
    char s[MAX];
    printf("Digite uma string\n");
    scanf(" %[^\n]", s);
    invertido(s);
    printf("%s\n",s);
    return 0;
}

void invertido(char *s){
    int p=0, u;
    char cntrl;
    for(int i=0;s[i]!='\0';i++){
        u=i;
    }
    while(p!=u&&p<u){
        cntrl=s[p];
        s[p]=s[u];
        s[u]=cntrl;
        p++;
        u--;
    }
}

