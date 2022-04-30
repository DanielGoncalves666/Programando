#ifndef _PES_H
#define _PES_H


/*
	TAD referente a uma pilha estatica-sequencial

	Daniel Gonçalves
	2022
*/

#define MAX 20

typedef struct pilha * Pilha;

Pilha criaPilha();
int pilhaVazia(Pilha p);
int pilhaCheia(Pilha p);
int push(Pilha p, int elem);
int pop(Pilha p, int *elem);
int leTopo(Pilha p, int *elem);


#endif
