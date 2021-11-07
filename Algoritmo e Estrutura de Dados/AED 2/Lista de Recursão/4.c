#include<stdio.h>

// Faça uma função recursiva que permita somar os elementos de um vetor de inteiros.

//vet é o endereço para um vetor e tamanho é a ultima posicao do vetor
int somaVet(int *vet, int tamanho)
{
	if(tamanho == -1)
		return 0;
	else
		return vet[tamanho] + somaVet(vet,tamanho - 1);
}


int main()
{
	int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("%d\n", somaVet(vet, sizeof(vet)/ sizeof(int) - 1));

	return 0;
}