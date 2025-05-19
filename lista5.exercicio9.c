#include <stdio.h>
#include <string.h>

#define MAX 80

void concatena(char *nome, char *endereco, char *telefone);

int main()
{
    char nome[MAX], endereco[MAX], telefone[MAX];
    printf("Digite o nome\n");
    scanf(" %[^\n]", nome);
    printf("Digite o endereco\n");
    scanf(" %[^\n]", endereco);
    printf("Digite o telefone\n");
    scanf(" %[^\n]", telefone);
    concatena(nome, endereco, telefone);
    printf("%s\n",nome);
    return 0;
}

void concatena(char *nome, char *endereco, char *telefone){
    int cntrl;
    for(int i=0;nome[i]!='\0';i++){
        cntrl=i;
    }
    for(int i=0;endereco[i]!='\0';i++){
        nome[cntrl+1]=endereco[i];
        cntrl+=1;
    }
    for(int i=0;telefone[i]!='\0';i++){
        nome[cntrl+1]=telefone[i];
        cntrl+=1;
    }
}





