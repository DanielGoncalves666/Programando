//Lista Linear Não ordenada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/LLNO.h"

const int MAX = 20;

struct llno
{
	char lista[20][tam];
	int FIM;
};

/*
criar_lista
----------
Entrada: Nenhuma
Operação: Aloca uma estrutura do tipo 'struct llno' e seta FIM para zero
Saída: tipo ListaStrings
*/
ListaStrings criar_lista()
{
	ListaStrings p = (ListaStrings) malloc(sizeof(struct llno));

	if(p != NULL)
		p->FIM = 0;

	return p;
}

/*
lista_vazia
----------
Entrada: tipo ListaStrings
Operação: verifica se a lista está vazia
Saída: 0, para não, 1, para sim
*/
int lista_vazia(ListaStrings p)
{	
	if(p->FIM == 0)
		return 1;

	return 0;
}

/*
lista_cheia
----------
Entrada: tipo ListaStrings
Operação: verifica se a lista está cheia
Saída: 0, para não, 1, para sim
*/
int lista_cheia(ListaStrings p)
{
	if(p->FIM == MAX)
		return 1;

	return 0;
}


/*
insere_elem
----------
Entrada: tipo ListaStrings, um vetor de caracteres
Operação: Adiciona o vetor de caracteres ao fim da lista
Saída: 0, em fracasso, 1, em sucesso
*/
int insere_elem(ListaStrings p, char string[tam])
{
	if(p == NULL || lista_cheia(p) == 1)
		return 0;

	strcpy(p->lista[p->FIM],string);
	p->FIM++;

	return 1;
}


/*
get_pos
----------
Entrada: tipo ListaStrings, inteiro indicando a posição(1 até FIM)
Operação: retorna o conteúdo da posição indicada, se ela existe.
Saída: 0, em fracasso, 1 , em sucesso
*/
char *get_pos(ListaStrings p, int pos)
{
	if(p == NULL || pos <= 0 || pos > p->FIM)
		return NULL;

	return p->lista[pos - 1];
}

/*
remove_elem
----------
Entrada: tipo listaStrings, vetor de caracteres
Operação: remove um elemento da lista
Saída: 0, em fracasso, 1, em sucesso
*/
int remove_elem(ListaStrings p, char string[tam])
{
	if(p == NULL || lista_vazia(p) == 1)
		return 0;
	
	int aux = 0, i = 0;

	while(aux < p->FIM && strcmp(string, p->lista[aux]) != 0)
		aux++;

	if(aux == p->FIM)
		return 0;

	for(i = aux + 1; i < p->FIM; i++)
		strcpy(p->lista[i - 1], p->lista[i]);

	p->FIM--;

	return 1;
}


/*
apaga_lista
----------
Entrada: tipo ListaStrings
Operação: desaloca a estrutura lista
Saída: nenhuma
*/

void apaga_lista(ListaStrings *p)
{
	free(*p);
	*p = NULL;
}