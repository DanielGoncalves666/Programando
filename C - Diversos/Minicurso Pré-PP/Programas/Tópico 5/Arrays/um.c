#include<stdio.h>

int main()
{
	int vetor[6] = {0};
	int i;

	for(i = 0; i < 6; i++)
	{
		scanf("%d",&vetor[i]);
	}
	
	for(i = 0; i < 6; i++)
	{
		printf("%d\n", vetor[i]);
	}


	return 0;
}
