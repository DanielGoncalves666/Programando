#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no
{
	int info;
	struct no *prox;
};

Lista cria_lista()
{
    //aloca o nó cabeçalho: 
    Lista cabe;
    cabe = (Lista) malloc(sizeof(struct no));

    //se a lista foi alocada com sucesso, seta para o estado vazio
    if(cabe != NULL)
    {
        cabe->prox = NULL;
        cabe->info = 0;//campo vago
    }

    return cabe;
}

int lista_vazia(Lista lst)
{
    if(lst->prox == NULL)
        return 1;
    
    return 0;
}

//0 para falha, 1 para sucesso
int remove_par(Lista lst, int *retorno)
{
	if(lista_vazia(lst))
		return 0;//lista vazia

	Lista aux = lst;
	Lista ultimo = NULL;

	while(aux->prox != NULL)
	{
		if(aux->prox->info % 2 == 0)
			ultimo = aux;
		
		aux = aux->prox;
	}

	if(ultimo == NULL)
		return 0;//nenhum par encontrado

	*retorno = ultimo->prox->info;

	Lista aux2 = ultimo->prox;//armzenamos o endereço do no a ser desalocado
    ultimo->prox = aux2->prox;//fazemos o no anterior apontar para o posterior
   
    free(aux2);

	return 1;
}