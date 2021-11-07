#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"

#define max 20

struct fila
{
	char no[max][tam];
	int ini, fim;
};

Fila cria_fila()
{
	Fila novo = (Fila) malloc(sizeof(struct fila));

	if(novo != NULL)
	{
		novo->ini = 0;
		novo->fim = 0;
	}

	return novo;
}

void liberar(Fila *f)
{
	free(*f);
	f = NULL;
}

int fila_vazia(Fila f)
{
	if(f->ini == f->fim)
		return 1;
	else
		return 0;
}

int fila_cheia(Fila f)
{
	//fim indica a proxima posição n ocupada
	if(f->ini == (f->fim + 1)%max)
		return 1;
	else
		return 0;
}

int inseri_fim(Fila f, char elem[])
{
	if(fila_cheia(f))
		return 0;

	strcpy(f->no[f->fim],elem);
	f->fim = (f->fim + 1) % max ;

	return 1;
}

int remove_ini(Fila f, char elem[])
{
	if(fila_vazia(f))
		return 0;

	strcpy(elem, f->no[f->ini]);
	f->ini = (f->ini + 1)%max;

	return 1;
}