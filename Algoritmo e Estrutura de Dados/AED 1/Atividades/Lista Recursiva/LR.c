+#include <stdio.h>
#include <stdlib.h>
#include "LR.h"

struct no
{
	double info;
	struct no *prox;
};


Lista cria_lista()
{
	return NULL;
}

int lista_vazia(Lista lst)
{
	if(lst == NULL)
		return 1;

	return 0;
}

int insere_ord(Lista *lst, double elem)
{
	//lista vazia ou elem a ser inserido menor que o primeiro
	if(lista_vazia(*lst) || elem < (*lst)->info)
	{
		Lista novo = (Lista) malloc(sizeof(struct no));
		if(novo == NULL)
			return 0;

		novo->info = elem;
		novo->prox = *lst;
		*lst = novo;//no caso de lst apontar para um nó, essa operação altera o endereço armazenado em prox diretamente

		return 1;
	}
	else
	{
		return insere_ord(&((*lst)->prox),elem);
	}
}

int remove_ord(Lista *lst, double elem)
{
	//lista vazia ou se o elemento não existir
	if(lista_vazia(*lst) || elem < (*lst)->info)
	{
		return 0;
	}
	else
	{
		//elemento igual ao no de cabeça
		if(elem == (*lst)->info)
		{
			Lista aux = *lst;
			*lst = aux->prox;
			free(aux);

			return 1;
		}
		else
		{
			return remove_ord(&((*lst)->prox),elem);
		}
	}
}

int obtem_elem(Lista lst, int indice, double *elem)
{
	//se a lista estiver vazia ou se o indice passado for menor que 1
	if(lista_vazia(lst) || indice < 1)
	{
		return 0;
	}
	else
	{
		if(indice == 1)
		{
			*elem = lst->info;
			
			return 1;
		}
		else
		{
			return obtem_elem(lst->prox,indice - 1, elem);
		}
	}
}

//a função vai removendo o primeiro elemento continuamente
int apagar_lista(Lista *lst)
{
	double elem;

	if(lista_vazia(*lst))
		return 1;
	else
	{
		//falha na reinicialização
		if(!obtem_elem(*lst,1,&elem))
			return 0;
		else if(!remove_ord(lst,elem))
			return 0;
		else
			return apagar_lista(lst);
	}
}
