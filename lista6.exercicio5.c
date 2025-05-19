#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 81

char* cifra_cesar(char* msg);

int main()
{
    char msg[MAX], *cod;
    printf("Digite a Mensagem:");
    scanf("%[^\n]",msg);
    cod=cifra_cesar(msg);
    printf("%s",cod);
    return 0;
}
char* cifra_cesar(char* msg){
    int j=0;
    char *s=(char*)malloc(MAX*sizeof(char));
    if(s==NULL){
        printf("\nMemoria Insuficiente!\n");
        exit(1);
    }
    for(int i=0;msg[i]!='\0';i++){
        if((msg[i]>='a'&&msg[i]<='w')||(msg[i]>='A'&&msg[i]<='W')){
            s[j]=msg[i]+3;
            j++;
        }
        else{
            switch(msg[i]){
                case 'x':
                    s[j]='a';
                    j++;
                    break;
                case 'y':
                    s[j]='b';
                    j++;
                    break;
                case 'z':
                    s[j]='c';
                    j++;
                    break; 
                case 'X':
                    s[j]='A';
                    j++;
                    break;
                case 'Y':
                    s[j]='B';
                    j++;
                    break; 
                case 'Z':
                    s[j]='C';
                    j++;
                    break;
                default:
                    s[j]=msg[i];
                    j++;
                    break;
            }
        }
    }
    return s;
}