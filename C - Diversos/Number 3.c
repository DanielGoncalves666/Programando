#include<stdio.h>
#include<stdlib.h>

int idade;

void categoria()
{
    if(idade<18 && idade>0)
        printf("O jogador e da categoria Junior.\n");
    if(idade>=18 && idade<=33)
        printf("O jogador e da categoria Professional.\n");
    if(idade>33)
        printf("O jogador e da categoria Master.\n");
}
int main()
{
    scanf("%d",&idade);
    categoria();

    return 0;
}
