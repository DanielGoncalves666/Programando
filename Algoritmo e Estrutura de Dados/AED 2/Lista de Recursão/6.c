#include <stdio.h>

/*
Crie um programa em C, que contenha uma função recursiva que receba dois inteiros
positivos k e n e calcule k^n . Utilize apenas multiplicações. O programa principal deve
solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da função.
*/

int potencia(int k, int n)
{
	if(n == 0)
		return 1;
	else
		return k * potencia(k, n - 1);
}

int main()
{
	int k,n;

	scanf("%d %d",&k,&n);
	printf("k elevado a n é %d\n",potencia(k,n));


	return 0;
}