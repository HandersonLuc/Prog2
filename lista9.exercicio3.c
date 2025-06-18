#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * estado[27] =
{"AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA",
"PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"};

typedef struct assalariados {
    char nome[51];
    char sexo;
    int idade;
    float salario;
    char estado[3];
} Assalariados;

Assalariados * cadastra(char *nome, char sexo, int idade, float salario, char *estado);

void relatorio(Assalariados ** ptr, int numAssalariados);

void imprime(Assalariados **ptr, int numAssalariados);

int main()
{
    Assalariados **pessoas;
    int numAssalariados=3;
    pessoas = (Assalariados **) malloc (numAssalariados*sizeof(Assalariados*));
    pessoas[0] = cadastra("Fulano de tal", 'M',45,1500.00, "RJ");
    pessoas[1] = cadastra("Ciclano", 'M',50,2500.00, "RS");
    pessoas[2] = cadastra("Beltrano", 'M',42,500.00, "RS");
    imprime(pessoas, numAssalariados);
    relatorio(pessoas,numAssalariados);
    return 0;
}

Assalariados *cadastra(char *nome, char sexo, int idade, float salario, char *estado){
    Assalariados *a=(Assalariados*)malloc(sizeof(Assalariados));
    strcpy(a->nome,nome);
    a->sexo=sexo;
    a->idade=idade;
    a->salario=salario;
    strcpy(a->estado,estado);
    return a;
}

void imprime(Assalariados **a, int numAssalariados){
    for(int i=0;i<numAssalariados;i++){
        printf("%s\n",a[i]->nome);
        printf("%c\n",a[i]->sexo);
        printf("%d\n",a[i]->idade);
        printf("%3.f\n",a[i]->salario);
        printf("%s\n",a[i]->estado);
    }
}

void relatorio(Assalariados **ptr, int numAssalariados) {
    char * estados[27] = {
        "AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT",
        "PA","PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"
    };

    for (int i = 0; i < 27; i++) {
        int count = 0;
        for (int j = 0; j < numAssalariados; j++) {
            if (strcmp(ptr[j]->estado, estados[i]) == 0 && ptr[j]->sexo == 'M' && ptr[j]->idade > 40 && ptr[j]->salario > 1000.00){ 
                count++;
            }
        }
        if (count > 0) {
            printf("Estado=%s com %d homens maiores de 40 anos e salário maior que R$ 1000,00\n", estados[i], count);
        }
    }
}
