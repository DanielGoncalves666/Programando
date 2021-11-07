#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(void) {
  int rgrau;
  struct noHorario *h;
  
  Grafo g;
  g = criarGrafo(8);
  inserirArco (g,0,1);
  inserirArco (g,1,0);
  inserirArco (g,0,5);
  inserirArco (g,5,0);
  inserirArco (g,5,7);
  inserirArco (g,7,5);
  inserirArco (g,3,7);
  inserirArco (g,7,3);
  inserirArco (g,3,4);
  inserirArco (g,4,3);
  inserirArco (g,2,4);
  inserirArco (g,4,2);
  inserirArco (g,2,6);
  inserirArco (g,6,2);
  inserirArco (g,0,2);
  inserirArco (g,2,0);
  inserirHorario (g,0,1,10,0,11,0);
  inserirHorario (g,0,1,17,0,18,0);
  inserirHorario (g,1,0,11,0,12,0);
  inserirHorario (g,1,0,19,0,20,0);
  inserirHorario (g,0,5,1,30,3,0);
  inserirHorario (g,0,5,10,0,12,0);
  inserirHorario (g,5,0,3,0,5,0);
  inserirHorario (g,5,0,13,0,14,30);
  inserirHorario (g,0,2,5,0,6,30);
  inserirHorario (g,0,2,14,50,16,0);
  inserirHorario (g,2,0,7,0,9,0);
  inserirHorario (g,2,0,16,30,18,0);
  inserirHorario (g,2,6,10,0,11,0);
  inserirHorario (g,6,2,12,0,13,0);
  inserirHorario (g,2,4,17,0,18,0);
  inserirHorario (g,4,2,15,0,16,0);
  inserirHorario (g,4,3,9,0,11,0);
  inserirHorario (g,3,4,16,0,18,0);
  inserirHorario (g,3,7,5,0,8,0);
  inserirHorario (g,7,3,9,0,12,0);
  inserirHorario (g,7,5,0,0,1,0);
  inserirHorario (g,5,7,2,0,3,0);
 
  
  h = encontrarListaHorarios(g, 0, 5);
  while (h->prox !=NULL)
      printf("%d %d",h->HoraSaida, h->HoraChegada);
  
  imprimirListaAdj(g);


  
  

 


}