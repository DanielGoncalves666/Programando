#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int A,B,C,tamanho,casa;
double porcentagem;

int main(){
	for(;;){
		scanf("%d",&A);
		if(A == 0)
			break;
		scanf("%d %d",&B,&C);
		
		casa = A * B;
		porcentagem = 100.0/C;
		
		tamanho = (int) sqrt(casa*porcentagem);
		
		printf("%d\n",tamanho);
	}

	return 0;
}
