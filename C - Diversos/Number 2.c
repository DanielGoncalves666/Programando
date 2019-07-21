#include<stdio.h>
#include<stdlib.h>

int i;
float lojas[3],menor,menorv;

float vrau()
{
    for(i=0;i<3;i++)
    {
        if(i==0)
            menor=lojas[i];
		if(lojas[i]<menor)
            menor=lojas[i];
    }
    return menor;
}
void loja_m()
{
    if(menorv==lojas[0])
        printf("O produto da loja 1 possui o menor preco!\n");
    if(menorv==lojas[1])
        printf("O produto da loja 2 possui o menor preco!\n");
    if(menorv==lojas[2])
        printf("O produto da loja 3 possui o menor preco!\n");
}

int main()
{
    for(i=0;i<3;i++)
    {
        scanf("%f",&lojas[i]);
    }
    menorv=vrau();
    loja_m();

    return 0;
}
