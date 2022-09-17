#ifndef _FES_UC_H
#define _FES_UC_H


/*
	TAD referente a uma fila estatica-sequencial (com uso de contador) (FES-UC)

	Daniel Gonçalves
	2022
*/

#define MAX 20

typedef struct fila * Fila;

Fila criaFila();
int filaVazia(Fila p);
int filaCheia(Fila p);
int insereFinal(Fila f, int elem);
int removeInicio(Fila f, int *elem);


#endif
