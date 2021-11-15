#include<stdio.h>

int main(){
	int aposta[6], resul[6], qtd = 0;

	for(int i=0; i<6; i++){
		scanf("%d",&aposta[i]);
	}

	for(int i=0; i<6; i++){
		scanf("%d",&resul[i]);
	}

	for(int i=0; i<6; i++){
		for(int h=0; h<6; h++){
			if(aposta[i] == resul[h]){
				qtd++;
				break;
			}
		}
	}

	if(qtd < 3)
		printf("azar\n");
	else if(qtd == 3)
		printf("terno\n");
	else if(qtd == 4)
		printf("quadra\n");
	else if(qtd == 5)
		printf("quina\n");
	else if(qtd == 6)
		printf("sena\n");

	return 0;
}