#include<stdlib.h>
#include"LDEED-O.h"

struct no
{
	int valor;
	struct no * ant;
	struct no * prox;
};

/*
criaLista
----------
Entrada: nenhuma
Descrição: cria uma lista e coloca ela no estado vazio (simplesmente retorna NULL)
Saida: ponteiro para estrutura nó
*/
Lista criaLista()
{
	return NULL;
}

/*
listaVazia
------------
Entrada: tipo Lista
Descrição: verificar se Lista passada está vazia
Saída: 0, se há elementos
	   1, se a lista está vazia
*/
int listaVazia(Lista lst)
{
	if(lst == NULL)
		return 1;
	else
		return 0;
}

// Função listaCheia não tem motivo para ser implementada já que o máximo de elementos da lista vai depender da memória disponível

/*
insereOrd
-----------
Entrada: ponteiro para tipo Lista
         inteiro a ser inserido
Descrição: insere 'elem' na lista
Saída: 0, se a inserção falhar
       1, se a inserção ocorrer com sucesso
*/
int insereOrd(Lista *lst, int elem)
{
	Lista novo = (Lista) malloc(sizeof(struct no));
	if(novo == NULL)
		return 0;
		
	novo->valor = elem;
	
	if(listaVazia(*lst))
	{
		novo->prox = NULL;
		novo->ant = NULL;
		
		*lst = novo;
	}
	else
	{
		Lista aux = *lst;	
			
		while(aux->prox != NULL && aux->valor < elem)
			aux = aux->prox;
			
		if(aux->valor >= elem)
		{
			// insere antes de aux
			novo->prox = aux;
			novo->ant = aux->ant;
			
			aux->ant = novo;
			
			if(*lst != aux)// caso a inserção não seja no inicio da fila
				aux->ant->prox = novo;
			else
				*lst = novo;
		}	
		else
		{
			// insere depois de aux (só ocorre para inserção no fim da lista)
			novo->prox = NULL;
			novo->ant = aux;
			aux->prox = novo;
		}
	}


	return 1;
}

/*
removeOrd
-----------
Entrada: ponteiro para tipo Lista
		 inteiro, contendo o elemento a ser removido
Descrição: remove 'elem' da lista se ele existir
Saida: 0, se a remoção falhar
       1, em sucesso
*/
int removeOrd(Lista *lst, int elem)
{
	if(listaVazia(*lst))
		return 0;
		
	Lista aux = *lst;
	
	while(aux->prox != NULL && aux->valor < elem)
		aux = aux->prox;
		
	if(aux->valor != elem)
		return 0;
	
	if(aux->ant != NULL) // se não for o primeiro da lista
		aux->ant->prox = aux->prox;
	
	if(aux->prox != NULL) // se não for o último da lista
		aux->prox->ant = aux->ant;
	
	if(aux == *lst) // se for o primeiro da lista
		*lst = aux->prox;
	
	free(aux);
	
	return 1;
}

/*
obterElemPosicao
------------------
Entrada: tipo Lista
         inteiro indicando a posição a ser retornada
         ponteiro para inteiro, indicando onde deve ser armazenado o valor da posição
Descrição: percorre 'lst' e armazena o conteúdo da (posicao + 1)-ésima entrada em 'elem'
Saída: 0, em falha
       1, em sucesso
*/
int obterElemPosicao(Lista lst, int posicao, int *elem)
{
	if(listaVazia(lst) || posicao < 0)
		return 0;
		
	Lista aux = lst;	
		
	int i = 0;
	while(i < posicao)
	{
		aux = aux->prox;
		if(aux == NULL)
			return 0;
			
		i++;
	}
	
	*elem = aux->valor;	
		
	return 1;
}
