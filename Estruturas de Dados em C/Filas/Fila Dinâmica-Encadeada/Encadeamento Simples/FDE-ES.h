#ifndef _FDE_ES_H
#define _FDE_ES_H


/*
	TAD referente a uma fila dinâmica encadeada com encadeamento simples (FDE-ES)

	Daniel Gonçalves
	2022
*/

typedef struct fila * Fila;

Fila criaFila();
int filaVazia(Fila f);
int insereFinal(Fila f, int elem);
int removeInicio(Fila f, int *elem);


#endif
