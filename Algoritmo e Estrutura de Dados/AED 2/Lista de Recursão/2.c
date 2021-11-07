#include<stdio.h>

//Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência Fibonacci.
//Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...

int fibonacci(int N)
{
	if(N == 1)
		return 0;
	else if(N == 2)
		return 1;
	else
		return fibonacci(N - 1) + fibonacci(N - 2);
}

int main()
{
	printf("%d\n", fibonacci(8));

	return 0;
}