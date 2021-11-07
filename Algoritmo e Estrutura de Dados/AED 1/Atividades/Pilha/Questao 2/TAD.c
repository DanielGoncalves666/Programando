#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"

struct no
{
	char nome[MAX];
	struct no *prox;
};

Pilha cria_pilha()
{
	return NULL;
}

int pilha_vazia(Pilha plt)
{
	if(plt == NULL)
		return 1;

	return 0;
}

//não existe lista cheia

int push(Pilha *plt, char nome[MAX])
{
	Pilha novo = (Pilha) malloc(sizeof(struct no));

	if(novo == NULL)
		return 0;

	strcpy(novo->nome,nome);
	novo->prox = *plt;
	*plt = novo;

	return 1;
}

int pop(Pilha *plt, char nome[MAX])
{
	if(pilha_vazia(*plt))
		return 0;
	
	Pilha aux = *plt;

	nome = (*plt)->nome;
	*plt = aux->prox;
	free(aux);

	return 1;
}

int le_topo(Pilha plt, char nome[MAX])
{
	if(pilha_vazia(plt))
		return 0;

	nome = plt->nome;

	return 1;
}

//libera_pilha e esvazia_pilha são a mesma coisa neste caso
int esvaziar_pilha(Pilha *plt)
{
	if(pilha_vazia(*plt))
		return 0;

	Pilha aux;

	while(*plt != NULL)
	{
		aux = *plt;
		*plt = aux->prox;
		free(aux);
	}
	//*plt termina apontando para NULL

	return 1;
}

int tamanho_pilha(Pilha plt)
{
	if(pilha_vazia(plt))
		return 0;

	int N = 1;

	while(plt->prox != NULL)
	{
		N++;
		plt = plt->prox;
	}

	return N;		
}