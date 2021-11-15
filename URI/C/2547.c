#include<stdio.h>

int main(){
	int N, min, max, qtd, num;

	while(scanf("%d %d %d",&N,&min,&max) != EOF){
		qtd = 0;

		for(int i=0; i<N; i++){
			scanf("%d",&num);

			if(num >= min && num <= max)
				qtd++;
		}

		printf("%d\n",qtd);
	}

	return 0;
}