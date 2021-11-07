#include <time.h>
#include <stdlib.h>

int particao(int v[],int esq,int dir);
void troca(int v[], int i,int j);
int pivo_aleatorio(int esq, int dir);
void insertsort(int v[], int esq, int dir);

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

int pivo_aleatorio(int esq, int dir) { 
   	double r;
   	r = (double) rand()/RAND_MAX;  // valor entre 0.01 e 0.99
   	return (int)(esq + r*(dir-esq));
}

void insertsort(int v[], int esq, int dir) {
	int i, j;
	int aux;
  
  	for(i = esq + 1; i <= dir; i++) {
    	aux = v[i];
    	j = i - 1;
    	while((j >= 0) && (aux < v[j])) {
      		v[j+1] = v[j];
      		j--;
    	}
    	v[j + 1] = aux;
  }
}

void quicksort_aleatorizado(int v[], int esq, int dir) {
   	int i;
   	if(dir <= esq) 
		return;

   	troca(v, pivo_aleatorio(esq,dir), esq);
   	i = particao(v, esq, dir);
   	
	quicksort_aleatorizado(v, esq, i-1);
	quicksort_aleatorizado(v, i+1, dir);
}

void quicksort_aleatorizado_insertsort(int v[], int esq, int dir)
{
	int i;
   	if(dir <= esq)//verifica se a partição é inválida 
		return;

   	troca(v, pivo_aleatorio(esq,dir), esq);//realiza a troca entre o pivo escolhido aleatoriamente
	   									   // e a posição da esquerda
   	i = particao(v, esq, dir);			   // chamada da partição normal
   	
	if((i - 1) - esq + 1 <= 5)		       //verificação do tamanho da partição		
		insertsort(v,esq,i - 1);
	else
		quicksort_aleatorizado(v, esq, i-1);
	
	if(dir - (i + 1) + 1 <= 5)
		insertsort(v,i + 1, dir);
	else
		quicksort_aleatorizado(v, i+1, dir);
}

