#include<stdio.h>
#include<stdlib.h>

float km, combugas, conmedio, consum;

void dados()
{
    scanf("%f",&km);
    scanf("%f",&combugas);
}
float consumo()
{
    conmedio=km;
    return conmedio;
}
int main()
{
    dados();
    consum=consumo();
    printf("O carro consumiu %.2f litros de combustivel",consum);

    return 0;
}
