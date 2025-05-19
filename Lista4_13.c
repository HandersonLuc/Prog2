#include <stdio.h>

#define MAX 20

void quantidade(char *s);

int main()
{
    char s[MAX];
    printf("Digite uma frase:");
    scanf(" %[^\n]", s);
    quantidade(s);
    return 0;
}

void quantidade(char *s){
    int cntrl=1;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]!='/'){
            for(int j=i+1;s[j]!='\0';j++){
                if(s[i]==s[j]){
                    cntrl+=1;
                    s[j]='/';
                }
            }
            printf("'%c'=%d, ",s[i],cntrl);
            cntrl=1;
        }
    }
}
