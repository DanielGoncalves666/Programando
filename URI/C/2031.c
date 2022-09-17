#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N, ganhador;
char s1[7], s2[7];

int vencedor(char *s1, char *s2);

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf(" %s %s",s1,s2);
		ganhador = vencedor(s1,s2);
		if(ganhador == 0)
			printf("Sem ganhador\n");
		else if(ganhador == 3)
			printf("Ambos venceram\n");
		else if(ganhador == 4)
			printf("Aniquilacao mutua\n");
		else
			printf("Jogador %d venceu\n",ganhador);
	}

	return 0;
}

int vencedor(char *s1, char *s2){
	if(strcmp(s1,"ataque") == 0){
		if(strcmp(s2,"ataque") == 0){
			return 4;
		}else if(strcmp(s2,"papel") == 0){
			return 1;
		}else if(strcmp(s2,"pedra") == 0){
			return 1;
		}
	}else if(strcmp(s1,"pedra") == 0){
		if(strcmp(s2,"ataque") == 0){
			return 2;
		}else if(strcmp(s2,"papel") == 0){
			return 1;
		}else if(strcmp(s2,"pedra") == 0){
			return 0;
		}
	}else if(strcmp(s1,"papel") == 0){
		if(strcmp(s2,"ataque") == 0){
			return 2;
		}else if(strcmp(s2,"papel") == 0){
			return 3;
		}else if(strcmp(s2,"pedra") == 0){
			return 2;
		}
	}
}
