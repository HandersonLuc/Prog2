#include <stdio.h>
#include <string.h>

#define MAX 80

void d(char *nome, char *abreviado);

int main()
{
    char nome[MAX], abreviado[MAX];
    printf("Digite o nome\n");
    scanf(" %[^\n]", nome);
    d(nome, abreviado);
    printf("%s", abreviado);
    return 0;
}

void d(char *nome, char *abreviado){
    int j=0;
    if(nome[0]>'A'&&nome[0]<'Z'){
        abreviado[j]=nome[0];
        j++;
        abreviado[j]='.';
    }
    for(int i=1;nome[i]!='\0';i++){
        if(nome[i-1]==' '){
            if(nome[i]>'A'&&nome[i]<'Z'){
                j++;
                abreviado[j]=nome[i];
                j++;
                abreviado[j]='.';
            }
        }
    }
}



