#include<stdio.h>

/*
 Crie um programa em C que receba um vetor de números reais com 100 elementos.
Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor.
*/

#define tam 100

void inverterVetor(int *vet, int ini, int fim)
{
	int aux;

	if(ini + 1 == fim)
	{
		aux = vet[ini];
		vet[ini] = vet[fim];
		vet[fim] = aux;
	}
	else
	{
		aux = vet[ini];
		vet[ini] = vet[fim];
		vet[fim] = aux;
		inverterVetor(vet,ini + 1, fim - 1);
	}
}

int main()
{
	int vet[100];

	for(int i=0; i < 100; i++)
		vet[i] = i;

	inverterVetor(vet,0,99);

	for(int i = 0; i < 100; i++)
		printf("%d\n",vet[i]);
		

	return 0;
}