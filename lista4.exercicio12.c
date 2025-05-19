/*Faça um programa que receba uma string do usuário (máx. 20 caracteres) e um caracter
qualquer. O programa deve remover todas as ocorrências do caracter da string e mostrar o
resultado.*/

#include <stdio.h>

int main(){
    char str[9], c;
    printf("Digite uma string (maximo 20 caracteres): ");
    scanf(" %[^\n]", str);
    printf("Digite um caracter para remover: ");
    scanf(" %c", &c);
    char *p = str;  
    char *q = str;
    while (*p) {
        if (*p != c) {
            *q++ = *p;
        }//*p == c pula
        p++;
    }
    *q = '\0';  // Adiciona o terminador nulo no final da string
    printf("String apos remover '%c': %s\n", c, str);
    return 0;
}