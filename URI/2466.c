#include<stdio.h>
#include<stdlib.h>

int main(){
	int N;
	scanf("%d",&N);

	int vet[N];

	for(int i=0; i<N; i++){
		scanf("%d",&vet[i]);
	}

	int aux = N;
	for(int i=0; i<N-1; i++){
		for(int h=0; h<aux-1; h++){
			if(vet[h] == vet[h+1])
				vet[h] = 1;
			else
				vet[h] = -1;
		}
		aux--;
	}

	if(vet[0] == 1)
		printf("preta\n");
	else
		printf("branca\n");

	return 0;
}