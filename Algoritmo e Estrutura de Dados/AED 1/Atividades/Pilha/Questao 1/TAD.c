#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"

#define QTD 20

struct pilha
{
	long int matricula[QTD];
	char nome[QTD][MAX];
	char setor[QTD];
	float salario[QTD];
	int topo;//ultima posicao ocupada
};

Pilha cria_pilha()
{
	Pilha plt = (Pilha) malloc(sizeof(struct pilha));
	if(plt != NULL)
		plt->topo = -1;

	return plt;
}

int pilha_vazia(Pilha plt)
{
	if(plt->topo == -1)
		return 1;

	return 0;
}

int pilha_cheia(Pilha plt)
{
	if(plt->topo == QTD - 1)
		return 1;

	return 0;
}

//complexidade constante
int push(Pilha plt, long int matri, char nom[MAX], char set, float sal)
{
	if(plt == NULL || pilha_cheia(plt))
		return 0;

	plt->topo++;
	int i = plt->topo;

	plt->matricula[i] = matri;
	strcpy(plt->nome[i],nom);
	plt->setor[i] = set;
	plt->salario[i] = sal;

	return 1;
}

int pop(Pilha plt, long int *matri, char nom[MAX], char *set, float *sal)
{
	if(plt == NULL || pilha_vazia(plt))
		return 0;

	int i = plt->topo;

	*matri = plt->matricula[i];
	strcpy(nom, plt->nome[i]);
	*set = plt->setor[i];
	*sal = plt->salario[i];

	plt->topo--;

	return 1;
}

int get_topo(Pilha plt, long int *matri, char nom[MAX], char *set, float *sal)
{
	if(plt == NULL || pilha_vazia(plt))
		return 0;

	int i = plt->topo;

	*matri = plt->matricula[i];
	strcpy(nom, plt->nome[i]);
	*set = plt->setor[i];
	*sal = plt->salario[i];

	return 1;
}

int libera_pilha(Pilha *plt)
{
	if(*plt == NULL)
		return 0;

	free(plt);
	plt = NULL;

	return 1;
}

int esvazia_pilha(Pilha plt)
{
	if(plt == NULL)
		return 0;
	
	plt->topo = -1;

	return 1;
}

int tamanho_pilha(Pilha plt, int *tam)
{
	if(plt == NULL)
		return 0;

	*tam = plt->topo + 1;

	return 1;
}