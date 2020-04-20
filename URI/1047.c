#include<stdio.h>
#include<stdlib.h>

int h1, m1, h2, m2, qtd_min = 0;

int main(){
	scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
	if(h1 == h2){
		if(m1 == m2)
			printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
		else if(m1 < m2){
			qtd_min += m2 - m1;
			printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", qtd_min/60, qtd_min%60);	
		}else if(m1 > m2){
			qtd_min += (23*60);
			qtd_min += m2 + (60 - m1); 
			printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", qtd_min/60, qtd_min%60);
		}
	}else if(h1 < h2){
		qtd_min += 60 - m1;
		qtd_min += (h2 - (h1+1))*60;
		qtd_min += m2;
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", qtd_min/60, qtd_min%60);
	}else if(h1 > h2){
		qtd_min += 60 - m1;
		qtd_min += m2;
		qtd_min += (24 - (h1 + 1))*60;
		qtd_min += h2*60;
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", qtd_min/60, qtd_min%60);
	} 
	
	return 0;
}
