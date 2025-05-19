#include <stdio.h>

#define MAX 5

void armazena(int *v1, int *v2, char *op);

void calcula(int *v1, int *v2, char *op, float *v3);

int main()
{
    int v1[MAX], v2[MAX];
    char op[MAX];
    float v3[MAX];
    for(int i=0;i<MAX;i++){
        printf("digite uma op\n");
        scanf("%c", &op[i]);
    }
    armazena(v1,v2,op);
    calcula(v1,v2,op,v3);
    for(int i=0;i<MAX;i++){
        printf("%f\n",v3[i]);
    }
    return 0;
}

void armazena(int *v1, int *v2, char *op){
    for(int i=0;i<MAX;i++){
        printf("digite um valor\n");
        scanf("%d", &v1[i]);
    }
    for(int i=0;i<MAX;i++){
        printf("digite um valor\n");
        scanf("%d", &v2[i]);
    }
}

void calcula(int *v1, int *v2, char *op, float *v3){
    for(int i=0;i<MAX;i++){
        switch(op[i]){
            case '+' : v3[i]=v1[i]+v2[i]; break;
            case '-' : v3[i]=v1[i]-v2[i]; break;
            case '/' : v3[i]=v1[i]/v2[i]; break;
            case '*' : v3[i]=v1[i]*v2[i]; break;
        }
    }
}







