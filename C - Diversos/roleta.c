/*
	Apresenta o resultado de N giradas de uma roleta. Os números sorteados variam de 1 <= X <= 20.
	A saída se dá linha por linha, com cada linha indicando a quantidade de vezes que um valor X foi sorteado.
	Daniel Gonçalves - 2022
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int
main()
{
	int x = 0;//armazena o número sorteado
	int n = 0;//armazena a quantidade de giradas
	int vetor[20] = {};//armazena a quantidade de vezes que o valor X foi sorteado na posiçao X - 1
	int i;
	
	scanf("%d",&n);
	
	srand(time(NULL));
	for(i = 0; i < n; i++)
	{
		x = rand() % 20;
		vetor[x]++;
	}
	
	for(i = 0; i < 20; i++)
		printf("Num.%2d: %d\n",i + 1, vetor[i]);

	return 0;
}
