/*Mostre e explique (comentando as linhas de código) o que será impresso na tela:
#include<stdio.h>
#include<string.h>
main(void)
{
char texto[]= "foi muito facil";
int i;
for (i = 0; texto[i]!='\0'; i++)
{
if (texto[i] == ' ') break;
}
i++;
for ( ; texto[i]!='\0'; i++)
{
printf("%c", texto[i]);
}
}*/

//Mostre e explique (comentando as linhas de código) o que será impresso na tela:
#include<stdio.h>
#include<string.h>
main(void)
{
char texto[]= "foi muito facil";
int i;
for (i = 0; texto[i]!='\0'; i++)
{
if (texto[i] == ' ') break; // Encontra o primeiro espaço na string
}
i++;
for ( ; texto[i]!='\0'; i++) // Continua a partir do próximo caractere após o espaço
{
printf("%c", texto[i]);
printf("Vai ser printado 'muito facil' na tela\n");
}
} 