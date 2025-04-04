#include <stdio.h>

int main(){
    int h, m, s;
    printf("numero inteiro de segundos: \n");
    scanf("%d", &s);
    h = s / 3600; /* total de horas */
    m = (s % 3600) / 60; /* pego o que sobrou do tempo de horas e divido por 60, aí tenho os minutos*/
    s = s % 60; /* Atualiza valor dos segundos*/
    printf("horas: %d, minutos: %d, segundos: %d\n", h, m, s);
    return 0;
}