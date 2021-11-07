#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int pivo_aleatorio(int esq, int dir);
void pivo_medio(int v[], int esq, int dir);
int particao(int v[],int esq,int dir);
void troca(int v[], int i,int j);

int particao(int v[],int esq,int dir){
  	int i, fim;

  	fim = esq;
  	for(i = esq+1; i <= dir;i++)
  	{
    	if(v[i] < v[esq]){
       		fim = fim+1;
    	   	troca(v,fim,i);
    	}
  	}
  	troca(v,esq,fim);
  	return fim;
}

void troca(int v[], int i,int j){
  	int temp;
  
  	temp = v[i];
  	v[i] = v[j];
  	v[j] = temp;
}


void quicksort(int v[], int esq, int dir){
  
  	int i, retorno;
  	int auxDir, auxEsq;
  	Pilha p = cria_pilha();
  
  	retorno = empilha(&p,esq,dir);	//empilha a partição composta por toda a lista
  	if(!retorno)
  	{
		printf("\nFalha! Espaço insuficiente!\n");
		return;
  	}

  	do
  	{
		desempilha(&p,&auxEsq,&auxDir);
	  

	  	if(auxEsq < auxDir)
	  	{
			i = particao(v,auxEsq,auxDir); 
			retorno = empilha(&p,i+1,auxDir);
			retorno += empilha(&p,auxEsq,i - 1);
			//primeiro empilha a partição da direita, pois ela fica mais ao fundo da pilha 
	  	
			if(retorno != 2)
			{
				printf("\nFalha! Espaço insuficiente!\n");
				return;
  			}	  
		}
		//se esq e dir forem iguais, é uma partição unitária e o elemento estará na posição correta
		//e desse modo não empilhamos

  	}while(tamanho_pilha(p));
}

int pivo_aleatorio(int esq, int dir) { 
   	double r;
   	r = (double) rand()/RAND_MAX;  // valor entre 0.01 e 0.99
   	return (int)(esq + r*(dir-esq));
}

void quicksortAleatorizado(int v[], int esq, int dir){
  
  	int i, retorno;
  	int auxDir, auxEsq;
  	Pilha p = cria_pilha();
  
  	retorno = empilha(&p,esq,dir);	//empilha a partição composta por toda a lista
  	if(!retorno)
  	{
		printf("\nFalha! Espaço insuficiente!\n");
		return;
  	}

  	do
  	{
		desempilha(&p,&auxEsq,&auxDir);
	  
	  	if(auxEsq < auxDir)
	  	{
			troca(v,pivo_aleatorio(auxEsq,auxDir),auxDir);
			i = particao(v,auxEsq,auxDir); 
			retorno = empilha(&p,i+1,auxDir);
			retorno += empilha(&p,auxEsq,i - 1);
			//primeiro empilha a partição da direita, pois ela fica mais ao fundo da pilha 
	  	
			if(retorno != 2)
			{
				printf("\nFalha! Espaço insuficiente!\n");
				return;
  			}	  
		}
		//se esq e dir forem iguais, é uma partição unitária e o elemento estará na posição correta
		//e desse modo não empilhamos

  	}while(tamanho_pilha(p));
}

void pivo_medio(int v[], int esq, int dir)
{
	troca(v,(esq + dir)/2, esq + 1);
	if(v[esq] > v[esq + 1])
		troca(v,esq,esq + 1);
	
	if(v[esq] > v[dir])
		troca(v,esq,dir);
	
	if(v[esq + 1] > v[dir])
		troca(v,esq + 1, dir);
}

void quicksortMediana3(int v[], int esq, int dir){
  
  	int i, retorno;
  	int auxDir, auxEsq;
  	Pilha p = cria_pilha();
  
  	retorno = empilha(&p,esq,dir);	//empilha a partição composta por toda a lista
  	if(!retorno)
  	{
		printf("\nFalha! Espaço insuficiente!\n");
		return;
  	}

  	do
  	{
		desempilha(&p,&auxEsq,&auxDir);
	  
	  	if(auxEsq < auxDir)
	  	{
			pivo_medio(v,auxEsq,auxDir);
			i = particao(v,auxEsq,auxDir); 
			retorno = empilha(&p,i+1,auxDir);
			retorno += empilha(&p,auxEsq,i - 1);
			//primeiro empilha a partição da direita, pois ela fica mais ao fundo da pilha 
	  	
			if(retorno != 2)
			{
				printf("\nFalha! Espaço insuficiente!\n");
				return;
  			}	  
		}
		//se esq e dir forem iguais, é uma partição unitária e o elemento estará na posição correta
		//e desse modo não empilhamos

  	}while(tamanho_pilha(p));
}
