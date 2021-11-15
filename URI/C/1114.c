#include<stdio.h>
#include<stdlib.h>

int teste,i;

int main()
{
    for(i=0;i<1;)
    {
        scanf("%d",&teste);
        if(teste!=2002)
        {
            printf("Senha Invalida\n");
        }
        else
        {
            printf("Acesso Permitido\n");
            i+=1;
        }
    }
    return 0;
}
