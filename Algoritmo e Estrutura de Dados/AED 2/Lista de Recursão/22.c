#include <stdio.h>

// Os números tetranacci iniciam com quatro termos pré-determinados e a partir daı́ todos
//os demais números são obtidos pela soma dos quatro números anteriores. Os primeiros
//números tetranacci são: 0, 0, 0, 1, 1, 2, 4, 8, 15, 29, 56, 108, 208...
//Faça uma função recursiva que receba um número N e retorne o N-ésimo termo da
//sequência de tetranacci.

int tretanacci(int N)
{
	if(N <= 3)
		return 0;
	else if(N == 4)
		return 1;
	else
		return tretanacci(N - 1) + tretanacci(N - 2) + tretanacci(N - 3) + tretanacci(N - 4);
}

int main()
{
	int N;

	scanf("%d",&N);
	printf("%d\n",tretanacci(N));

	return 0;
}