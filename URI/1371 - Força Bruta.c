//programa feito com força bruta, econtra a qtd de divisores de cada número
//apenas as portas de quadrados perfeitos ficam abertas
#include<stdio.h>
#include<stdlib.h>

int main(){
	int N;

	while(1){
		scanf("%d",&N);
		if(N == 0)
			break;

		int *portas = (int *) calloc(N,sizeof(int));
		portas[0] = 1;//a primeira porta sempre ta aberta

		int qtd;

		for(int i=2; i<=N; i++){
			qtd = 2;//todo numero é divisivel por 1 e ele mesmo
			for(int h=2; h<=i/2; h++){
				if(i % h == 0)
					qtd++;
			}

			if(qtd % 2 == 1)
				portas[i-1] = 1;
		}

		printf("1");
		for(int i=1; i<N; i++){
			if(portas[i] == 1){
				printf(" %d",i+1);
			}
		}
		printf("\n");

		free(portas);
	}

	return 0;
}