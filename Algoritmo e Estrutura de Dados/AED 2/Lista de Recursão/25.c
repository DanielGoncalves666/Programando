#include <stdio.h>

// Os números de Catalan são definidos pela seguinte recursão

//Alguns números desta sequência são: 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786...
//Faça uma função recursiva que receba um número N e retorne o N-ésimo número de Catalan.

//os valores não estão batendo
int catalan(int N)
{
	if(N == 0)
		return 1;
	else
	{
		double aux = (2 * ( (2 * N) - 1)) / (double) (N + 1);  
		return aux * catalan(N - 1);
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	printf("%d\n",catalan(N));


	return 0;
}