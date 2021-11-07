#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


void IniciaFila(TipoFila *fila){
   fila->inicio = NULL;
   fila->fim = NULL;
   fila->tamanho=0;
}

int Vazia(TipoFila *fila){
   return (fila->inicio == NULL);
}

void Enfileira(int x, TipoFila *fila){
   TipoNo *aux;
   aux = (TipoNo *) malloc(sizeof(TipoNo));
   aux->valor=x;
   aux->prox=NULL;
   if (Vazia(fila)){
      fila->inicio=aux;
      fila->fim=aux;
   }
   else {
      fila->fim->prox = aux;
      fila->fim = aux;
   }
   fila->tamanho++;
}

int Desenfileira(TipoFila *fila){
   TipoNo *q; int v;
   if (Vazia(fila)) {
      printf("Fila esta vazia\n");
      return 0;
   }
   q = fila->inicio;
   v = fila->inicio->valor;
   fila->inicio = fila->inicio->prox;
   free(q);
   fila->tamanho--;
   return v;
}
