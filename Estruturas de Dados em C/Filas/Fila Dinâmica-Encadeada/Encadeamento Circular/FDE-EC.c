#include<stdlib.h>
#include"FDE-EC.h"

struct no
{
	int valor;
	struct no *prox;
};

/*
criaFila
----------
Entrada: nenhuma
Descrição: cria uma Fila e coloca ela no estado vazio (simplesmente returna NULL)
Saida: tipo fila
*/
Fila criaFila()
{
	return NULL;
}

/*
filaVazia
------------
Entrada: tipo Fila
Descrição: verificar se fila passada está vazia
Saída: 0, se há elementos
	   1, se a fila está vazia
*/
int filaVazia(Fila f)
{
	if(f == NULL)
		return 1;
	else
		return 0;
}

// Função filaCheia não tem motivo para ser implementada já que o máximo de elementos da fila vai depender da memória disponível

/*
insereFinal
----------
Entrada: ponteiro para tipo fila
		 inteiro a ser incluído na fila.
Descrição: Adiciona 'elem' no final de f
Saída: 0, se a inserção falhar
       1, se suceder
*/
int insereFinal(Fila *f, int elem)
{
	struct no *novo = (struct no *) malloc(sizeof(struct no));
	if(novo == NULL)
		return 0;
		
	novo->valor = elem;

	if(filaVazia(*f))
	{
		novo->prox = novo;
		*f = novo;
	}
	else
	{
		novo->prox = (*f)->prox;
		(*f)->prox = novo;
		*f = novo;
	}
	
	return 1;
}

/*
removeInicio
-------------
Entrada: ponteiro para tipo fila
         ponteiro para inteiro, indicando onde o valor removido deve ser armazenado
Descrição: remove o elemento no começo da fila
Saída: 0, se a remoção falhar
       1, se a remoção suceder
*/
int removeInicio(Fila *f, int *elem)
{
	if(filaVazia(*f))
		return 0;
		
	Fila aux = (*f)->prox;
	*elem = aux->valor;
	
	if(*f == (*f)->prox)
		*f = NULL;	
	else
		(*f)->prox = aux->prox;
		
	free(aux);
	
	return 1;
}




