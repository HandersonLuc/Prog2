/*A cadeia que representa a parte local de um endereço de e-mail Hotmail válido (aquela parte
que vem à esquerda do “@”) tem no máximo 64 caracteres e pode conter apenas letras (‘a’ a ‘z’) e
números (‘0’ a ‘9’), e os caracteres ponto (‘.’), hífen (‘-’) e sublinhado (‘_’). Quaisquer outros
caracteres especiais ou letras acentuadas não são permitidos. Além disso, a cadeia deve conter no
mínimo duas letras ou números, seu primeiro caractere tem que ser necessariamente uma letra, e
o caractere ponto (“.”) não pode aparecer em sequência ou ser o último da cadeia. Por exemplo,
“jsilva”, “t.o.n.y-99_”, “x-__7-” são strings válidas, enquanto “3marias”, “_peter”, “bia.”, “abc...z”
são incorretas. Escreva uma função em C que receba como parâmetros a cadeia s, representando
a parte local de um endereço de e-mail, e retorne 1 se a cadeia for válida de acordo com as
condições descritas, ou 0, se for inválida. A função deve ter o seguinte protótipo:

int valida_mail(char *s);*/

#include <stdio.h>
#include <stdlib.h>

int valida_mail(char *s);

int main() {
    char email[65]; // 64 caracteres + 1 para o terminador nulo
    printf("Digite a parte local do endereco de e-mail: ");
    scanf("%64s", email); // Limita a leitura a 64 caracteres

    if (valida_mail(email)) {
        printf("Endereco de e-mail valido.\n");
    } else {
        printf("Endereco de e-mail invalido.\n");
    }

    return 0;
}

int valida_mail(char *s) {
    int letras_numeros = 0; // Contador de letras e números
    char *p = s;

    // Verifica se o primeiro caractere é uma letra
    if (!(*p >= 'a' && *p <= 'z') && !(*p >= 'A' && *p <= 'Z')) {
        return 0; // Primeiro caractere deve ser uma letra
    }

    while (*p != '\0') {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9')) {
            letras_numeros++;
        } else if (*p == '.' || *p == '-' || *p == '_') {
            // Verifica se o caractere especial é seguido por outro caractere inválido
            if (*(p + 1) == '.' || *(p + 1) == '-' || *(p + 1) == '_' || *(p + 1) == '\0') {
                return 0; // Ponto não pode ser seguido por outro ponto ou ser o último
            }
        } else {
            return 0; // Caractere inválido
        }
        p++;
    }

    // Verifica se há pelo menos duas letras ou números
    if (letras_numeros < 2) {
        return 0;
    }

    return 1; // E-mail válido
}