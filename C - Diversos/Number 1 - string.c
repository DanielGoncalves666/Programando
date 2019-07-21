#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i, h=0, m=0;
char nome[50], sexo[15];

int main()
{
    for(i=0;i<56;i++)
    {
    	printf("Informe o nome da pessoa.\n");
        scanf("%s",nome);
        printf("Informe o sexo da pessoa: Feminino ou Masculino.\n");
        scanf("%s",sexo);
        printf("O nome dessa pessoa e %s.\n",nome);
        if(strcmp(sexo,"Masculino")==0)
        {
            h++;
            printf("E ele e homem.\n");
        }
        if(strcmp(sexo,"Feminino")==0)
        {
            m++;
            printf("E ela e mulher.\n");
        }
    }
    printf("Fora informados os nomes de %d homens e %d mulheres.\n",h,m);
    
    return 0;
}
