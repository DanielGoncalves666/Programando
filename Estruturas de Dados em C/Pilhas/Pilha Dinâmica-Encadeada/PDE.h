#ifndef _PDE_H
#define _PDE_H


/*
	TAD referente a uma pilha dinâmica encadeada

	Daniel Gonçalves
	2022
*/

typedef struct no * Pilha;

Pilha criaPilha();
int pilhaVazia(Pilha p);
int pilhaCheia(Pilha p);
int push(Pilha *p, int elem);
int pop(Pilha *p, int *elem);
int leTopo(Pilha p, int *elem);


#endif
