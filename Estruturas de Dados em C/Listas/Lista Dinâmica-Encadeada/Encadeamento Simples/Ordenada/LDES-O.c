#include<stdlib.h>
#include"LDES-O.h"

struct no
{
	int valor;
	struct no *prox;
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
Descrição: insere 'elem' na lista 'lst'
Saída: 0, se a inserção falhar
       1, se a inserção ocorrer com sucesso
*/
int insereOrd(Lista *lst, int elem)
{
	Lista novo = (Lista) malloc(sizeof(struct no));
	if(novo == NULL)
		return 0;
		
	novo->valor = elem;
	
	if(listaVazia(*lst) || elem <= (*lst)->valor)
	{
		// lista vazia ou o elemento a ser inserido é menor que o primeiro
		novo->prox = *lst;
		*lst = novo;
		
		return 1;
	}
	
	Lista aux = *lst;
	while(aux->prox != NULL && aux->prox->valor < elem)
		aux = aux->prox;
		
	novo->prox = aux->prox;
	aux->prox = novo;

	return 1;
}

/*
removeOrd
-----------
Entrada: ponteiro para tipo Lista
         inteiro a ser removido
Descrição: remove 'elem' da lista 'lst'
Saida: 0, se a remoção falhar
       1, em sucesso
*/
int removeOrd(Lista *lst, int elem)
{
	if(listaVazia(*lst) || (*lst)->valor < elem) // lista vazia ou elem menor que o primeiro
		return 0;
		
	Lista aux = *lst;
	
	if(aux->valor == elem)
	{
		*lst = aux->prox; // elem é o primeiro da lista
		free(aux);
		
		return 1;
	}
	
	// percorre até o final da lista ou até encontrar um elemento maior ou igual
	while(aux->prox != NULL && aux->prox->valor < elem)
		aux = aux->prox;
		
	if(aux->prox == NULL || aux->prox->valor > elem) // se o próximo elemento for maior que 'elem' ou se tiver chegado no fim da lista
		return 0;	
		
	Lista remover = aux->prox;
	aux->prox = remover->prox;
	free(remover);
	
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
		
	int i = 0;
	while(i < posicao)
	{
		lst = lst->prox;
		if(lst == NULL)
			return 0;
			
		i++;
	}
	
	*elem = lst->valor;	
		
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
	
	int i = 0;	
		
	// percorre até encontrar um elemento igual ou maior
	while(lst->valor < elem && lst->prox != NULL)
	{
		i++;
		lst = lst->prox;
	}
	
	if(lst->valor == elem)
	{
		*posicao = i;
		return 1;
	}
	
	return 0; // não encontrou o elemento
}

/*
removeElemPos
---------------
Entrada: ponteiro para tipo Lista
         inteiro, a posição do elemento à ser removido
         ponteiro para inteiro, indicando onde deve ser armazenado o elemento removido
Descrição: percorre a lista até a posição indicada e remove o elemento da lista
Saída: 0, em falha
       1, em sucesso
*/
int removeElemPos(Lista *lst, int posicao, int *elem)
{
	if(listaVazia(*lst))
		return 0;
	
	Lista aux = *lst;
	
	if(posicao == 0)
	{
		*lst = aux->prox;
		free(aux);
		
		return 1;	
	}
	
	int i = 1;
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




