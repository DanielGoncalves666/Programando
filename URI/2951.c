#include<stdio.h>
#include<stdlib.h>

int qtd, amizade, soma=0, recitadas;
char RUNA;

int main(){
	scanf("%d %d ",&qtd,&amizade);
	char runas[qtd+1];
	int valores[qtd];
	
	for(int i=0; i<qtd; i++){
		scanf("%c %d ",&runas[i],&valores[i]);
	}
	scanf("%d ",&recitadas);

	for(int i=0; i<recitadas; i++){
		RUNA = getchar();
		getchar();
		for(int h=0; h<qtd; h++){
			if(RUNA == runas[h]){
				soma += valores[h];
				break;	
			}
		}
	}
	printf("%d\n",soma);
	
	if(soma >= amizade)
		printf("You shall pass!\n");
	else
		printf("My precioooous\n");

	return 0;
}
