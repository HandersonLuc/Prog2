/*12. Criar um tipo Livro e um tipo Biblioteca tal como dado abaixo:
(A) Criar uma função Livro * fillLivro() que preenche os campos da estrutura Livro e retorna
esse novo livro.
(B) Criar uma função Biblioteca * fillBiblioteca(int numLivros) que preenche os campos da
estrutura do tipo Biblioteca realizando chamadas a função fillLivro em um número de vezes igual
ao número contido na variável numLivros.
(C) Criar uma função void valorBiblioteca(Biblioteca * b1, int numLivros) que fornece o
montante gasto para se comprar todos os exemplares existentes na biblioteca.
(D) Criar uma função Livro * maiorBiblioteca(Biblioteca * b1, int numLivros) que retorna o livro
com maior número de exemplares.
(E) Criar um programa que ilustra o funcionamento das funções anteriores.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    int ano;
    char titulo[100];
    char autor[100];
    int nVolume; // Número de exemplares de um dado livro.
    float preco;
} Livro;

typedef struct Biblioteca {
    Livro **V; // Armazena a informação de n livros
    int nLivros; // Número de livros existentes na biblioteca
} Biblioteca;

// Função para preencher os dados de um livro
Livro *fillLivro() {
    Livro *livro = malloc(sizeof(Livro));
    if (livro == NULL) {
        printf("Erro de alocação de memória.\n");
        return NULL;
    }
    
    printf("Digite o ano do livro: ");
    scanf("%d", &livro->ano);
    getchar(); // Limpa o buffer do stdin
    
    printf("Digite o título do livro: ");
    fgets(livro->titulo, sizeof(livro->titulo), stdin);
    livro->titulo[strcspn(livro->titulo, "\n")] = 0; // Remove a nova linha
    
    printf("Digite o autor do livro: ");
    fgets(livro->autor, sizeof(livro->autor), stdin);
    livro->autor[strcspn(livro->autor, "\n")] = 0; // Remove a nova linha
    
    printf("Digite o número de exemplares: ");
    scanf("%d", &livro->nVolume);
    
    printf("Digite o preço do livro: ");
    scanf("%f", &livro->preco);
    
    return livro;
}

// Função para preencher a biblioteca
Biblioteca *fillBiblioteca(int numLivros) {
    Biblioteca *biblioteca = malloc(sizeof(Biblioteca));
    if (biblioteca == NULL) {
        printf("Erro de alocação de memória para a biblioteca.\n");
        return NULL;
    }
    
    biblioteca->nLivros = numLivros;
    biblioteca->V = malloc(numLivros * sizeof(Livro *));
    if (biblioteca->V == NULL) {
        printf("Erro de alocação de memória para os livros.\n");
        free(biblioteca);
        return NULL;
    }
    
    for (int i = 0; i < numLivros; i++) {
        printf("Preenchendo dados do livro %d:\n", i + 1);
        biblioteca->V[i] = fillLivro();
    }
    
    return biblioteca;
}

// Função para calcular o valor total da biblioteca
void valorBiblioteca(Biblioteca *b1) {
    float total = 0.0;
    for (int i = 0; i < b1->nLivros; i++) {
        total += b1->V[i]->nVolume * b1->V[i]->preco;
    }
    printf("O valor total da biblioteca é: R$ %.2f\n", total);
}

// Função para encontrar o livro com o maior número de exemplares
Livro *maiorBiblioteca(Biblioteca *b1) {
    if (b1->nLivros == 0) return NULL;

    Livro *maior = b1->V[0];
    for (int i = 1; i < b1->nLivros; i++) {
        if (b1->V[i]->nVolume > maior->nVolume) {
            maior = b1->V[i];
        }
    }
    return maior;
}

int main() {
    int numLivros;

    printf("Digite o número de livros na biblioteca: ");
    scanf("%d", &numLivros);
    getchar(); // Limpa o buffer do stdin

    Biblioteca *biblioteca = fillBiblioteca(numLivros);
    if (biblioteca == NULL) {
        return 1; // Erro ao alocar a biblioteca
    }

    valorBiblioteca(biblioteca);

    Livro *livroMaior = maiorBiblioteca(biblioteca);
    if (livroMaior != NULL) {
        printf("O livro com o maior número de exemplares é:\n");
        printf("Título: %s, Autor: %s, Exemplares: %d\n", 
               livroMaior->titulo, livroMaior->autor, livroMaior->nVolume);
    }

    // Liberando a memória alocada
    for (int i = 0; i < biblioteca->nLivros; i++) {
        free(biblioteca->V[i]);
    }
    free(biblioteca->V);
    free(biblioteca);

    return 0;
}
