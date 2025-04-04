#include <stdio.h>

int total_de_notas(int v);

int main(){
    int valor;
    printf("Valor: ");
    scanf("%d", &valor);
    printf("o total de notas e : %d \n", total_de_notas(valor));
    return 0;
}

int total_de_notas(int valor) {
    int notas[] = {100, 50, 20, 10, 5, 2, 1}; // Valores das cédulas
    int total_notas = 0;
    for (int i = 0; i < 7; i++) {
        total_notas += valor / notas[i]; // Calcula o número de notas para cada valor
        valor %= notas[i];           // Atualiza o valor restante
    }
    return total_notas;
}