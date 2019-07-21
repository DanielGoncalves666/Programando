#include<stdio.h>
#include<stdlib.h>

float valor_produto,prestacao;

void valor()
{
    scanf("%f",&valor_produto);
}
float prestacoes(float a)
{
    int b;
    b=a/5;
    return b;
}

int main()
{
    valor();
    prestacao= prestacoes(valor_produto);
    printf("O valor de cada prestacao e de R$%.2f",prestacao);


    return 0;
}
