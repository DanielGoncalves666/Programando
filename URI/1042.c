#include<stdio.h>
#include<stdlib.h>

int vet[3],vet2[3];

int main()
{
	scanf("%d %d %d",&vet[0],&vet[1],&vet[2]);
	for(int i=0; i<3; i++){
		vet2[i] = vet[i];
	}
	
	for(int i=0; i<2; i++){
		if(vet2[i] > vet2[i+1]){
			int aux = vet2[i];
			vet2[i] = vet2[i+1];
			vet2[i+1] = aux;
			i = -1;
		}
	}
	
	for(int i=0; i<3; i++){
		printf("%d\n",vet2[i]);
	}
	
	printf("\n");
	for(int i=0; i<3; i++){
		printf("%d\n",vet[i]);
	}	
}
