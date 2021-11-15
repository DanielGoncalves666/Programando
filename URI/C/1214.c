#include<stdio.h>

int
main()
{
	int C = 0, N = 0, soma, qtd;
	double media = 0.0;

	scanf("%d",&C);
	for(int i = 0; i<C; i++)
	{
		scanf("%d",&N);
		
		int vet[N];
		soma = 0, media = 0.0, qtd = 0;
		for(int h = 0; h<N; h++)
		{
			scanf("%d", &vet[h]);
			soma += vet[h];
		}

		media = soma / (double) N;

		for(int h = 0; h<N; h++)
		{
			if(vet[h] > media)
				qtd++;
		}

		printf("%.3f%%\n", (qtd / (double) N) * 100);
	}

	return 0;
}