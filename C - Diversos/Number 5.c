#include<stdio.h>
#include<stdlib.h>

int ano,idade;

void nascimento()
{
	scanf("%d",&ano);
}
void id()
{
	idade=2017-ano;
	printf("Voce possui %d anos.\n",idade);
}

void classificacao()
{
	if(idade<15)
		printf("Alem disso, voce possui menos de 15 anos.\n");
	if(idade>=15 && idade<18)
		printf("Alem disso, voce possui 15 ou mais anos e menos que 18 anos.\n");
	if(idade>=18)
		printf("Alem disso, voce possui 18 ou mais anos.\n");
}

int main()
{
	nascimento();
	id();
	classificacao();

    return 0;
}
