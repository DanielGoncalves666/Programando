#include<stdlib.h>
#include"LDESNO-NO.h"

struct no
{
	int valor;
	struct no *prox;
};

/*
criaLista
----------
Entrada: nenhuma
Descrição: cria uma lista, alocando o nó cabeçalhaço e colocando ela em estado vazio
Saida: ponteiro para estrutura nó
*/
Lista criaLista()
{
	Lista no = (Lista) malloc(sizeof(struct no));
	if(no != NULL)
	{
		no->valor = 0;
		no->prox = NULL;
	}
	
	return no;
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
	if(lst->prox == NULL)
		return 1;
	else
		return 0;
}

// Função listaCheia não tem motivo para ser implementada já que o máximo de elementos da lista vai depender da memória disponível

/*
insereElem
-----------
Entrada: tipo Lista
         inteiro a ser inserido
Descrição: insere 'elem' na lista 'lst'
Saída: 0, se a inserção falhar
       1, se a inserção ocorrer com sucesso
*/
int insereElem(Lista lst, int elem)
{
	// insere o elemento sempre no começo da lista
	
	Lista aux = (Lista) malloc(sizeof(struct no));
	if(aux == NULL)
		return 0;
		
	lst->valor++;// indica a quantidade de elementos na lista
		
	aux->valor = elem;
	aux->prox = lst->prox;
	lst->prox = aux;

	return 1;
}

/*
removeElem
-----------
Entrada: tipo Lista
         inteiro a ser removido
Descrição: remove 'elem' da lista 'lst'
Saida: 0, se a remoção falhar
       1, em sucesso
*/
int removeElem(Lista lst, int elem)
{
	if(listaVazia(lst))
		return 0;
		
	Lista aux = lst;
	
	while(aux->prox != NULL && aux->prox->valor != elem)
		aux = aux->prox;
		
	if(aux->prox == NULL)
		return 0;	
		
	Lista remover = aux->prox;
	aux->prox = remover->prox;
	free(remover);
	
	lst->valor--; // decrementa a quantidade de elementos na lista
	
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
		
	Lista aux = lst->prox;	
		
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

/*
obterPosicaoElem
-----------------
Entrada: tipo Lista
         ponteiro para inteiro, indicando onde deve ser armazenado a posição do primeiro elemento igual a 'elem'
         inteiro indicando o elemento a ser procurado
Descrição: percorre a lista e retorna a posição do primeiro elemento 'elem'.
Saída: 0, em falha
       1, em sucesso
*/
int obterPosicaoElem(Lista lst, int *posicao, int elem)
{
	if(listaVazia(lst))
		return 0;
	
	Lista aux = lst->prox;
	
	int i = 0;				
	while(aux->valor != elem && aux->prox != NULL)
	{
		i++;
		aux = aux->prox;
	}
	
	if(aux->valor == elem)
	{
		*posicao = i;
		return 1;
	}
	
	return 0; // não encontrou o elemento
}

/*
removeElemPos
---------------
Entrada: tipo Lista
         inteiro, a posição do elemento à ser removido
         ponteiro para inteiro, indicando onde deve ser armazenado o elemento removido
Descrição: percorre a lista até a posição indicada e remove o elemento da lista
Saída: 0, em falha
       1, em sucesso
*/
int removeElemPos(Lista lst, int posicao, int *elem)
{
	if(listaVazia(lst))
		return 0;
	
	Lista aux = lst;

	int i = -1;
	while(aux->prox != NULL && i < posicao)
	{
		i++;
		aux = aux->prox;
	}
		
	if( aux->prox == NULL)
		return 0;
		
	Lista remover = aux->prox;
	aux->prox = remover->prox;
	*elem = remover->valor;
	free(remover);
	
	return 1;
}




