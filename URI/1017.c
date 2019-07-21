#include<stdio.h>
#include<stdlib.h>
#define gasto 12.0

	int tempo, velocidade;
	float litros;

void main(){
	scanf("%d %d",&tempo,&velocidade);
	litros=(tempo*velocidade)/gasto;
	printf("%.3f\n",litros);
}
