#include<stdio.h>
#include<stdlib.h>

int A,B,C,D,soma1,soma2;

int main()
{
    scanf("%d",&A);
    scanf("%d",&B);
    scanf("%d",&C);
    scanf("%d",&D);

    soma1=C+D;
    soma2=A+B;

    if(B>C && D>A && soma1>soma2 && C>0 && D>0 && A%2==0)
    {
        printf("Valores aceitos\n");
    }
    else
    {
        printf("Valores nao aceitos\n");
    }

    return 0;
}
