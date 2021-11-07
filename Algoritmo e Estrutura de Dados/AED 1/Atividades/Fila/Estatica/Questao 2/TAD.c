#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"

#define max 20

struct fila
{
	int matricula[max];
	char nome[max][tam];
	int faltas[max];
	float media[max];
	int ini, cont;
};

Fila cria_fila()
{
	Fila novo = (Fila) malloc(sizeof(struct fila));

	if(novo != NULL)
	{
		novo->ini = 0;
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
	//fim indica a proxima posição n ocupada
	if(f->cont == max)
		return 1;
	else
		return 0;
}

int inseri_fim(Fila f, int mat, char elem[], int falt, float med)
{
	if(fila_cheia(f))
		return 0;

	int fim = (f->ini + f->cont) % max;	

	f->matricula[fim] = mat;
	strcpy(f->nome[fim],elem);
	f->faltas[fim] = falt;
	f->media[fim] = med;

	f->cont ++;

	return 1;
}

int remove_ini(Fila f, int *mat, char elem[], int *falt, float *med)
{
	if(fila_vazia(f))
		return 0;

	*mat = f->matricula[f->ini];
	strcpy(elem, f->nome[f->ini]);
	*falt = f->faltas[f->ini];
	*med = f->media[f->ini];

	f->ini = (f->ini + 1)%max;
	f->cont--;

	return 1;
}