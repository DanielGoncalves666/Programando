#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char senha[30];
int num,i,a,b,soma;

void somar()
{
	printf("Digite o primeiro numero\n");
	scanf("%d",&a);
	printf("Digite o segundo numero\n");
	scanf("%d",&b);
	soma=a+b;
	printf("A soma e de %d.",soma);
}

int main()
{
	for(i=5;i>0;i--)
	{
		printf("Digite a senha:\n");
		scanf("%s",&senha);
		num=strcmp(senha,"Delicia");
		if(num==0)
		{
			somar();
		}
		else
		{
			printf("Senha incorreta. Restam %d tentativas.\n",i-1);
			if(i-1==0)
			{
				printf("Suas chances acabaram.\n");
			}
		}
	}
	
	return 0;
}
