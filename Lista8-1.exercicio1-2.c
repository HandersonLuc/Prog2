#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 81

void quick(int n,char *s);


int main()
{
    char *s;
    int x;
    s=(char*)malloc(MAX*sizeof(char));
    if(s==NULL){
        printf("Memoria Insuficiente!!");
        exit(1);
    }
    printf("Digite uma string:");
    scanf(" %[^\n]",s);
    x=strlen(s);
    quick(x,s);
    printf("Ordenação Quick:");
    printf("%s\n",s);
    return 0;
}

void quick(int n,char *s){
    if(n>1){
        int x=s[0],a=1,b=n-1;
        do{
            while(a<n&&s[a]<=x) a++;
            while(s[b]>x) b--;
            if(a<b){
                int temp=s[a];
                s[a]=s[b];
                s[b]=temp;
                a++;
                b--;
            }
        }while(a<=b);
        s[0]=s[b];
        s[b]=x;
        quick(b,s);
        quick(n-a,&s[a]);
    }
}



