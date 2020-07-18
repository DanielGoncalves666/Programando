#include<stdio.h>
#include<stdlib.h>

int main(){
	int N, comprimento, qtd;

	while(1){
		scanf("%d",&N);
		if(N == 0)
			break;

		int pares = 0;
		for(int i=0; i<N; i++){
			scanf("%d %d",&comprimento,&qtd);
			pares += qtd/2;
		}

		if(pares % 2 == 0){
			printf("%d\n",pares/2);
		}else{
			printf("%d\n",(pares - 1)/2);
		}
	}

	return 0;
}