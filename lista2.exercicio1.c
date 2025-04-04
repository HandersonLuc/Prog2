#include <stdio.h>

int main(){
    int num;
    printf("Num: \n");
    scanf("%d", &num);
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            printf("NUMERO NAO PRIMO\n");
            break;
        }else
        {
            printf("NUMERO PRIMO\n");
            break;
        }
    }
    return 0;
}