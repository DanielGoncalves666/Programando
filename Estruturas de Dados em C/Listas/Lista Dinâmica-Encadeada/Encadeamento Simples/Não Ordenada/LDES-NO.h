#ifndef _LDES_NO_H
#define _LDES_NO_H


/*
	TAD referente a uma lista dinâmica encadeada simples (LDES) não ordenada (NO).

	Daniel Gonçalves
	2022
*/

typedef struct no * Lista;

Lista criaLista();
int listaVazia(Lista lst);
int insereElem(Lista *lst, int elem);
int removeElem(Lista *lst, int elem);
int obterElemPosicao(Lista lst, int posicao, int *elem);
int obterPosicaoElem(Lista lst, int *posicao, int elem);
int removeElemPos(Lista *lst, int posicao, int *elem);

#endif
