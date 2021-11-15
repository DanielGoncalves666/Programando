#include<stdio.h>

int main(){
	int N, qtd = 0,ciclo;

	while(1){
		scanf("%d",&N);

		if(N == -1)
			break;

		qtd++;
		ciclo = N/2;

		printf("Experiment %d: %d full cycle(s)\n",qtd,ciclo);
	}

	return 0;
}