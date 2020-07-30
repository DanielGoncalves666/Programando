#include<stdio.h>

int main(){
	int N,maior,num;

	scanf("%d",&N);

	for(int i=0; i<N; i++){
		scanf("%d",&num);

		if(i == 0){
			maior = num;
		}else if(maior < num){
			maior = num;
		}
	
	}

	printf("%d\n",maior + 1);

	return 0;
}