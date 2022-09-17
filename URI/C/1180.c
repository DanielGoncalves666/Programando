#include<stdio.h>
#include<stdlib.h>

	int N,i,menor,p;

int main(){
	scanf("%d",&N);
	int X[N];
	for(i=0;i<N;i++){
		scanf("%d",&X[i]);
		if(i==0){
			menor=X[i];
			p=i;
		}
		if(X[i]<menor){
			menor=X[i];
			p=i;
		}
	}
	printf("Menor valor: %d\n",menor);
	printf("Posicao: %d\n",p);
	
	
	return 0;
}
