#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int gritos = 0, repet = 0, soma, numero;
char string[8];

int main(){

	for(;gritos<3;){
		scanf("%s ",string);
		
		if(string[0] == 'c'){
			gritos++;
			repet++;
			if(repet == 2)
				printf("0\n");
			if(soma > 0){
				printf("%d\n",soma);
				soma = 0;
			}	
		}else{
			repet = 0;
			numero = 0;

			if(string[0] == '*')
				numero += 4;
			if(string[1] == '*')
				numero += 2;
			if(string[2] == '*')
				numero += 1;
				
			soma += numero;
		}
	}


	return 0;
}	
