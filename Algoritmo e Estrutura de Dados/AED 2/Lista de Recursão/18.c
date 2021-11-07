#include <stdio.h>

//O superfatorial de um número N é definida pelo produto dos N primeiros fatoriais de N.
//Assim, o superfatorial de 4 é sf (4) = 1! ∗ 2! ∗ 3! ∗ 4! = 288
//Faça uma função recursiva que receba um número inteiro positivo N e retorne o superfatorial desse número.

//aux é a variavel que recebe o valor de i!, enquanto 1 =< i =< N
int superfatorial(int N, int aux, int i)
{
	aux = aux * i;

	if(i == N)
		return aux;
	else
		return aux * superfatorial(N, aux, i + 1);
}

int main()
{
	int N;

	scanf("%d",&N);
	printf("%d\n",superfatorial(N,1,1));

	return 0;
}