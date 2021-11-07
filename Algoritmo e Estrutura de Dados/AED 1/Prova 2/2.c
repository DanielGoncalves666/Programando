#include <stdio.h>
#include <stdlib.h>
#include "2.h"

struct fila
{
	struct investimentos *ini;
	struct investimentos *fim;
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

//fila cheia não se aplica a esse tipo de implementação

int insere_fim(Fila f, int codigo, double valor, float percentual)
{
	struct investimentos *novo;
	novo = (struct investimentos *) malloc(sizeof(struct investimentos));
	if(novo == NULL)
		return 0;

	novo->codigo = codigo;
	novo->valor = valor;
	novo->percentual = percentual;
	novo->prox = NULL;

	if(fila_vazia(f))
		f->ini = novo;
	else
		(f->fim)->prox = novo;//penultimo no apos a adição

	f->fim = novo;

	return 1;
}

int remove_ini(Fila f, struct investimentos *out)
{
	if(fila_vazia(f))
		return 0;

	struct investimentos *aux = f->ini;

	out->codigo = aux->codigo;
	out->valor = aux->valor;
	out->percentual = aux->percentual;

	if(f->ini == f->fim)
		f->fim = NULL;

	f->ini = aux->prox;

	free(aux);
	return 1;
}