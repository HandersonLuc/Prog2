#include <stdio.h>

int mdc_recursiva(int a, int b) {
    printf("\n%d e %d", a, b);  /**Imprime os valores de a e b**/
    if (a % b == 0) return b; /**Se o resto da divisão for igual a 0 quer dizer que b é o mdc e retorna ele**/
        return mdc_recursiva (b, a % b); /**Chama recursivmanete a propia funçao aonde a recebe o valor de b, b recebe o resto da divisão de a e b**/
}

int main() {
    int a=32, b=18;                 /**Inicializa a e b com os valores 32 e 18**/
    printf("\nResultado=%d",mdc_recursiva(a, b));   /**Imprime o mdc de a e b**/
}