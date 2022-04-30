#ifndef _LDEC_NO_H
#define _LDEC_NO_H


/*
	TAD referente a uma lista dinâmica encadeada simples circular (LDEC) não ordenada (NO).

	Daniel Gonçalves
	2022
*/

typedef struct no * Lista;

Lista criaLista();
int listaVazia(Lista lst);
int insereFinal(Lista *lst, int elem);
int insereInicio(Lista *lst, int elem);
int removeInicio(Lista *lst, int *elem);
int removeFinal(Lista *lst, int *elem);
int removeElem(Lista *lst, int elem);
int obterElemPosicao(Lista lst, int posicao, int *elem);


#endif
