#include<stdio.h>

int main(){
	int N,saldo,num;
	
	scanf("%d %d",&N,&saldo);

	int menor = saldo;
	for(int i=0; i<N; i++){
		scanf("%d",&num);
		saldo += num;

		if(saldo < menor)
			menor = saldo;
	}

	printf("%d\n",menor);

	return 0;
}