#include <stdio.h>

// Os números tribonacci são definidos pela seguinte recursão
//f(n) = 0 se n = 0
//f(n) = 0 se n = 1
//f(n) = 1 se n = 2
//f(n) = f(n-1)+f(n-2)+f(n-3) se n > 3
//Faça uma função recursiva que receba um número N e retorne o N-ésimo termo da
//sequência de tribonacci.

int tribonacci(int N)
{
	if(N == 0 || N == 1)
		return 0;
	else if(N == 2)
		return 1;
	else
		return tribonacci(N - 1) + tribonacci(N - 2) + tribonacci(N - 3);
}

int main()
{
	int N;
	
	scanf("%d",&N);
	printf("%d\n",tribonacci(N));

	return 0;
}