#include <stdlib.h>
#include <time.h>
#include "header.h"

void aleatorio(int *vet, int tamanho);
void preenche_sequencia_asc(int *vet, int tamanho);
void preenche_sequencia_desc(int *vet, int tamanho);
void preenche_poucas_chaves(int *vet, int tamanho);

int preencheVetor(int **vetor, int *tamanho)
{
	int escolha;

	printf("\nEntre com o tamanho do vetor:\n");
	scanf("%d",tamanho);

	*vetor = (int *) malloc(sizeof(int) * *tamanho);
	if(*vetor == NULL)
	{
		printf("\nFalha na alocação do vetor.\n");
		return 0;
	}

	do
	{
		printf("\n ---- Menu: Método de Preenchimento ----\n");
		printf("1 - Aleatório\n");
		printf("2 - Ascendente\n");
		printf("3 - Descendente\n");
		printf("4 - Poucas chaves\n");
		scanf("%d",&escolha);

		switch(escolha)
		{
			case 1:
				aleatorio(*vetor, *tamanho);
				return 1;
			case 2:
				preenche_sequencia_asc(*vetor, *tamanho);
				return 1;
			case 3:
				preenche_sequencia_desc(*vetor, *tamanho);
				return 1;
			case 4:
				preenche_poucas_chaves(*vetor, *tamanho);
				return 1;
		}
	
	}while(1);
}

void aleatorio(int *vet, int tamanho)
{
	int i;
	srand(time(NULL));

	for(i = 0; i < tamanho; i++)
		vet[i] = rand() % tamanho;
}

void preenche_sequencia_asc(int *vet, int tamanho){
	int i;
	int comeco = 0;

	for(i = 0; i < tamanho; i++) {
		vet[i] = comeco;
		comeco++;
	}
}

void preenche_sequencia_desc(int *vet, int tamanho){
	int i;
	int fim = tamanho - 1;

	for(i = 0; i < tamanho; i++) {
		vet[i]=fim;
		fim--;
	}
}

void preenche_poucas_chaves(int *vet, int tamanho){
  	int i;
	int nchaves = tamanho % (tamanho % 4);

	srand(time(NULL));
	for(i = 0; i < tamanho; i++) 
	{
		vet[i] = rand()%nchaves;
	}
}
