#include<stdio.h>

//Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N.

int fatorial(int N)
{
	//uma funçao recursiva tem duas partes, uma condição de parada e a parte recursiva

	if(N == 0 || N == 1)
		return 1;
	else
		return N * fatorial(N - 1);
}

int main()
{
	printf("%d\n", fatorial(5));

	return 0;
}