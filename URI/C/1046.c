#include<stdio.h>
#include<stdlib.h>

	int inicio, fim, tempo;

void main(){
	scanf("%d %d",&inicio,&fim);
	if(inicio>fim){
		tempo=(24-inicio)+fim;
		printf("O JOGO DUROU %d HORA(S)\n",tempo);
	}
	if(inicio<fim){
		tempo=fim-inicio;
		printf("O JOGO DUROU %d HORA(S)\n",tempo);
	}
	if(inicio==fim){
		printf("O JOGO DUROU 24 HORA(S)\n");
	}
}
