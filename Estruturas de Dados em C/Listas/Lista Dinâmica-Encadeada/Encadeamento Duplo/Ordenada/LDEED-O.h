#ifndef _LDEED_O_H
#define _LDEED_O_H


/*
	TAD referente a uma lista dinâmica encadeada simples com encadeamento duplo (LDEC) ordenada (O).

	Daniel Gonçalves
	2022
*/

typedef struct no * Lista;

Lista criaLista();
int listaVazia(Lista lst);
int insereOrd(Lista *lst, int elem);
int removeOrd(Lista *lst, int elem);
int obterElemPosicao(Lista lst, int posicao, int *elem);


#endif
