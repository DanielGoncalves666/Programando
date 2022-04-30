#ifndef _FES_DP_H
#define _FES_DP_H


/*
	TAD referente a uma fila estatica-sequencial (com disperdício de posição) (FES_DP)

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
