#ifndef _LDEED_NO_H
#define _LDEED_NO_H


/*
	TAD referente a uma lista dinâmica encadeada simples com encadeamento duplo (LDEC) não ordenada (NO).

	Daniel Gonçalves
	2022
*/

typedef struct no * Lista;

Lista criaLista();
int listaVazia(Lista lst);
int insereElem(Lista *lst, int elem);
int removeElem(Lista *lst, int elem);
int obterElemPosicao(Lista lst, int posicao, int *elem);


#endif
