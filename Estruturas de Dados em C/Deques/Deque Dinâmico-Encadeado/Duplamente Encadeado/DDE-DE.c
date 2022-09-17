#include<stdlib.h>
#include"DDE-DE.h"

struct no
{
	int valor;
	struct no * ant;
	struct no * prox;
};

struct deque
{
	struct no *ini;
	struct no *fim;
};


/*
criaDeque
----------
Entrada: nenhuma
Descrição: cria um deque e coloca ele no estado vazio
Saida: ponteiro para estrutura deque
*/
Deque criaDeque()
{
	Deque novo = (Deque) malloc(sizeof(struct deque));
	if(novo != NULL)
		novo->ini = novo->fim = NULL;
		
	return novo;
}

/*
dequeVazio
------------
Entrada: tipo Deque
Descrição: verificar se o deque passado está vazia
Saída: 0, se há elementos
	   1, se o deque está vazia
*/
int dequeVazio(Deque d)
{
	if(d->ini == NULL)
		return 1;
	else
		return 0;
}

// Função dequeCheio não tem motivo para ser implementada já que o máximo de elementos da deque vai depender da memória disponível

/*
insereInicio
----------
Entrada: Tipo deque
		 inteiro a ser incluído no deque.
Descrição: Adiciona 'elem' no inicio de d
Saída: 0, se a inserção falhar
       1, se suceder
*/
int insereInicio(Deque d, int elem)
{
	struct no *novo = (struct no *) malloc(sizeof(struct no));
	if(novo == NULL)
		return 0;
		
	novo->valor = elem;
	novo->ant = NULL;

	if(dequeVazio(d))
	{
		d->fim = novo;
		novo->prox = NULL;
	}
	else
	{
		(d->ini)->ant = novo;
		novo->prox = d->ini;
	}
	
	d->ini = novo;
	
	return 1;
}


/*
insereFinal
----------
Entrada: Tipo deque
		 inteiro a ser incluído no deque.
Descrição: Adiciona 'elem' no final de d
Saída: 0, se a inserção falhar
       1, se suceder
*/
int insereFinal(Deque d, int elem)
{
	struct no *novo = (struct no *) malloc(sizeof(struct no));
	if(novo == NULL)
		return 0;
		
	novo->valor = elem;
	novo->prox = NULL;

	if(dequeVazio(d))
	{
		d->ini = novo;
		novo->ant = NULL;
	}
	else
	{
		(d->fim)->prox = novo;
		novo->ant = d->fim;
	}
	
	d->fim = novo;
	
	return 1;
}

/*
removeInicio
-------------
Entrada: Tipo deque
         ponteiro para inteiro, indicando onde o valor removido deve ser armazenado
Descrição: remove o elemento no começo do deque
Saída: 0, se a remoção falhar
       1, se a remoção suceder
*/
int removeInicio(Deque d, int *elem)
{
	if(dequeVazio(d))
		return 0;
		
	struct no *aux = d->ini;
	*elem = aux->valor;
	
	if(d->ini == d->fim)
		d->fim = NULL;	
	else
	    aux->prox->ant = NULL;
	
	d->ini = aux->prox;
	free(aux);
	
	return 1;
}

/*
removeFinal
-------------
Entrada: Tipo deque
         ponteiro para inteiro, indicando onde o valor removido deve ser armazenado
Descrição: remove o elemento no final do deque
Saída: 0, se a remoção falhar
       1, se a remoção suceder
*/
int removeFinal(Deque d, int *elem)
{
	if(dequeVazio(d))
		return 0;
		
	struct no *aux = d->fim;
	*elem = aux->valor;
	
	if(d->ini == d->fim)
		d->ini = NULL;	
	else
	 	aux->ant->prox = NULL;
	
	d->fim = aux->ant;
	free(aux);
	
	return 1;
}

