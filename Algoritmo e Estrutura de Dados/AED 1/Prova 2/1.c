#include <stdio.h>
#include "1.h"

#define QTD 100

struct pilha
{
	char vet[QTD];
	
	int topo;
};

Pilha cria_pilha()
{
	Pilha p = (Pilha) malloc(sizeof(struct pilha));
	if(p != NULL)
		p->topo = -1;

	return p;
}

int pilha_vazia(Pilha p)
{
	if(p->topo == -1)
		return 1;

	return 0;
}

//a função push precisa da pilha_cheia
int pilha_cheia(Pilha p)
{
	if(p->topo == QTD - 1)
		return 1;

	return 0;
}

int push(Pilha p, char c)
{
	if(pilha_cheia(p))
		return 0;

	p->topo++;
	p->vet[p->topo] = c;

	return 1;
}

int pop(Pilha p, char *c)
{
	if(pilha_vazia(p))
		return 0;

	*c = p->vet[p->topo];
	p->topo--;

	return 1;
}