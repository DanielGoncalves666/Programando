#include <stdio.h>

//O hiperfatorial de um número N, escrito H(n), é definido por
//	H(n) = o produtorio de k = 1 até n de k ^ k = 1¹ * 2² * 3³ * ... * N^N
//
//Faça uma função recursiva que receba um número inteiro positivo N e retorne o hiperfa-
//torial desse número.

int potencia(int N, int k)
{
	if(k == 0)
		return 1;
	else
		return N * potencia(N, k - 1);
}

//k = 1
int hiperfatorial(int N, int k)
{
	if(N == k)
		return potencia(k,k);
	else
		return potencia(k,k) * hiperfatorial(N, k + 1);
}


int main()
{
	int N;

	scanf("%d",&N);
	printf("%d\n",hiperfatorial(N,1));

	return 0;
}