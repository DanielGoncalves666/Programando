#include<stdio.h>
#include<stdlib.h>

int main(){
	int N, M, num;

	while(1){
		scanf("%d %d",&N,&M);
		if(N + M == 0)
			break;

		int *bilhetes = NULL, *qtd = NULL, qtd_absoluta = 0;
		for(int i=0; i<M; i++){
			scanf("%d",&num);

			if(i == 0){
				qtd_absoluta++;
				bilhetes = (int *) realloc(bilhetes,qtd_absoluta*sizeof(int));
				qtd = (int *) realloc(qtd,qtd_absoluta*sizeof(int));
				bilhetes[0] = num;
				qtd[0] = 1;
			}else{
				for(int h=0; h<qtd_absoluta; h++){
					if(num == bilhetes[h]){
						qtd[h]++;
						break;
					}

					if(h + 1 == qtd_absoluta){
						qtd_absoluta++;
						bilhetes = (int *) realloc(bilhetes,qtd_absoluta*sizeof(int));
						qtd = (int *) realloc(qtd,qtd_absoluta*sizeof(int));

						bilhetes[h+1] = num;
						qtd[h+1] = 1;
						break;
					}
				}
			}
		}

		int total = 0;
		for(int i=0; i<qtd_absoluta; i++){
			if(qtd[i] > 1)
				total++;
		}

		printf("%d\n",total);
	}

	return 0;
}