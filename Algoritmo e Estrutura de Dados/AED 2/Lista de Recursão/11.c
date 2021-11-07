#include <stdio.h>

// A multiplicação de dois números inteiros pode ser feita através de somas sucessivas.
// Proponha um algoritmo recursivo Multip Rec(n1,n2) que calcule a multiplicação de dois
// inteiros.

int MultipRec(int N1, int N2)
{
	if(N2 == 1)
		return N1;
	else
		return N1 + MultipRec(N1, N2 - 1);
}

int main()
{
	int N1, N2;

	scanf("%d %d",&N1,&N2);
	printf("%d\n",MultipRec(N1,N2));

	return 0;
}