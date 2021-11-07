#include<stdio.h>

// Faça uma função recursiva que receba um número inteiro positivo N e imprima todos os
//números naturais de 0 até N em ordem decrescente.

void sequencia(int N)
{
	if(N == 0)
		printf("%d\n",N);
	else
	{
		printf("%d\n",N);
		sequencia(N - 1);
	}
}

int main()
{
	int N;

	scanf("%d",&N);
	sequencia(N);

	return 0;
} 