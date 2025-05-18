#include <stdio.h>

int main()
{
    int x[10], y[10];
    int n=9;
    for(int i=0;i<10;i++){
        printf("Digite num\n");
        scanf("%d", &x[i]);
    }
    for(int i =0;i<10;i++){
        y[i]=x[n];
        n-=1;
    }
    for(int i =0;i<10;i++){
        printf("%d\n", y[i]);
    }
    return 0;
}