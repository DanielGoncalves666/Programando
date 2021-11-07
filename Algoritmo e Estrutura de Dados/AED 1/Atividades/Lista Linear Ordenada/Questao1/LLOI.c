//lista linear ordenada de inteiros

#include <stdio.h>
#include <stdlib.h>
#include "../include/LLOI.h"

struct no
{
	int num;
	struct no *prox;
};

/*
inicializar_lista
-------------------
Entrada: nenhuma
Processo: Inicializa uma lista vazia
Saida: endereço NULL.
*/
Lista inicializar_lista()
{
	return NULL;
}

/*
lista_vazia
------------
Entrada: tipo Lista
Processo: verifica se a lista está vazia
Saída: 0, se não vazia, 1, se vazia
*/
int lista_vazia(Lista lst)
{
	if(lst == NULL)
		return 1;

	return 0;
}

/*
Não há a necessidade de se criar uma função para verificar se a lista está cheia.
*/


/*
insere_ord
-----------
Entrada: ponteiro para o tipo Lista.
Processo: aloca, inicializa e insere ordenamente (decrescente) um elemento na lista passada
Saída: 0, em fracasso, 1, em sucesso
*/
int insere_ord(Lista *lst, int elem)
{
	Lista N = (Lista) malloc(sizeof(struct no));

	//falha na alocação; memória cheia
	if(N == NULL)
		return 0;
	
	N->num = elem;

	//lista vazia ou elemento maior ou igual que o primeiro.
	if(lista_vazia(*lst) || elem >= (*lst)->num)
	{
		N->prox = *lst;// N aponta para a posição que a cabeça da lista apontava
		*lst = N;//a cabeça da lista agora aponta para N

		return 1;
	}

	//resto da lista
	Lista aux = *lst;
	while(aux->prox != NULL && aux->prox->num > elem)
	{
		aux = aux->prox;
	}
	
	N->prox = aux->prox;//o ano agora aponta pro elemento posterior
	aux->prox = N;//aux deixa de apontar para o elemento superior e passa a apontar para N

	return 1;
}

/*
remove_ord
-----------
Entrada;
Processo:
Saída:
*/
int remove_ord(Lista *lst, int elem)
{
	//lista vazia ou elemento menor que o primeiro
	if(lista_vazia(*lst) || elem > (*lst)->num)
		return 0;

	Lista aux = *lst;//ponteiro para o primeiro nó

	//elemento a ser removido no começo da lista
	if(elem == (*lst)->num)
	{
		*lst = aux->prox;
		free(aux); 
		return 1; 
	}

	//percorre a lista
	while(aux->prox != NULL && aux->prox->num > elem)
		aux = aux->prox;

	if(aux->prox == NULL || aux->prox->num < elem)
		return 0;

	Lista aux2 = aux->prox;
	aux->prox = aux2->prox;
	free(aux2);

	return 1;
}

int get_pos(Lista lst, int posicao, int *elemento)
{
	if(lista_vazia(lst) || posicao < 0)
		return 0;

	int i = 0;
	while(i < posicao)
	{
		lst = lst->prox;
		if(lst == NULL)
			return 0;

		i++;
	}

	*elemento = lst->num;

	return 1;
}

int remove_pos(Lista *lst, int posicao, int *elemento)
{
	int retorno = get_pos(*lst,posicao, elemento);
	if(retorno == 0)
		return 0;

	retorno = remove_ord(lst, *elemento);
	if(retorno == 0)
		return 0;

	return 1;
}