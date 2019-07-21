#include<stdio.h>
#include<stdlib.h>

int A,B,n1,n2;

void ler()
{
    scanf("%d",&A);
    scanf("%d",&B);
}
void troca()
{
    n1=A;
    n2=B;
    A=n2;
    B=n1;
}

int main()
{
    ler();
    troca();
    printf("%d\n",A);
    printf("%d\n",B);

    return 0;
}
