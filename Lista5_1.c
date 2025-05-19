#include <stdio.h>

#define MAX 81

void vogal(char *s, int *vogais);

int main()
{
    char s[MAX];
    int vogais=0;
    printf("digite uma palavra\n");
    scanf(" %[^\n]", s);
    vogal(s, &vogais);
    printf("%d", vogais);
    return 0;
}

void vogal(char *s, int *vogais){
    for(int i=0;s[i]!='\0';i++){
        switch(s[i]){
            case 'a' : *vogais+=1; break;
            case 'e' : *vogais+=1; break;
            case 'i' : *vogais+=1; break;
            case 'o' : *vogais+=1; break;
            case 'u' : *vogais+=1; break;
        }
    }    
}