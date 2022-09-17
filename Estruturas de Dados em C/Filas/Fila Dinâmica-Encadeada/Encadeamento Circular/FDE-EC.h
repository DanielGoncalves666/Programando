#ifndef _FDE_EC_H
#define _FDE_EC_H


/*
	TAD referente a uma fila dinâmica encadeada com encadeamento circular (FDE-EC)

	Daniel Gonçalves
	2022
*/

typedef struct no * Fila;

Fila criaFila();
int filaVazia(Fila f);
int insereFinal(Fila *f, int elem);
int removeInicio(Fila *f, int *elem);


#endif
