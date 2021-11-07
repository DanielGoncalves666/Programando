#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void IniciaPilha(TipoPilha *pilha){
 pilha->topo = NULL;
 pilha->tamanho = 0;
}

int VaziaPilha(TipoPilha *pilha){
 return (pilha->topo == NULL);
}

int Topo (TipoPilha *pilha){
 TipoNo *aux;
 if (pilha==NULL) 
    return -1;
 return pilha->topo->valor;
}


void Empilha(int x, TipoPilha *pilha){
 TipoNo *aux;
 if (pilha==NULL) 
    return;
 aux = (TipoNo *) malloc(sizeof(TipoNo));
 aux->valor = x;
 aux->prox = pilha->topo;
 pilha->topo = aux;
 pilha->tamanho++;
}

int Desempilha(TipoPilha *pilha){
   int v;
   TipoNo *no;
   if (pilha==NULL) 
      return -1;
   no = pilha->topo;
   v = no->valor;
   pilha->topo = no->prox;
   pilha->tamanho--;
   free(no);
  return v;
}