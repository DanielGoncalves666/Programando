#include<stdio.h>
#include<stdlib.h>

int A, N, i,soma=0;

int main(){
	scanf("%d",&A);
	for(;;){
		scanf("%d",&N);
		if(N<=0)
			continue;
		for(i=0;i<N;i++){
			soma+=A+i;
		}	
		break;
	}
	printf("%d\n",soma);
	
	return 0;
}
