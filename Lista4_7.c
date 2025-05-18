#include <stdio.h>
#include <string.h>

void CamelCase(char *s);

int main()
{
    char s[20];
    strcpy(s,"media da turma");
    CamelCase(s);
    return 0;
}

void CamelCase(char *s){
    char j=0, s2[20];
    for(int i=0;i<20;i++){
        if(i==0 && s[i]>'a' && s[i]<'z'){
            s[i]=s[i]- 32;
        }
        if(s[i-1]==' '){
            s[i]=s[i]- 32;
        }
    }
    for(int i=0;i<20;i++){
        if(s[i]!=' '){
            s2[j]=s[i];
            j++;
        }
    }
    strcpy(s,s2);
    printf("%s", s);
}
