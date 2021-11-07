#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_3.h"

#define MAX 10

struct no
{
	int codigo;
	char nome[MAX];
	double preco;

	struct no *prox;
	struct no *ant;
};

int listaVazia(Produto lst) {
    if (lst == NULL) {
        return 1;
    }
    
	return 0;
}

int apaga_lista(Produto *lst) 
{
    if(listaVazia(*lst))
        return 0;
    
	Produto aux ;

    while( *lst != NULL){
        
		aux = *lst;
		*lst = (*lst)->prox;

		free(aux);
    }
	*lst = NULL;

    return 1;
}

int insere_produto(Produto *lst, int cod, char nome[], double reais)
{
	Produto Novo = (Produto) malloc(sizeof(struct no));
    if(Novo == NULL)
        return 0;

	Novo->codigo = cod;
	strcpy(Novo->nome,nome);
	Novo->preco = reais;

	if(listaVazia(*lst))
	{
		Novo->prox = NULL;
		Novo->ant = NULL;
		*lst = Novo;

		return 1;
	}
	else
	{
		Produto aux;

		while(aux->prox != NULL && cod < aux->codigo)
			aux = aux->prox;

		if(aux->prox == NULL)
		{
			Novo->prox = aux->prox;
			Novo->ant = aux;
			aux->prox = Novo;
		}
		else if(aux->ant == NULL)
		{
			Novo->prox = aux;
			Novo->ant = aux->ant;
			aux->ant = Novo;
		}
		else
		{
			Novo->prox = aux;
			Novo->ant = aux->ant;
			aux->ant->prox = Novo;
			aux->ant = Novo;
		}
	}

    return 1;
}