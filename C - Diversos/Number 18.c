#include<stdio.h>
#include<stdlib.h>

int tipo_de_cliente;
float KWh,valor;

void cliente()
{
    do
    {
        scanf("%d",&tipo_de_cliente);
    }while(tipo_de_cliente>3 || tipo_de_cliente<1);
}
void valor_consumido()
{
    scanf("%f",&KWh);
}
float conta_de_luz(int a, float b)
{
    float result;
    if(a==1)
        result=b*0.60;
    if(a==2)
        result=b*0.48;
    if(a==3)
        result=b*1.29;
    return result;
}

int main()
{
    cliente();
    valor_consumido();
    valor=conta_de_luz(tipo_de_cliente,KWh);
    printf("Voce tera que pagar nesta conta de luz R$ %.2f",valor);

    return 0;
}
