#include<stdio.h>
#include<stdlib.h>

int n1,n2,n3,tipo_1=0;

void ler()
{
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
}
void cond_existencia(int a,int b,int c)
{
    if(abs(b-c)<a && a<b+c)
        if(abs(a-c)<b && b<a+c)
            if(abs(a-b)<c && c<a+b)
            {
                printf("Os valores desses lados formam um triangulo ");
                tipo_1=1;
            }
            else
                printf("Os valores desses lados nao formam um triangulo.");
        else
            printf("Os valores desses lados nao formam um triangulo.");
    else
        printf("Os valores desses lados nao formam um triangulo.");
}

void tipo(int a1,int b1,int c1)
{
    if(a1==b1 && b1==c1)
        printf("EQUILATERO.");
    else    if(a1==b1 && c1!=a1)
                printf("ISOSCELES.");
            else
                printf("ESCALENO.");
}

int main()
{
    ler();
    cond_existencia(n1,n2,n3);
    if(tipo_1==1)
        tipo(n1,n2,n3);

    return 0;
}
