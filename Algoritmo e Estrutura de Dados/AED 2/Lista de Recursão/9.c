#include <stdio.h>

// Crie uma função recursiva que receba um número inteiro positivo N e calcule o produtório
// dos números de 1 a N.

int produtorio(int N)
{
	if(N == 1)
		return 1;
	else
		return N * produtorio(N - 1);
}

int main()
{
	int N;

	scanf("%d",&N);
	printf("%d\n", produtorio(N));

	return 0;
}