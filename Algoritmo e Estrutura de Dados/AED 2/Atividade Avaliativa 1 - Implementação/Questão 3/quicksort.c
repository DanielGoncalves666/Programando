#include<stdlib.h>
#include<string.h>
#include"header.h"

void troca(struct cliente v[], int i,int j);
int particao(struct cliente v[],int esq,int dir);

int particao(struct cliente v[],int esq,int dir){
  	int i, fim;

  	fim = esq;
  	for(i = esq+1; i <= dir;i++)
  	{
    	if(strcmp(v[i].nome,v[esq].nome) < 0)
		{
       		fim = fim+1;
    	   	troca(v,fim,i);
    	}
  	}
  	troca(v,esq,fim);
  	return fim;
}

void troca(struct cliente v[], int i,int j){
	struct cliente temp;
  
  	temp = v[i];
  	v[i] = v[j];
  	v[j] = temp;
}

void quicksort_mediana_tres(struct cliente v[], int esq, int dir) {
	int i;
	
	if(dir <= esq) 
		return;
	
	troca(v, (esq+dir)/2, esq+1);
	
	if(strcmp(v[esq].nome,v[esq+1].nome) > 0)
		troca(v, esq, esq+1);
	if(strcmp(v[esq].nome,v[dir].nome) > 0)
		troca(v, esq, dir);
	if(strcmp(v[esq+1].nome,v[dir].nome) > 0)
		troca(v, esq+1, dir);
	
	i = particao(v, esq+1, dir-1);
	quicksort_mediana_tres(v, esq, i-1);
	quicksort_mediana_tres(v, i+1, dir);
 }