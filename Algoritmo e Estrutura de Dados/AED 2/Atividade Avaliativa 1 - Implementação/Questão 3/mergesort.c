#include <stdlib.h>
#include "header.h"

void intercala(struct cliente v[], int esq, int med, int dir);

void mergesortMelhorado(struct cliente v[], int esq, int dir){
	
	int med;
   	if (esq < dir){
    	med = (esq+dir) / 2;
    mergesortMelhorado(v,esq,med);
    mergesortMelhorado(v,med+1,dir);
    

    if (!(v[med].agencia < v[med+1].agencia))
	    intercala(v,esq,med,dir);
   }
}

void intercala(struct cliente v[], int esq, int med, int dir){

	struct cliente *r;  //vetor auxiliar dinâmico para armazenar a mistura
	int i,j,k;

	r = (struct cliente *) malloc (((dir+1) - esq)*sizeof(struct cliente));

	i = esq;
	j = med + 1;
	k = 0;

	while ((i <= med) && ( j <= dir))
	{
		if(v[i].agencia <= v[j].agencia){
			r[k] = v[i];
			i++;
		}
		else{
			r[k] = v[j];
			j++;
		}
		k++;
	}

	while (i <= med) 
	{
		r[k] = v[i]; 
		i++; 
		k++;
	}
	
	while (j <= dir) 
	{
		r[k] = v[j];
		j++;
		k++;
	}

	//Copia do vetor auxiliar (contendo os dados ordenados) sobre o vetor original
	j=0;
	for(i = esq; i <= dir; i++){
		v[i]=r[j];
		j++;
	}

	free(r);
}