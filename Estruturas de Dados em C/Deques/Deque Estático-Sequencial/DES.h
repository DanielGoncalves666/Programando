#ifndef _DES_H
#define _DES_H


/*
	TAD referente a um deque estatica-sequencial (com uso de contador) (DES)

	Daniel Gonçalves
	2022
*/

#define MAX 20

typedef struct deque * Deque;

Deque criaDeque();
int dequeVazio(Deque d);
int dequeCheio(Deque d);
int insereInicio(Deque d, int elem);
int insereFinal(Deque d, int elem);
int removeInicio(Deque d, int *elem);
int removeFinal(Deque d, int *elem);

#endif
