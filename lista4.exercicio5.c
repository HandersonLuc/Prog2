#include <stdio.h>

void calcula_corrida(float dist, float *b1, float *b2);

int main()
{
    float dist, b1, b2;
    printf("Digite a distancia a ser percorrida:");
    scanf("%f",&dist);
    calcula_corrida(dist, &b1, &b2);
    return 0;
}

void calcula_corrida(float dist, float *b1, float *b2){
    int dia,hora,feriado;
    float inicial=4.95,total;
    *b1=2.5;
    *b2=3.0;
    printf("Digite 1 se hoje e feriado e 0 se nao e:");
    scanf("%d",&feriado);
    printf("Digite 0 se o dia de hoje esta entre Segunda e Sexta e 1 para Finais de Semana:");
    scanf("%d", &dia);
    printf("Digite 0 se a hora esta entre 6 da manha e 21 da noite e 1 para os outros horarios:");
    scanf("%d", &hora);
    if(feriado==1||dia==1||hora==1){
        total=inicial+(*b2*dist);
    }
    else{
        total=inicial+(*b1*dist);
    }
    printf("O Valor total da corrida e de:%.2f",total);
}