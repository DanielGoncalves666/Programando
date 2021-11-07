#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "header.h"

#define MAX 10

void preencherVetor(struct cliente *Clientes);
void imprimir(struct cliente *Clientes);

int main()
{
	struct cliente Clientes[MAX];
	
	srand(time(NULL));
	preencherVetor(Clientes);

	printf("\n---- Sequência Inicial ---- \n");
	imprimir(Clientes);
	
	quicksort_mediana_tres(Clientes,0,MAX - 1);
	mergesortMelhorado(Clientes,0,MAX - 1);

	printf("\n---- Sequência pós ordenação ---- \n");
	imprimir(Clientes);

	return 0;
}

void preencherVetor(struct cliente *Clientes)
{
	printf("---- Inserir informações dos clientes ----\n");
	int i;
	int agencia;
	char string[50],tipo;

	for(i = 0; i < MAX; i++)
	{
		printf("\nEntre com o nome do cliente %d (máximo de 50 caracteres) :\n", i+1);
		scanf("%50[^\n]",string);
		printf("\nEntre com o número da agência do cliente %d:\n",i+1);
		scanf("%d",&agencia);
		while ((tipo = getchar()) != '\n' && tipo != EOF);

		int h = 0;
		while(string[h] != '\0')
		{
			string[h] = tolower(string[h]);//o nome inteiro fica minúsculo para não causar problema na 
										   //ordenação
			h++;
		}

		strcpy(Clientes[i].nome,string);
		Clientes[i].agencia = agencia;

		Clientes[i].numeroConta = rand() % 100000;
		Clientes[i].tipo = rand() % 2 + 1;
	}
}

void imprimir(struct cliente *Clientes)
{
	int i;
	for(i = 0; i < MAX; i++)
	{
		printf("\nCliente %d | Nome: %s | Agencia: %d | Numero da conta: %d | Tipo da conta: ",i + 1, Clientes[i].nome, Clientes[i].agencia, Clientes[i].numeroConta);
		if(Clientes[i].tipo == 1)
			printf("Corrente.\n");
		else
			printf("Poupança.\n");
	}
}