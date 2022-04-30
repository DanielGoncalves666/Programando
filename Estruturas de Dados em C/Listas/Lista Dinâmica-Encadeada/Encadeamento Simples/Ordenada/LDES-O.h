#ifndef _LDES_O_H
#define _LDES_O_H


/*
	TAD referente a uma lista dinâmica encadeada simples (LDES) ordenada (O).

	Daniel Gonçalves
	2022
*/

typedef struct no * Lista;

Lista criaLista();
int listaVazia(Lista lst);
int insereOrd(Lista *lst, int elem);
int removeOrd(Lista *lst, int elem);
int obterElemPosicao(Lista lst, int posicao, int *elem);
int obterPosicaoElem(Lista lst, int *posicao, int elem);
int removeElemPos(Lista *lst, int posicao, int *elem);

#endif
