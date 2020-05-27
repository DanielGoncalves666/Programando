#include<stdio.h>
#include<stdlib.h>

int N,qtd;

int main(){
	int caso = 1;
	
	for(;scanf("%d",&N) != EOF;){
		qtd = 1;
		for(int i=1; i<=N; i++){
			qtd += i;
		}
		if(N == 0){
			printf("Caso %d: %d numero\n",caso,qtd);
			printf("0\n\n");
		}else{
			printf("Caso %d: %d numeros\n",caso,qtd);
			printf("0 ");
			for(int h=1; h<=N; h++){
				for(int j=0; j<h; j++){
					printf("%d",h);
					if(j < h-1)
						printf(" ");
				}
				if(h < N)
					printf(" ");
			}
			printf("\n\n");	
		}
		caso++;
	}

	return 0;
}
