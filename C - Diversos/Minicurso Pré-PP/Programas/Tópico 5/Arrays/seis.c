#include<stdio.h>

int main()
{
	int vetor[5] = {0};
	int i;
	int maior = 0, menor = 0;
	int posMaior = 0, posMenor = 0;
	
	for(i = 0; i < 5; i++)
	{
		scanf("%d",&vetor[i]);
	}
	
	for(i = 0; i < 5; i++)
	{
		if(i == 0)
		{
			maior = vetor[0];
			menor = vetor[0];
		}
		else
		{
			if(vetor[i] > maior)
			{
				maior = vetor[i];
				posMaior = i;
			}
			
			if(vetor[i] < menor)
			{
				menor = vetor[i];
				posMenor = i;
			}
		}
	}
	
	printf("Posmaior: %d\n Posmenor: %d\n", posMaior, posMenor);


	return 0;
}
