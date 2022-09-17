/*
O total de numeros é informado pelo usuario quando o programa é chamado.
Daniel Goncalves 2021
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int qtd = atoi(argv[argc - 1]);

	if(qtd > 30)
	{
		printf("Nao é permitida a entrada de mais de 30 numeros.\n");
		return 1;
	}

	int *vetor = NULL;//vetor de inteiros
	int i = 0;

	for(i = 0; i < qtd; i++)
	{
		vetor = (int *) realloc(vetor, sizeof(int) * (i + 1));
		printf("Entre com o %dº valor:\n",i + 1);
		scanf("%d", &vetor[i]);
	}

	for(i = 0; i < qtd; i++)
	{
		printf("%d ",vetor[i]);
	}
	printf("\n");

	return (0);
}