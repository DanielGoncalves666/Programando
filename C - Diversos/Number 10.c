#include<stdio.h>
#include<stdlib.h>

float atual, dispon, reais;

void cotacao()
{
    scanf("%f",&atual);
}
void disponivel()
{
    scanf("%f",&dispon);
}
float real(int a, int b)
{
    int c;
    c=a*b;
    return c;
}

int main()
{
    cotacao();
    disponivel();
    reais= real(atual,dispon);
    printf("$%.2f", reais);

    return 0;
}
