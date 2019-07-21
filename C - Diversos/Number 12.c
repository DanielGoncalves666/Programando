#include<stdio.h>
#include<stdlib.h>

float preco_de_custo,taxa1,precofinal;

void custo()
{
    scanf("%f",&preco_de_custo);
}
void taxa()
{
    scanf("%f",&taxa1);
}
float venda(float a,float b)
{
    float taxa2,result;
    taxa2=(a/100)*b;
    result=a+taxa2;
    return result;
}

int main()
{
    custo();
    taxa();
    precofinal=venda(preco_de_custo,taxa1); //aqui foi considerado que o preço de venda fosse igual ao custo
    printf("O preco de venda foi de %.2f",precofinal);

    return 0;
}
