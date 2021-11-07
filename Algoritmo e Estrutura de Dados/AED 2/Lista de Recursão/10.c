#include <stdio.h>

// Escreva uma função recursiva que determine quantas vezes um dı́gito K ocorre em um
// número natural N. Por exemplo, o dı́gito 2 ocorre 3 vezes em 762021192.

int recorrenciaK(int N, int K)
{
	if(N < 10)
	{
		if(N == K)
			return 1;
		else
			return 0;
	}
	else
	{
		int aux = N % 10;
		if(aux == K)
			return 1 + recorrenciaK(N/10,K);
		else
			return 0 + recorrenciaK(N/10,K);
	}
}

int main()
{
	int N, K;

	scanf("%d %d",&N,&K);

	printf("%d\n", recorrenciaK(N,K));


	return 0;
}