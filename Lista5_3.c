#include <stdio.h>
#include <string.h>

#define MAX 20

void quantidade(char *s,char c);

int main()
{
    char s[MAX], c;
    printf("Digite uma letra\n");
    scanf("%c", &c);
    printf("Digite a string\n");
    scanf(" %[^\n]", s);
    quantidade(s,c);
    return 0;
}

void quantidade(char *s,char c){
    int cntrl=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==c){
            cntrl+=1;
            }
    }
    printf("a letra %c aparece %d veze(s)\n",c,cntrl);
}
