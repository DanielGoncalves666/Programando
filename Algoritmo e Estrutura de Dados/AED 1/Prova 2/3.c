#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3.h"

#define MAX 20
#define QTD 15

struct deque
{
	char strings[MAX][QTD];
	int ini, cont;//ini indica a posicao do primeiroe elemento
};

Deque cria_deque()
{
	Deque d = (Deque) malloc(sizeof(struct deque));

	if(d != NULL)
	{
		d->ini = d->cont = 0;
	}

	return d;
}

int deque_vazio(Deque d)
{
	if(d->cont == 0)
		return 1;

	return 0;
}

int deque_cheio(Deque d)
{
	if(d->cont == MAX)
		return 1;

	return 0;
}

int insere_inicio(Deque d, char string[])
{
	if(deque_cheio(d))
		return 0;
	
	//decremento circular
	if(d->ini == 0)
		d->ini = MAX - 1;
	else
		d->ini--;

	strcpy(d->strings[d->ini],string);

	d->cont++;
	
	return 1;
}

int insere_final(Deque d, char string[])
{
	if(deque_cheio(d))
		return 0;

	int fim = (d->ini + d->cont) % MAX;

	strcpy(d->strings[fim],string);

	d->cont++;

	return 1;
}

int remove_inicio(Deque d, char string[])
{
	if(deque_vazio(d))
		return 0;

	strcpy(string,d->strings[d->ini]);

	//incremento circular
	d->ini = (d->ini + 1) % MAX;
	
	d->cont--;

	return 1;
}


int remove_final(Deque d, char string[])
{
	if(deque_vazio(d))
		return 0;

	d->cont--;
	int fim = (d->ini + d->cont) % MAX;

	strcpy(string,d->strings[fim]);

	return 1;
}
