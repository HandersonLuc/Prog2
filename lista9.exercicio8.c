/*Uma agenda é representada por um vetor de ponteiros para o tipo Compromisso, que
representa as informações sobre um compromisso diário, conforme descrito a seguir:
struct data {
int dd, mm, aa; /* Dia, mes e ano 
};
typedef struct data Data;
struct compromisso {
char descricao[81];  Descricao do compromisso 
Data dta; Data do compromisso 
};
typedef struct compromisso Compromisso;
Considere que esse vetor está em ordem cronológica, ou seja, ordem crescente de acordo com a
data de cada compromisso, e, além disso, não há mais de um compromisso com uma mesma data.
Aplicando a técnica de busca binária, implemente uma função que, dada uma data (dia, mês e
ano), se há no vetor algum compromisso com essa data, retorna o ponteiro para este
compromisso. Caso contrário, a função deve retornar NULL. A função recebe como parâmetros o
ponteiro vet, para o primeiro elemento do vetor, o inteiro n, que representa o tamanho do vetor, e
os inteiros d, m e a, representando uma data. Seu protótipo é
Compromisso* busca(int n, Compromisso** vet, int d, int m, int a);*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    int dd, mm, aa; // Dia, mês e ano
}; 
typedef struct data Data;

struct compromisso {
    char descricao[81]; // Descrição do compromisso
    Data dta; // Data do compromisso
}; 
typedef struct compromisso Compromisso;

// Função de busca binária
Compromisso* busca(int n, Compromisso** vet, int d, int m, int a) {
    int esquerda = 0;
    int direita = n - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        // Comparar as datas
        if (vet[meio]->dta.aa == a && vet[meio]->dta.mm == m && vet[meio]->dta.dd == d) {
            return vet[meio]; // Compromisso encontrado
        }
        
        // Comparar as datas para decidir a direção da busca
        if (vet[meio]->dta.aa < a || (vet[meio]->dta.aa == a && vet[meio]->dta.mm < m) || 
            (vet[meio]->dta.aa == a && vet[meio]->dta.mm == m && vet[meio]->dta.dd < d)) {
            esquerda = meio + 1; // Busca na metade direita
        } else {
            direita = meio - 1; // Busca na metade esquerda
        }
    }
    return NULL; // Compromisso não encontrado
}

int main() {
    int n = 5; // Número de compromissos
    Compromisso** vet = malloc(n * sizeof(Compromisso*));

    // Alocando e inicializando o vetor de compromissos
    for (int i = 0; i < n; i++) {
        vet[i] = malloc(sizeof(Compromisso));
        sprintf(vet[i]->descricao, "Compromisso %d", i + 1);
        vet[i]->dta.dd = 10 + i; // Dias: 10, 11, 12, 13, 14
        vet[i]->dta.mm = 5;      // Mês: Maio
        vet[i]->dta.aa = 2023;   // Ano: 2023
    }

    // Testando a busca
    int diaParaBuscar = 12;
    int mesParaBuscar = 5;
    int anoParaBuscar = 2023;
    Compromisso* resultado = busca(n, vet, diaParaBuscar, mesParaBuscar, anoParaBuscar);

    if (resultado != NULL) {
        printf("Compromisso encontrado: %s na data %02d/%02d/%04d\n", 
               resultado->descricao, resultado->dta.dd, resultado->dta.mm, resultado->dta.aa);
    } else {
        printf("Compromisso não encontrado para a data %02d/%02d/%04d.\n", 
               diaParaBuscar, mesParaBuscar, anoParaBuscar);
    }

    // Testando com uma data que não existe
    diaParaBuscar = 15; // Data que não existe
    resultado = busca(n, vet, diaParaBuscar, mesParaBuscar, anoParaBuscar);

    if (resultado != NULL) {
        printf("Compromisso encontrado: %s na data %02d/%02d/%04d\n", 
               resultado->descricao, resultado->dta.dd, resultado->dta.mm, resultado->dta.aa);
    } else {
        printf("Compromisso não encontrado para a data %02d/%02d/%04d.\n", 
               diaParaBuscar, mesParaBuscar, anoParaBuscar);
    }

    // Liberando a memória alocada
    for (int i = 0; i < n; i++) {
        free(vet[i]);
    }
    free(vet);

    return 0;
}
