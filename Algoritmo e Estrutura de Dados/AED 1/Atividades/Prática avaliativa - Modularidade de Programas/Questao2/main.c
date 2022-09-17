/*
Daniel Gonçalves 2021
*/
#include <stdio.h>

int fatorial(int);
int arranjo(int, int);


int main()
{
	int N = 0;//armazena o tamanho do conjunto
	int P = 0;//armazena o tamanho dos arranjos
	int result = 0;//armazena o resultado

	while(1)
	{
		printf("\nEntre com o tamanho do conjunto e o de cada arranjo, respectivamente:\n");
		scanf("%d %d",&N,&P);

		if(N < P || N == 0 || P == 0)
		{
			printf("\nEntrada Nao aceita!\n");
			continue;
		}

		break;
	}

	result = arranjo(N,P);

	printf("Existem %d arranjos de %d elementos em %d elementos.\n",result,P,N);

	return (0);
}

int
fatorial(int num)
{
	if(num == 1 || num == 0)
		return 1;

	return num * fatorial(num - 1);
}

int 
arranjo(int N, int P)
{
	return fatorial(N) / fatorial(N - P);
}