#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"TAD.h"

struct no
{
	char nome[tam];
	int volume;
	float preco;
	struct no *prox;
};

struct fila
{
	struct no *ini;
	struct no *fim;
};

Fila cria_fila()
{
	Fila novo = malloc(sizeof(struct fila));

	if(novo != NULL)
	{
		novo->ini = NULL;
		novo->fim = NULL;
	}

	return novo;
}

int fila_vazia(Fila f)
{
	if(f->ini == NULL)
		return 1;
	else
		return 0;
}

int insere_fim(Fila f, int volume, char nome[], float preco)
{
	struct no *novo;
	novo = (struct no *) malloc(sizeof(struct no));
	if(novo == NULL)
		return 0;

	novo->volume = volume;
	strcpy(novo->nome,nome);
	novo->preco = preco;
	novo->prox = NULL;

	if(fila_vazia(f))
		f->ini = novo;
	else
		(f->fim)->prox = novo;//penultimo no apos a adição

	f->fim = novo;

	return 1;
}

int remove_ini(Fila f, int *volume, char nome[], float *preco)
{
	if(fila_vazia(f))
		return 0;

	struct no *aux = f->ini;	
	*volume = aux->volume;
	strcpy(nome,aux->nome);
	*preco = aux->preco;

	if(f->ini == f->fim)
		f->fim = NULL;

	f->ini = aux->prox;

	free(aux);
	return 1;
}

void apaga_fila(Fila *f)
{
	struct no *aux;
	while((*f)->ini != NULL)
	{
		aux = (*f)->ini;
		(*f)->ini = aux->prox;
		free(aux);
	}

	free(*f);
	*f = NULL;
}

int esvazia_fila(Fila f)
{
	if(f == NULL)
		return 0;

	struct no *aux;
	while(f->ini != NULL)
	{
		aux = f->ini;
		f->ini = aux->prox;
		free(aux);
	}

	f->ini = NULL;
	f->fim = NULL;

	return 1;
}
