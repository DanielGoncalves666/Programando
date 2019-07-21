#include<stdio.h>
#include<stdlib.h>

int num;

void fon()
{
    if(num%2==0)
        printf("O numero digitado e par");
    else
        printf("O numero digitado e impar");
}

int main()
{
    scanf("%d",&num);
    fon();

    return 0;
}
