/*Fazer um programa para cadastro e diálogo de login. O programa deve:
a. Cadastrar um nome de usuário via teclado. O nome de usuário tem, no máximo, 8 caracteres,
sendo válidos somente os caracteres numéricos e as letras maiúsculas ou minúsculas. Somente os
caracteres válidos devem ser exibidos no console durante a digitação do nome de usuário.
b. Cadastrar uma senha do usuário via teclado. Esta segue as mesmas regras do nome de usuário,
com a diferença de que são exibidos somente asteriscos no console à medida que a senha é digitada.
c. Receber um novo nome de usuário e uma nova senha, utilizando os mesmos procedimentos
descritos nos itens a e b.
d. Comparar o nome de usuário cadastrado com o recebido posteriormente e a senha cadastrada
com a senha recebida. Caso sejam idênticos, informar “OK”, do contrário, informar “Acesso
negado”.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define MAX_LEN 8

void lerEntrada(char *entrada, int ocultar) {
    char ch;
    int i = 0;
    while (i < MAX_LEN) {
        ch = getch();

        if (ch == '\r') { // Enter
            break;
        }

        if (isalnum(ch)) { // Aceita apenas letras e números
            entrada[i++] = ch;
            if (ocultar)
                printf("*");
            else
                printf("%c", ch);
        }
    }

    entrada[i] = '\0'; // Finaliza string
    printf("\n");
}

int main() {
    char usuario[9], senha[9];
    char usuario2[9], senha2[9];

    printf("Cadastro:\n");

    printf("Digite o nome de usuario (max 8 caracteres alfanumericos): ");
    lerEntrada(usuario, 0);

    printf("Digite a senha (max 8 caracteres alfanumericos): ");
    lerEntrada(senha, 1);

    printf("\nLogin:\n");

    printf("Digite o nome de usuario: ");
    lerEntrada(usuario2, 0);

    printf("Digite a senha: ");
    lerEntrada(senha2, 1);

    // Comparar
    if (strcmp(usuario, usuario2) == 0 && strcmp(senha, senha2) == 0) {
        printf("\nOK\n");
    } else {
        printf("\nAcesso negado\n");
    }

    return 0;
}
