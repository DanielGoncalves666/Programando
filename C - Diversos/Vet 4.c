#include<stdio.h>
#include<stdlib.h>

int main()
{
    int vet[12];
    int soma=0,i;

    for(i=0;i<12;i++)
    {
        scanf("%d",&vet[i]);
        soma=vet[i]+soma;
    }
    if(soma>25)
        printf("A soma e maior que 25\n");
    else
        printf("A soma e menor que 25\n");

    return 0;
}
