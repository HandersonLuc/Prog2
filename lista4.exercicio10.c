/*Um cinema que possui capacidade de 20 lugares está sempre lotado. Certo dia cada
espectador respondeu a um questionário, onde constava:
- sua idade;
- sua opinião em relação ao filme, que podia ser: ótimo, bom, regular, ruim ou péssimo.
Elabore um programa que, recebendo estes dados calcule e mostre:
a. a quantidade de respostas ótimo;
b. a diferença percentual entre respostas bom e regular;
c. a média de idade das pessoas que responderam ruim;
d. a porcentagem de respostas péssimo e a maior idade que utilizou esta opção;
e. a diferença de idade entre a maior idade que respondeu ótimo e a maior idade que
respondeu ruim.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcalculaOtimo(int otimo);
void calcularDiferencaPercentual(int bom, int regular);
void calcularMediaIdadeRuim(int n, int *idade, char *opiniao, int numRuim);
void calcularPessimo(int n, int *idade, char *opiniao, int numPessimo);
void calcularDiferencaIdade(int n, int *idade, char *opiniao);



int main(){
    int idade[20];
    char opiniao[20];
    int otimo = 0, bom = 0, regular = 0, ruim = 0, pessimo = 0;
    printf("Digite a quantidade de espectadores (maximo 20): ");
    int n;
    scanf("%d", &n);
    if (n > 20) {
        printf("Numero de espectadores excede o limite de 20.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Digite a idade do espectador %d: ", i + 1);
        scanf("%d", &idade[i]);
        printf("Digite a opiniao do espectador %d (O - otimo, B - bom, R - regular, P - pessimo): ", i + 1);
        scanf(" %c", &opiniao[i]);

        switch (opiniao[i]) {
            case 'O':
            case 'o':
                otimo++;
                break;
            case 'B':
            case 'b':
                bom++;
                break;
            case 'R':
            case 'r':
                regular++;
                break;
            case 'P':
            case 'p':
                pessimo++;
                break;
        }
    }
    return 0;
}
void calcalculaOtimo(int otimo){
    printf("Quantidade de respostas otimo: %d\n", otimo);
}
void calcularDiferencaPercentual(int bom, int regular){
    if (bom + regular > 0) {
        float diferencaPercentual = fabs((float)(bom - regular) / (bom + regular)) * 100;
        printf("Diferenca percentual entre respostas bom e regular: %.2f%%\n", diferencaPercentual);
    } else {
        printf("Nao ha respostas bom ou regular para calcular a diferenca percentual.\n");
    }
}
void calcularMediaIdadeRuim(int n, int *idade, char *opiniao, int numRuim) {
    int somaIdade = 0;
    int contador = 0;

    for (int i = 0; i < n; i++) {
        if (opiniao[i] == 'R' || opiniao[i] == 'r') {
            somaIdade += idade[i];
            contador++;
        }
    }

    if (contador > 0) {
        float mediaIdade = (float)somaIdade / contador;
        printf("Media de idade das pessoas que responderam ruim: %.2f\n", mediaIdade);
    } else {
        printf("Nao ha respostas ruim para calcular a media de idade.\n");
    }
}
void calcularPessimo(int n, int *idade, char *opiniao, int numPessimo) {
    if (numPessimo > 0) {
        int maiorIdadePessimo = -1;
        for (int i = 0; i < n; i++) {
            if ((opiniao[i] == 'P' || opiniao[i] == 'p') && idade[i] > maiorIdadePessimo) {
                maiorIdadePessimo = idade[i];
            }
        }
        float porcentagemPessimo = ((float)numPessimo / n) * 100;
        printf("Porcentagem de respostas pessimo: %.2f%%\n", porcentagemPessimo);
        printf("Maior idade que utilizou a opcao pessimo: %d\n", maiorIdadePessimo);
    } else {
        printf("Nao ha respostas pessimo para calcular a porcentagem.\n");
    }
}
void calcularDiferencaIdade(int n, int *idade, char *opiniao) {
    int maiorIdadeOtimo = -1;
    int maiorIdadeRuim = -1;

    for (int i = 0; i < n; i++) {
        if (opiniao[i] == 'O' || opiniao[i] == 'o') {
            if (idade[i] > maiorIdadeOtimo) {
                maiorIdadeOtimo = idade[i];
            }
        }
        if (opiniao[i] == 'R' || opiniao[i] == 'r') {
            if (idade[i] > maiorIdadeRuim) {
                maiorIdadeRuim = idade[i];
            }
        }
    }

    if (maiorIdadeOtimo != -1 && maiorIdadeRuim != -1) {
        int diferencaIdade = abs(maiorIdadeOtimo - maiorIdadeRuim);
        printf("Diferenca de idade entre a maior idade que respondeu otimo e a maior idade que respondeu ruim: %d\n", diferencaIdade);
    } else {
        printf("Nao foi possivel calcular a diferenca de idade entre otimo e ruim.\n");
    }
}