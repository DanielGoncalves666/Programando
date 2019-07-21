#include<stdio.h>
#include<stdlib.h>

float custo, custo_imposto,custo_total;

void custo_de_fabrica()
{
    scanf("%f",&custo);
}
float impostos(float inicial)
{
    float custo_final, intermediario;

    intermediario=(inicial/100)*45;
    custo_final=inicial+intermediario;
    return custo_final;
}
float distribuidor(float inicial_2)
{
    float custo_final_2, intermediario_2;

    intermediario_2=(inicial_2/100)*28;
    custo_final_2=inicial_2+intermediario_2;
    return custo_final_2;
}

int main()
{
    custo_de_fabrica();
    custo_imposto=impostos(custo);
    custo_total=distribuidor(custo_imposto);
    printf("O custo deste carro e de R$%.2f",custo_total);

    return 0;
}
