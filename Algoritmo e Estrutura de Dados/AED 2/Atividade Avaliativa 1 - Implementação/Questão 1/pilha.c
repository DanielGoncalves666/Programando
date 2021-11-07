#include <stdlib.h>
#include "header.h"

struct no
{
	int dir;
	int esq;
	struct no *prox;
};

/*
cria_pilha
-----------
Entrada: nenhuma
Saída: NULL
Funionalidade: retorna uma pilha no estado vazio;
*/
Pilha cria_pilha()
{
	return NULL;
}

/*
pilha_vazia
------------
Entrada: Pilha.
Saída: 0, se a pilha não estiver vazia, 1, se a pilha estiver vazia.
Funcionaldiade: Determina se a pilha passada comoa argumenta está vazia ou não.
*/
int pilha_vazia(Pilha p)
{
	if(p == NULL)
		return 1;

	return 0;
}

/*
empilha
--------
Entrada: Ponteiro para Pilha e dois inteiros.
Saída: 0, se a operação resultar em falha, 1, se a operação resultar em sucesso.
Funcionalidade: Empilha os valores passados pelos parâmetros 'esq' e 'dir' no topo da pilha 'p'.
*/
int empilha(Pilha *p, int esq, int dir)
{
	Pilha no = (Pilha) malloc(sizeof(struct no));

	if(no == NULL)
		return 0;//falha na alocação

	no->esq = esq;
	no->dir = dir;
	no->prox = *p;
	*p = no;

	return 1;
}

/*
desempilha
----------
Entrada: Ponteiro para Pilha e ponteiros para dois inteiros, os quais receberão os valores desempilhados
Saída: 0, se a operação resultar em falha, 1, se a operação resultar em sucesso.
Funcionalidade: Desempilha os valores no topo da pilha 'p' e os atribue aos inteiros apontados por 'esq' e 'dir'.
*/
int desempilha(Pilha *p, int *esq, int *dir)
{
	if(pilha_vazia(*p))
		return 0;
	
	Pilha aux = *p;

	*esq = aux->esq;
	*dir = aux->dir;
	*p = aux->prox;
	free(aux);

	return 1;
}

/*
le_topo
--------
Entrada: Uma Pilha e dois ponteiros para inteiro, os quais receberão os valores no topo da pilha.
Saída: 0, se a operação resultar em falha, 1, se a operação resultar em sucesso.
Funcionalidade: Armazena no inteiro apontado por 'numero' o valor do topo da lista.
*/
int le_topo(Pilha p, int *esq, int *dir)
{
	if(pilha_vazia(p))
		return 0;
	
	*esq = p->esq;
	*dir = p->dir;

	return 1;
}

/*
tamanho_pilha
-------------
Entrada: Pilha.
Saída: Tamanho da pilha.
Funcionalidade: Calcula o tamanho da pilha.
*/
int tamanho_pilha(Pilha p)
{
	int tamanho = 0;

	while(p != NULL)
	{
		tamanho++;
		p = p->prox;
	}

	return tamanho;
}
