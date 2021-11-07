#include<stdio.h>

// Faça uma função recursiva que receba um número inteiro positivo par N e imprima todos
//os números pares de 0 até N em ordem crescente.

void sequencia(int aux, int N)
{
	if(aux >= N)
		printf("%d\n",aux);
	else
	{
		printf("%d\n",aux);
		sequencia(aux + 2, N);
	}
}

int main()
{
	int aux,N;

	scanf("%d %d",&aux,&N);
	sequencia(aux,N);

	return 0;
} 