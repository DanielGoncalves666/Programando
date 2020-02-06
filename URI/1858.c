#include<stdio.h>
#include<stdlib.h>

int N, menor;

int main(){
	scanf("%d",&N);
	
	int *vet = malloc(N*sizeof(int));
	
	for(int a = 0; a<N; a++){
		scanf("%d",&vet[a]);
		if(a == 0)
			menor = a + 1;
		else if(vet[a] < vet[menor-1])
			menor = a + 1;
	}
	
	printf("%d\n",menor);


	return 0;
}
