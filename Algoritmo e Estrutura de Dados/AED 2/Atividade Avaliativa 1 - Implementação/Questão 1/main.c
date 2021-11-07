#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

void imprime(int *vetor, int tamanho);
void copiaVetor(int *vetor, int *copia, int tamanho);
void calculaTempo(int *vetor, int tamanho);

int main()
{
	int escolha, retorno, tamanho;
	int *vetor = NULL;

	do
	{

		printf("\n-------- Menu -------\n");
		printf("1 - Quicksort Pilha - Básico\n");
		printf("2 - Quicksort Pilha - Aleatorizado\n");
		printf("3 - Quicksort Pilha - Mediana de Três\n");
		printf("4 - Calcula tempo\n");
		printf("5 - Sair\n");

		scanf("%d",&escolha);

		retorno = preencheVetor(&vetor, &tamanho);
		if(retorno == 0)
			break;

		switch(escolha)
		{
			case 1:
				printf("\nAntes: ");
				imprime(vetor,tamanho);
				quicksort(vetor,0, tamanho - 1);
				printf("\nDepois: ");
				imprime(vetor,tamanho);
				break;
			case 2:
				printf("\nAntes: ");
				imprime(vetor,tamanho);
				quicksortAleatorizado(vetor,0, tamanho - 1);
				printf("\nDepois: ");
				imprime(vetor,tamanho);
				break;
			case 3:
				printf("\nAntes: ");
				imprime(vetor,tamanho);
				quicksortMediana3(vetor,0, tamanho - 1);
				printf("\nDepois: ");
				imprime(vetor,tamanho);
				break;
			case 4:
				calculaTempo(vetor,tamanho);
				break;
		}

		free(vetor);
	}while(escolha != 5);

	return 0;
}

void imprime(int *vetor, int tamanho){
	int i;
	
	for(i = 0; i < tamanho; i++) 
	{
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

void copiaVetor(int *vetor, int *copia, int tamanho)
{
	int i;

	for(i = 0; i < tamanho; i++)
		copia[i] = vetor[i];
}

void calculaTempo(int *vetor, int tamanho)
{
	clock_t ini, fim;
	double tempo;
	int *copia = malloc(sizeof(int) * tamanho);
	
	copiaVetor(vetor,copia,tamanho);
	ini = clock();
	quicksort(copia,0,tamanho - 1);
	fim = clock();
	tempo = ((double)fim-ini)/CLOCKS_PER_SEC;
  	printf("\nTempo gasto (pilha normal): %.8f seconds.", tempo);

	copiaVetor(vetor,copia,tamanho);
	ini = clock();
	quicksortAleatorizado(copia,0,tamanho - 1);
	fim = clock();
	tempo = ((double)fim-ini)/CLOCKS_PER_SEC;
  	printf("\nTempo gasto (pilha aleatorio): %.8f seconds.", tempo);

	copiaVetor(vetor,copia,tamanho);
	ini = clock();
	quicksortMediana3(copia,0,tamanho - 1);
	fim = clock();

	tempo = ((double)fim-ini)/CLOCKS_PER_SEC;
  	printf("\nTempo gasto (pilha mediana): %.8f seconds.\n", tempo);
}