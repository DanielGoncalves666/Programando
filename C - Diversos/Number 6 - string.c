#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char nome[50],sexo[15];
int idade;

int main()
{
	scanf("%s",nome);
	scanf("%s",sexo);
	scanf("%d",&idade);
	
	printf("O nome da pessoa e %s\n",nome);	
	if(strcmp(sexo,"Feminino")==0 && idade<25)
		printf("Aceita\n");	
	else
		printf("Nao aceita\n");
		
	return 0;
		
}
