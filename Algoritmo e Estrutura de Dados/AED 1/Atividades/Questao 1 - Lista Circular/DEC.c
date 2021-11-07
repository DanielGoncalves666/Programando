#include <stdio.h>
#include <stdlib.h>
#inlcude "../include/DEC.H"


struct no
{
	int info;
	struct no * prox;
};

Lista cria_lista()
{
	return NULL;
}

int lista_vazia(Lista lst)
{
	if(lst == NULL)
		return 1;
	else 
		return 0;
}

