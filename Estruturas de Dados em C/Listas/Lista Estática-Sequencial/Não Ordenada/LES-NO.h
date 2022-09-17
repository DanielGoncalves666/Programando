#ifndef _LES_NO_H
#define _LES_NO_H

/*
	TAD referente a uma lista estático sequencial (LES) não ordenada (NO).

	Daniel Gonçalves
	2022
*/

#define TAM 10

typedef struct lista * Lista;

Lista criaLista();
int listaVazia(Lista lst);
int listaCheia(Lista lst);
int insereElem(Lista lst, int elem);
int removeElem(Lista lst, int elem);
int existeElem(Lista lst, int elem);
int obterValorElem(Lista lst, int indice, int *elem);

#endif
