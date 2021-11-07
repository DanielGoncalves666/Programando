#include<stdio.h>

//A função fatorial duplo é definida como o produto de todos os números naturais ı́mpares
//de 1 até algum número natural ı́mpar N. Assim, o fatorial duplo de 5 é
// 						5!! = 1 ∗ 3 ∗ 5 = 15


int fatorialDuplo(int N)
{
	if(N == 1)
		return 1;
	else
		return N * fatorialDuplo(N - 2);
}

int main()
{
	int N;

	scanf("%d",&N);
	printf("Fatorial duplo de %d = %d\n",N,fatorialDuplo(N));

	return 0;
}