/*Qual é a saída deste programa supondo que i ocupa o endereço 4094 na memória?
main() {
int i=5, *p;
p = &i;
printf("%x %d %d \n", p, *p+2, 3**p);
}*/

#include <stdio.h>

int main(){
    int i=5, *p;
    p = &i;
    printf("4094 %d %d \n", *p+2, 3**p);
    printf("p armagena o endeco de i, valor que o ponteiro de i mais 2, 3 vezes o valor de i\n");
    return 0;
}