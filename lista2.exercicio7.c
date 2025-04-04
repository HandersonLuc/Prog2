/*Escreva um programa que calcule o salário semanal de um trabalhador. As entradas
são o número de horas trabalhadas na semana e o valor da hora. Até 40 h/semana não se
acrescenta nenhum adicional. Acima de 40h e até 60h há um bônus de 50% para essas
horas. Acima de 60h há um bônus de 100% para essas horas.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int horasTrabalhadas, horasExtras = 0, horasExtras2 = 0;
    float valorHora, salarioSemanal, salarioExtra, salarioExtra2;
    printf("Digite o numero de horas trabalhadas na semana e o valor da hora: \n");
    scanf("%d %f", &horasTrabalhadas, &valorHora);
    if (horasTrabalhadas <= 40)
    {
      salarioSemanal = horasTrabalhadas * valorHora;  
    } else if (horasTrabalhadas <= 60)
    {
        horasExtras = horasTrabalhadas - 40;
        salarioExtra = (horasExtras * valorHora) * 1.5;
        salarioSemanal = (40 * valorHora) + salarioExtra;
    } else
    {
        horasExtras = 20;
        horasExtras2 = horasTrabalhadas - 60;
        salarioExtra = (horasExtras * valorHora) * 1.5;
        salarioExtra2 = (horasExtras2 * valorHora) * 2;
        salarioSemanal = (40 * valorHora) + salarioExtra + salarioExtra2;
    }
    printf("Salario semanal: %.2f\n", salarioSemanal);
    return 0;
}