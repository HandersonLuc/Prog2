#include <stdio.h>

void f1 (int v) {
    v = v + 1;      /**O v da função f1 recebe +1**/
    printf (" f1 = %d\n " , v ); /**é printado f1=2**/
}

void f2 (int *v) {
    *v = *v + 1; /**Por ter sido passado por referencia o v do main recebe +1**/
    printf (" f2 = %d\n " , *v);/**é printado f2=2**/
}

int f3 (int v) {
    v = v + 1;  /**O v da função f3 recebe +1**/
    printf (" f3 = %d\n " , v ); /**é printado f3=3**/
    return v;   /**return v com o valor 3**/
}

int main (void) {
    int v = 1;      /**Inicializa v com o valor 1**/
    f1 (v);         /**v é passado como valor**/
    f2 (&v);        /**v é passado como referencia**/
    v = f3 (v);     /**v recebe o return da função f3, v é passado como valor**/
    printf (" main = %d \n" , v ); /**é printando main=3**/
    return 0;
}