#include<stdio.h>
#include<stdlib.h>

int **p, i=10;

int main(){
	
	p = malloc(i*sizeof(int *));//p recebera o endereço de um bloco de memoria onde esta alocado um vetor de i posições
	for(int h=0;h<10;h++){
		p[h]=malloc(i*sizeof(int));//para cada posição do vetor p, que é um vetor de ponteiros para inteiros, será dado 
		//um endereço para um novo vetor de i posições, deste modo, temos uma matriz de 10X10 posições
	}

	return 0;
}
