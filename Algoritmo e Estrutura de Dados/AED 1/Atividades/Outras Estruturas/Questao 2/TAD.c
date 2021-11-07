#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"

#define max 20

struct fila
{
	int no[max];
	int ini, cont;
};

Fila cria_fila()
{
	Fila novo = (Fila) malloc(sizeof(struct fila));

	if(novo != NULL)
	{
		novo->ini = 0;//primeira posicao preenchida
		novo->cont = 0;
	}

	return novo;
}

void liberar(Fila *f)
{
	free(*f);
	*f = NULL;
}

int fila_vazia(Fila f)
{
	if(f->cont == 0)
		return 1;
	else
		return 0;
}

int fila_cheia(Fila f)
{
	if(f->cont == max)
		return 1;
	else
		return 0;
}

int inseri_final(Fila f, int elem)
{
	if(fila_cheia(f))
		return 0;

	int fim = (f->ini + f->cont) % max;	

	f->no[fim] = elem;

	f->cont++;

	return 1;
}

int inseri_inicio(Fila f, int elem)
{
	if(fila_cheia(f))
		return 0;

	f->no[f->ini] = elem;

	if(f->ini == 0)
		f->ini = max - 1;
	else
		f->ini--;

	f->cont++;

	return 1;
}


int remove_ini(Fila f, int *elem)
{
	if(fila_vazia(f))
		return 0;

	*elem = f->no[f->ini];

	f->ini = (f->ini + 1) % max;
	f->cont--; 

	return 1;
}

int remove_final(Fila f, int *elem)
{
	if(fila_vazia(f))
		return 0;

	int fim = (f->ini + f->cont) % max;	

	*elem = f->no[fim];

	f->cont--;
	return 1;
}
