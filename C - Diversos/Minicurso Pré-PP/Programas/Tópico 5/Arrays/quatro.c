#include<stdio.h>

int main()
{
	float vetor[15] = {};
	int i;
	float soma = 0;
	
	for(i = 0; i < 15; i++)
	{
		scanf("%f",&vetor[i]);
		
		soma += vetor[i];
	}

	printf("%.2f\n", soma / 15.0);

	return 0;
}
