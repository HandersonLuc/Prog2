/*Um cadastro de pessoas é representado por um vetor de ponteiros para o tipo Pessoa, conforme
descrito a seguir:
struct pessoa {
int codigo;
char nome[81];
};
typedef struct pessoa Pessoa;
Considere que esse vetor está em ordem crescente de código, e, além disso, o código é a
identificação única da pessoa. Aplicando a técnica de busca binária, implemente uma função que
verifique se um código fornecido como parâmetro existe no vetor. A função retorna o ponteiro
para esta pessoa (Pessoa *). Caso contrário, a função deve retornar NULL. A função recebe como
parâmetros o ponteiro vet, para o primeiro elemento do vetor, o inteiro n, que representa o
tamanho do vetor, e o código. Seu protótipo é:
Pessoa* busca(int n, Pessoa** vet, int codigo);
Faça também um programa para testar essa função.*/