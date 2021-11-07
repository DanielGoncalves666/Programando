#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"

#define MAX 20//tamanho

struct no
{
	int tipo;
	union {
		int i_int;
		char i_char;
	}info;

	struct no *prox;
};

Lista criar_lista()
{
	return NULL;
}

int lista_vazia(Lista lst)
{
	if(lst == NULL)
		return 1;
	else
		return 0;
}

//tipo - 1 para inteiro, 0 para char
//caracteres são passados como inteiros, convertidos implicitamente
int insere_elem (Lista *lst, int elem, int tipo){
	
	Lista N = (Lista) malloc(sizeof(struct no));
	if (N == NULL)
		return 0;// Falha: nó não alocado
	
	if(tipo == 0)
	{
		N->tipo = 0;
		N->info.i_char = (char) elem;
	}else if(tipo == 1)
	{
		N->tipo = 1;
		N->info.i_int = elem;
	}
	else
		return 0;
	
	N->prox = *lst; // Aponta para o 1º nó atual da lista
	
	*lst = N; // Faz a lista apontar para o novo nó
	return 1;
}


int remove_elem (Lista *lst, int elem, int tipo) {
	
	if (lista_vazia(lst) == 1)
		return 0; // Falha
	
	Lista aux = *lst; // Ponteiro auxiliar para o 1o nó
	
	if(elem == (*lst)->info.i_int && (*lst)->tipo == 1) {
		*lst = aux->prox; // Lista aponta para o 2o nó
		free(aux); // Libera memória alocada
		return 1; 
	}

	if(elem == (*lst)->info.i_char && (*lst)->tipo == 0) {
		*lst = aux->prox; // Lista aponta para o 2o nó
		free(aux); // Libera memória alocada
		return 1; 
	}

	// Percorrimento até achar o elem ou final de lista
	if(tipo == 0)
	{
		while(aux->prox != NULL)
		{
			if(aux->prox->tipo == 1)
			{
				aux = aux->prox;
				continue;
			}

			if(aux->prox->info.i_char == elem)
				break;

			aux = aux->prox;
		}
	}
	else
	{
		while(aux->prox != NULL)
		{
			if(aux->prox->tipo == 0)
			{
				aux = aux->prox;
				continue;
			}

			if(aux->prox->info.i_int == elem)
				break;

			aux = aux->prox;
		}
	}
	
	if (aux->prox == NULL) // Trata final de lista
		return 0; // Falha

	Lista aux2 = aux->prox; // Aponta nó a ser removido
	aux->prox = aux2->prox; // Retira nó da lista
	free(aux2); // Libera memória alocada
	
	return 1;
}