#include <stdio.h>
#include <stdlib.h>

struct elemento {
    float info; /* Valor real armazenado */
    struct elemento *prox; /* Ponteiro para o próximo elemento */
};

typedef struct elemento Elemento;

Elemento* filtra(Elemento *lst, float min, float max);

Elemento *cria(void);

Elemento *insere(Elemento *lista, float n);

void imprime(Elemento *lista);

void MinMax(Elemento *lista,float *min, float *max);

void libera(Elemento *lista);

int main()
{
    Elemento *lista;
    int z=1;
    float n, min, max;
    lista= cria();
    while(z!=0){
        printf("Digite 0-Encerrar 1-inserir 2-libera 3-imprime\n");
        scanf("%d",&z);
        if(z==1){
            printf("Digite um numero:");
            scanf("%f",&n);
            lista=insere(lista,n);
        }
        else if(z==2){
            MinMax(lista,&min,&max);
            lista=filtra(lista,min,max);
        }
        else if(z==3) imprime(lista);
    }
    libera(lista);
    return 0;
}

Elemento *cria(void){
    return NULL;
}

Elemento *insere(Elemento *lista,float n){
    Elemento *novo=(Elemento*)malloc(sizeof(Elemento));
    novo->info=n;
    novo->prox=lista;
    return novo;
}

void imprime(Elemento *lista){
    Elemento *l;
    for(l=lista;l!=NULL;l=l->prox) printf("%f\n",l->info);
}

void MinMax(Elemento *lista,float *min, float *max){
    Elemento *l;
    imprime(lista);
    printf("Digite o min e max da lista:");
    scanf("%f %f", min,max);
}


Elemento* filtra(Elemento *lst, float min, float max){
    Elemento *ant=NULL;
    Elemento *l=lst;
    while(l!=NULL){
        if(l->info<min||l->info>max){
            Elemento *rem=l;
            if(ant==NULL){
                lst=l->prox;
                l=lst;
            }
            else{
                ant->prox=l->prox;
                l=l->prox;
            }
            free(rem);
        }
        else{
            ant=l;
            l=l->prox;
        }
    }
    return lst;
}

void libera(Elemento *lista){
    Elemento *l=lista;
    Elemento *t;
    while(l!=NULL){
        t=l->prox;
        free(l);
        l=t;
    }
}