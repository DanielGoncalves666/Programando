#include<stdlib.h>
#include"LDEC-NO.h"

struct no
{
	int valor;
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
insereFinal
-----------
Entrada: ponteiro para tipo Lista
         inteiro a ser inserido
Descrição: insere 'elem' no final da lista 'lst'
Saída: 0, se a inserção falhar
       1, se a inserção ocorrer com sucesso
*/
int insereFinal(Lista *lst, int elem)
{
	Lista novo = (Lista) malloc(sizeof(struct no));
	if(novo == NULL)
		return 0;
	
	novo->valor = elem;
	
	if(listaVazia(*lst))
		novo->prox = novo; // aponta para si mesmo
	else
	{
		novo->prox = (*lst)->prox;
		(*lst)->prox = novo;
	}
	
	*lst = novo;	
	
	return 1;
}

/*
insereInicio
-----------
Entrada: ponteiro para tipo Lista
         inteiro a ser inserido
Descrição: insere 'elem' no inicio da lista 'lst'
Saída: 0, se a inserção falhar
       1, se a inserção ocorrer com sucesso
*/
int insereInicio(Lista *lst, int elem)
{
	Lista novo = (Lista) malloc(sizeof(struct no));
	if(novo == NULL)
		return 0;
	
	novo->valor = elem;
	
	if(listaVazia(*lst))
	{
		novo->prox = novo; // aponta para si mesmo
		*lst = novo;
	}
	else
	{
		novo->prox = (*lst)->prox;
		(*lst)->prox = novo;
	}
	
	return 1;
}


/*
removeInicio
-----------
Entrada: ponteiro para tipo Lista
		 ponteiro para inteiro, onde será armazenado o elemento removido
Descrição: remove o elemento do início da fila e armazena ele em 'elem'
Saida: 0, se a remoção falhar
       1, em sucesso
*/
int removeInicio(Lista *lst, int *elem)
{
	if(listaVazia(*lst))
		return 0;
		
	Lista aux = (*lst)->prox;  // primeiro elemento da lista
	*elem = aux->valor;
		
	// apenas um elemento na lista
	if((*lst)->prox == *lst)
		*lst = NULL;
	else // mais de um elemento
		(*lst)->prox = aux->prox;
	
	free(aux);
	return 1;
}

/*
removeFinal
-----------
Entrada: ponteiro para tipo Lista
		 ponteiro para inteiro, onde será armazenado o elemento removido
Descrição: remove o elemento do final da fila e armazena ele em 'elem'
Saida: 0, se a remoção falhar
       1, em sucesso
*/
int removeFinal(Lista *lst, int *elem)
{
	if(listaVazia(*lst))
		return 0;
		
	Lista aux = (*lst)->prox; // primeiro elemento da lista
	Lista ant = (*lst);
		
	// apenas um elemento na lista
	if(*lst == aux)
	{
		*elem = aux->valor;
		*lst = NULL;
	}
	else // mais de um elemento
	{
		while(aux->prox != (*lst)->prox)
		{
			ant = aux; // terminará apontando para o elemento anterior ao removido
			aux = aux->prox; // terminará apontando para o elemento a ser removido 
		}
		
		*elem = aux->valor;
		ant->prox = aux->prox;
		*lst = ant;
	}	
	
	free(aux);
	return 1;
}

/*
removeElem
-----------
Entrada: ponteiro para tipo Lista
		 inteiro, contendo o elemento a ser removido
Descrição: remove 'elem' da lista se ele existir
Saida: 0, se a remoção falhar
       1, em sucesso
*/
int removeElem(Lista *lst, int elem)
{
	if(listaVazia(*lst))
		return 0;
		
	Lista aux = (*lst)->prox;
	Lista ant = (*lst);
	
	if(*lst == aux)
	{
		//apenas um elemento
		if(aux->valor == elem)
			*lst = NULL;
		else
			return 0;
	}
	else
	{
		// mais de um elemento
		while(aux->prox != (*lst)->prox && aux->valor != elem)
		{
			ant = aux;
			aux = aux->prox;
		}
		
		if(aux->valor == elem)
		{
			ant->prox = aux->prox;
			
			if(aux == *lst) // se o aux era o ultimo elemento da lista
				*lst = ant;
		}
		else
			return 0;
	}
	
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
		
	Lista aux = lst->prox;	
		
	int i = 0;
	while(i < posicao)
	{
		aux = aux->prox;
		if(aux == lst->prox)// a lista foi toda percorrida e voltou ao primeiro elemento
			return 0;
			
		i++;
	}
	
	*elem = aux->valor;	
		
	return 1;
}
