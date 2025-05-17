/*Um cinema que possui capacidade de 100 lugares está quase sempre lotado. Certo dia cada
espectador respondeu a um questionário, onde constava:
- sua idade;
- sua opinião em relação ao filme, que podia ser: ótimo, bom, regular, ruim ou péssimo.
Elabore um programa que, recebendo estes dados calcule em funções e mostre:
a. a quantidade de respostas ótimo;
b. a diferença percentual entre respostas bom e regular;
c. a média de idade das pessoas que responderam ruim;
d. a porcentagem de respostas péssimo e a maior idade que utilizou esta opção;
e. a diferença de idade entre a maior idade que respondeu ótimo e a maior idade que respondeu
ruim.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcularOtimo(int numOtimo) {
    printf("Quantidade de respostas otimo: %d\n", numOtimo);
}

void calcularDiferencaPercentual(int numBom, int numRegular) {
    if (numBom + numRegular > 0) {
        float diferencaPercentual = fabs((float)(numBom - numRegular) / (numBom + numRegular)) * 100;
        printf("Diferenca percentual entre respostas bom e regular: %.2f%%\n", diferencaPercentual);
    } else {
        printf("Nao ha respostas bom ou regular para calcular a diferenca percentual.\n");
    }
}

void calcularMediaIdadeRuim(int n, int *idade, char *opiniao, int numRuim) {
    if (numRuim > 0) {
        float somaIdadeRuim = 0;
        for (int i = 0; i < n; i++) {
            if (opiniao[i] == 'R' || opiniao[i] == 'r') {
                somaIdadeRuim += idade[i];
            }
        }
        float mediaIdadeRuim = somaIdadeRuim / numRuim;
        printf("Media de idade das pessoas que responderam ruim: %.2f\n", mediaIdadeRuim);
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

int main() {
    int idade[100];
    char opiniao[100];
    int numOtimo = 0, numBom = 0, numRegular = 0, numRuim = 0, numPessimo = 0;

    printf("Digite a quantidade de espectadores (maximo 100): ");
    int n;
    scanf("%d", &n);

    if (n > 100) {
        printf("Numero de espectadores excede o limite de 100.\n");
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
                numOtimo++;
                break;
            case 'B':
            case 'b':
                numBom++;
                break;
            case 'R':
            case 'r':
                numRegular++;
                break;
            case 'P':
            case 'p':
                numPessimo++;
                break;
            case 'U': // Corrigido para aceitar "ruim"
            case 'u':
                numRuim++;
                break;
        }
    }

    calcularOtimo(numOtimo);
    calcularDiferencaPercentual(numBom, numRegular);
    calcularMediaIdadeRuim(n, idade, opiniao, numRuim);
    calcularPessimo(n, idade, opiniao, numPessimo);
    calcularDiferencaIdade(n, idade, opiniao);

    return 0;
}