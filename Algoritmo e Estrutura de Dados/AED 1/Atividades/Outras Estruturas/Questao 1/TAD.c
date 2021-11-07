#include<stdio.h>
#include<stdlib.h>
#include"TAD.h"

struct no
{
	int num;
	struct no *prox;
};

struct fila
{
	struct no *ini;
	struct no *fim;
};

Fila cria_fila()
{
	Fila novo = malloc(sizeof(struct no));

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

int insere(Fila f, int elem){
    struct no *novo;
    novo = (struct no *) malloc(sizeof(struct no));

    if(novo == NULL) 
		return 0;

    novo->num = elem;

	if(fila_vazia(f))
	{
		novo->prox = NULL;
		f->ini = novo;
		f->fim = novo;

		return 1;
	}

	if(elem <= f->ini->num)
	{
		novo->prox = NULL;
		f->ini = novo;

		return 1;
	}

    struct no* aux = f->ini;

    while(aux->prox != NULL && elem < aux->prox->num)
        aux = aux->prox;

	if(aux->prox == NULL)//insercao no fim
		f->fim = novo;
		
    novo->prox = aux->prox;
    aux->prox = novo;
    return 1;
}

int remove_ini(Fila f, int *elem)
{
	if(fila_vazia(f))
		return 0;

	struct no *aux = f->ini;	
	*elem = aux->num;

	if(f->ini == f->fim)
		f->fim = f->ini = NULL;
	else
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