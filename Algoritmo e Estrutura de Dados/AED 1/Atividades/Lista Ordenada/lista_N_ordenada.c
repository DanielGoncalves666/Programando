#include <stdio.h>
#include <stdlib.h>
#include "../include/lista_N_ordenada.h"

#define MAX 20//tamanho

struct lista
{
	float list[MAX];
	int fim;
};

/*
criar_lista
------------
Entrada: nenhuma
Processo: aloca dinamicamente uma estrutura do tipo (struct lista) e seta a variável fim para zero.
Saída: tipo Lista_NO
*/
Lista_NO criar_lista()
{
	Lista_NO lst = NULL;

	lst = (Lista_NO) malloc(sizeof(struct lista));

	if(lst != NULL)
		lst->fim = 0;

	return lst;
}

/*
lista_vazia
-----------
Entrada: tipo Lista_NO
Processo: verifica se a lista está vazia
Saída: 0, se não estiver, 1, se estiver
*/
int lista_vazia(Lista_NO lst)
{
	if(lst->fim == 0)
		return 1;
	else
		return 0;
}

/*
lista_cheia
-----------
Entrada: tipo Lista_NO
Processo: verifica se a lista está cheia
Saída: 0, se não estiver, 1, se estiver
*/
int lista_cheia(Lista_NO lst)
{
	if(lst->fim == MAX)
		return 1;
	else
		return 0;
}

/*
insere_elem
------------
Entrada: tipo Lista_NO; float
Processo: insere o float recebido no final da lista
Saída: 0, em fracasso, 1, em sucesso
*/
int insere_elem(Lista_NO lst, float elem)
{
	if(lst == NULL || lista_cheia(lst))
		return 0;
	
	lst->list[lst->fim] = elem;//insere elemento
	lst->fim++;//incrementa o fim

	return 1;
}

/*
remove_elem
--------------
Entrada: tipo Lista_NO; float
Processo: remove, se existir, o elemento passado como float da lista.
Saída: 0, em fracasso, 1, em sucesso.
*/
int remove_elem(Lista_NO lst, float elem)
{
	//a lista estiver vazia
	if(lst == NULL || lista_vazia(lst))
		return 0;

	int aux = 0, i = 0;

	//procura pelo elemento na lista
	while(aux < lst->fim && lst->list[aux] != elem)
		aux++;

	//se o elemento não existir
	if(aux == lst->fim)
		return 0;

	//se o elemento existir. Caso estiver na última posição o laço não é executado
	for(i = aux + 1; i < lst->fim; i++)
	{
		lst->list[i - 1] = lst->list[i];
	}

	lst->fim--;

	return 1;
}

/*
limpa_lista
-------------
Entrada: tipo Lista_NO
Processo: seta a lista apontada por Lista_NO para o modo vazio
Saída: nenhuma
*/
void limpa_lista(Lista_NO lst)
{
	lst->fim = 0;
}

/*
get_posicao
------------
Entrada: tipo Lista_NO; um inteiro indicando a posicao
Processo: acessa a posicao da lista solicitada e retorna seu valor
Saida: o float armazenado na posicao solicitada
*/
float get_posicao(Lista_NO lst, int posicao)
{
	return lst->list[posicao - 1];
}