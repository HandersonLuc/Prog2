/*Escreva um programa que sorteie uma letra do alfabeto de ‘a’ a ‘z’ e o usuário é
perguntado qual é essa letra. O programa deve informar se a letra é maior ou menor e
quando o usuário a acertou.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    char letraSorteada, letraUsuario;
    letraSorteada = 'a' + (rand() % 26); // Sorteia uma letra entre 'a' e 'z' - 'a' se refere ao valor ASCII de a, demorei para achar isso kkkk
    printf("Adivinhe a letra sorteada (de 'a' a 'z'): ");
    do {
        scanf(" %c", &letraUsuario);
        
        if (letraUsuario < letraSorteada) {
            printf("A letra sorteada é maior. Tente novamente: ");
        } else if (letraUsuario > letraSorteada) {
            printf("A letra sorteada é menor. Tente novamente: ");
        } else {
            printf("Parabéns! Você acertou a letra: %c\n", letraSorteada);
        }
    } while (letraUsuario != letraSorteada); // Continua até o usuário acertar
    
    return 0;
}