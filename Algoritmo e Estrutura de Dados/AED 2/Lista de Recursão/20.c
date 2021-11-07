#include<stdio.h>

// Um fatorial exponencial é um inteiro positivo N elevado à potência de N-1, que por sua
//vez é elevado à potência de N-2 e assim em diante. Ou seja,

//n^(n−1)^(n−2)^...^1
//Faça uma função recursiva que receba um número inteiro positivo N e retorne o fatorial
//exponencial desse número.

int potencia(int N, int k)
{
	if(k == 0)
		return 1;
	else
		return N * potencia(N, k - 1);
}

//N = aux
int fatorialExponencial(int N, int aux)
{
	if(aux == N)
	{
		int mult = fatorialExponencial(N, aux - 1);
		return potencia(N,mult);
	}
	else if(aux == 1)
		return 1;
	else
		return aux * fatorialExponencial(N,aux - 1);
}
//aqui usei a propriedade da potencia que dita que a potencia de expoentes é a multiplicação entre eles.

int main()
{
	int N;

	scanf("%d",&N);
	printf("%d\n",fatorialExponencial(N,N));

	return 0;
}