#include<stdio.h>
#include<stdlib.h>

int cod,qtd;
float valor;

int main()
{
    scanf("%d",&cod);
    scanf("%d",&qtd);
    if(cod==1)
    {
        valor=4.0*qtd;
    }
    if(cod==2)
    {
        valor=4.5*qtd;
    }
    if(cod==3)
    {
        valor=5.0*qtd;
    }
    if(cod==4)
    {
        valor=2.0*qtd;
    }
    if(cod==5)
    {
        valor=1.5*qtd;
    }
    printf("Total: R$ %.2f\n",valor);
}
