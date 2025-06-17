/*Tendo o seguinte código:
a. O programa acima pode ter no máximo 1 erro. Caso tiver, explique qual é o erro.
b. Qual o valor mostrado na tela no segundo (último) printf?*/

typedef struct data {
int dia;
int mes;
char nomeMes[12];
} Data;
main()
{
Data aniversarios[3] = { {5,1,"JANEIRO"},
{4,2,"FEVEREIRO"},{10,3,"MAIO"} };
int a;
Data *p_dt;
p_dt=&aniversarios[2];
printf("Nome do mês %d é: %s.", p_dt->mes, p_dt->nomeMes);
strcpy(p_dt->nomeMes, "MARÇO");
printf("\nNúmero de letras : %d=", strlen(p_dt->nomeMes));
Data p_dt2 = (Data *) malloc(sizeof(Data));
p_dt2 = &aniversarios[0];
}
// Resposta a: O programa tem um erro de alocação de memória. A linha `Data p_dt2 = (Data *) malloc(sizeof(Data));` tenta alocar memória para `p_dt2`, mas logo em seguida `p_dt2` é atribuído a apontar para `aniversarios[0]`, perdendo a referência à memória alocada, o que causa um vazamento de memória.
// Resposta b: O valor mostrado na tela no segundo printf será o número de letras do nome do mês "MARÇO", que é 5.