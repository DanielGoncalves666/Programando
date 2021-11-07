#include<stdio.h>

// Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório dos números de 1 a N.

int somatorio(int N)
{
	if(N == 1)
		return 1;
	else
		return N + somatorio(N - 1);
}


int main()
{
	int a;

	scanf("%d",&a);
	printf("%d\n",somatorio(a));

	return 0;
}