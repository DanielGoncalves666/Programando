#include <stdio.h>

// O fatorial quádruplo de um número N é dado por: (2n)! / n!
//Faça uma função recursiva que receba um número inteiro positivo N e retorne o fatorial
//quádruplo desse número.

int fatorial(int N)
{
	if(N == 0 || N == 1)
		return 1;
	else
		return N * fatorial(N - 1);
}

int fatorialQuadruplo(int N)
{
	int fatorialN = fatorial(N);
	int fatorial2N = fatorial(2*N);

	return fatorial2N / fatorialN;
}

int main()
{
	int N;

	scanf("%d",&N);
	printf("%d\n",fatorialQuadruplo(N));

	return 0;
}