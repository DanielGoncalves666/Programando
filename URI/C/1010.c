#include<stdio.h>
#include<stdlib.h>

int p1,p2,qtd1,qtd2;
float v1,v2,total,vt1,vt2;

int main()
{
    scanf("%d",&p1);
    scanf("%d",&qtd1);
    scanf("%f",&v1);
    vt1=(qtd1*v1);

    scanf("%d",&p2);
    scanf("%d",&qtd2);
    scanf("%f",&v2);
    vt2=(qtd2*v2);
    total=vt1+vt2;

    printf("VALOR A PAGAR: R$ %.2f\n",total);

    return 0;
}
