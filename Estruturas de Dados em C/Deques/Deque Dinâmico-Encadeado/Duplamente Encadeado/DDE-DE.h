#ifndef _DDE_DE_H
#define _DDE_DE_H


/*
	TAD referente a um deque dinâmico encadeado com encadeamente duplo

	Daniel Gonçalves
	2022
*/

typedef struct deque * Deque;

Deque criaDeque();
int dequeVazio(Deque d);
int insereInicio(Deque d, int elem);
int insereFinal(Deque d, int elem);
int removeInicio(Deque d, int *elem);
int removeFinal(Deque d, int *elem);

#endif
