#include<stdio.h>
#include<stdlib.h>

int num;

void ler()
{
    scanf("%d",&num);
}
void teste()
{
    if(num==40)
        printf("Este numero e igual a 40");
    if(num<25)
        printf("Este numero e menor que 25");
    if(num>80)
        printf("Este numero e maior que 80");
}

int main()
{
    ler();
    teste();

    return 0;
}
