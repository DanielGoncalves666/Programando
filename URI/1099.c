#include<stdio.h>
#include<stdlib.h>

int N,x,y,soma;

int main(){
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		soma = 0;
		scanf("%d %d",&x,&y);
		if(x == y){
			printf("0\n");
			continue;
		}else if(x > y){
			int aux = x;
			x = y;
			y = aux;
		}
			
		for(int i=x+1; i<y; i++){
			if(i%2 == 1){
				soma += i;
			}
		}
		printf("%d\n",soma);
	}

	return 0;
}
