struct elemento {
    int info;                  
    struct elemento *prox;     
};
typedef struct elemento Elemento;

#include <stdio.h>
#include <stdlib.h>

Elemento* copia(Elemento* lst) {
    if (lst == NULL) return NULL;

    // Cria o primeiro elemento da nova lista
    Elemento* nova = (Elemento*)malloc(sizeof(Elemento));
    if (!nova) {
        printf("Erro de memória.\n");
        exit(1);
    }

    nova->info = lst->info;
    nova->prox = NULL;

    Elemento *origAtual = lst->prox;
    Elemento *novaAtual = nova;

    // Copia os demais elementos
    while (origAtual != NULL) {
        Elemento* novoNo = (Elemento*)malloc(sizeof(Elemento));
        if (!novoNo) {
            printf("Erro de memória.\n");
            exit(1);
        }
        novoNo->info = origAtual->info;
        novoNo->prox = NULL;

        novaAtual->prox = novoNo;
        novaAtual = novoNo;
        origAtual = origAtual->prox;
    }

    return nova;
}

// Insere elemento no início
Elemento* insere(Elemento* lst, int valor) {
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = lst;
    return novo;
}

// Imprime a lista
void imprime(Elemento* lst) {
    while (lst != NULL) {
        printf("%d -> ", lst->info);
        lst = lst->prox;
    }
    printf("NULL\n");
}

int main() {
    Elemento* original = NULL;
    original = insere(original, 30);
    original = insere(original, 20);
    original = insere(original, 10);

    printf("Lista original: ");
    imprime(original);

    Elemento* copiaLista = copia(original);

    printf("Lista copiada: ");
    imprime(copiaLista);

    return 0;
}
