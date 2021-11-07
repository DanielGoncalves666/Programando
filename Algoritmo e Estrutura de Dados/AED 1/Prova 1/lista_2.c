#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_2.h"

#define QTD 20 //quantiade maxima de strings foi setada aleatoriamente
#define MAX 60

struct lista
{
	char strings[QTD][MAX];
	int FIM;
};

ListaString cria_lista()
{
	ListaString lst = (ListaString) malloc(sizeof(struct lista));

	if(lst != NULL)
		lst->FIM = 0;//seta a lista para o estado vazio

	return lst;
}

int lista_vazia(ListaString lst)
{
	if(lst->FIM == 0)
		return 1;

	return 0;
}

int intercala(ListaString lst, ListaString lst2, ListaString *lst3){

    if(lista_vazia(lst) == 1)
	{
		*lst3 = lst2;
        return 1;
	}
	else if(lista_vazia(lst2) == 1)
    {
		*lst3 = lst;
        return 1;
	}

    *lst3 = cria_lista();
    if(lst3 == NULL)
	{
		return 0;
	}

	if(lst->FIM + lst2->FIM > QTD)
	{
		//a intercalação superaria o tamanho maximo de uma lista
		return -1;//-1 para reportar esse tipo especifico de erro
	}

	int i,h,j;
	for(i = 0, h = 0, j = 0; i < lst->FIM || h < lst2->FIM;)
	{
		if(i < lst->FIM)
		{
			strcpy((*lst3)->strings[j], lst->strings[i]);
			i++;
			j++;
		}
		
		if(h < lst2->FIM)
		{
			strcpy((*lst3)->strings[j], lst2->strings[h]);
			h++;
			j++;
		}
	}

    return 1;
}