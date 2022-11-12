#include<stdio.h>

int main()
{
	int vetor[10] = {};
	int i;
	int cont = 0;
	
	for(i = 0; i < 10; i++)
	{
		scanf("%d",&vetor[i]);
		
		if(vetor[i] % 2 == 0)
			cont++;
	}

	printf("%d pares\n",cont);

	return 0;
}
