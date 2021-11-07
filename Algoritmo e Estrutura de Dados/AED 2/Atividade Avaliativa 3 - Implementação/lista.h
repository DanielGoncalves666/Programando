#ifndef LISTA_H
#define LISTA_H

#include "palavra.h"

typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, Palavra nova);
int remove_ord(Lista *lst, Palavra procurada);
Palavra *consulta_lista(Lista lst, Palavra procurada);

#endif