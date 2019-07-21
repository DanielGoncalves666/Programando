#include<stdio.h>
#include<stdlib.h>

int a, b;

void ler()
{
    scanf("%d",&a);
    scanf("%d",&b);
}
void maior(int num3, int num4)
{
    if(num3>num4)
        printf("O maior numero e o %d.",num3);
    if(num4>num3)
        printf("O maior numero e o %d.",num4);
}
void verificacao(int num1, int num2)
{
    if(num1==num2)
        printf("Os dois numeros sao iguais.");
    if(num1!=num2)
    {
        printf("Os dois numeros sao diferentes.\n");
        maior(num1,num2);
    }
}

int main()
{
    ler();
    verificacao(a,b);

    return 0;
}
