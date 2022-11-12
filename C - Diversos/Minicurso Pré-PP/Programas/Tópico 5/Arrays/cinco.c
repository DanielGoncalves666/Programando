#include<stdio.h>


int main()
{
	float vetor[15] = {0};
	int i;
	int neg = 0;
	float soma = 0;
	
	for(i = 0; i < 15; i++)
	{
		scanf("%f",&vetor[i]);
		
		if(vetor[i] < 0)
			neg++;
		else
			soma += vetor[i];
	}
	
	printf("Negativos: %d\nSoma positivos: %.2f\n", neg, soma);

	return 0;
}
