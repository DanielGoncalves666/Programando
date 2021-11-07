#include <stdlib.h>
#include "lista.h"
#include "palavra.h"

struct no
{
	Palavra item;
	struct no *prox;
};



// ------------------------------

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

// 0 em fracasso, 1 em sucesso
int insere_ord(Lista *lst, Palavra nova)
{
	//lista vazia ou palavra a ser inserida for menor que a primeira
	if(lista_vazia(*lst) || comparar(nova,(*lst)->item) == 1)
	{
		Lista novo = (Lista) malloc(sizeof(struct no));
		if(novo == NULL)
			return 0;

		novo->item = nova;
		novo->prox = *lst;
		*lst = novo;

		return 1;
	}
	else
	{
		return insere_ord(&((*lst)->prox),nova);
	}
}

// 0, em fracasso, 1, em sucesso
int remove_ord(Lista *lst, Palavra procurada)
{
	//lista vazia ou se o elemento não existir (pois ele é menor que o menor elemento da lista)
	if(lista_vazia(*lst) || comparar(procurada,(*lst)->item) == 1)
	{
		return 0;
	}
	else
	{
		//elemento igual ao no de cabeça
		if(comparar(procurada, (*lst)->item) == 0)
		{
			Lista aux = *lst;
			*lst = aux->prox;
			free(aux);

			return 1;
		}
		else
		{
			return remove_ord(&((*lst)->prox),procurada);
		}
	}
}

Palavra *consulta_lista(Lista lst, Palavra procurada)
{
	//se a lista estiver vazia ou se o elemento procurado for menor que o primeiro da lista
	if(lista_vazia(lst) || comparar(procurada, lst->item) == 1)
	{
		return NULL;
	}
	else
	{
		if(comparar(procurada,lst->item) == 0)
		{
			return &(lst->item);
		}
		else
		{
			return consulta_lista(lst->prox,procurada);
		}
	}
}