#include<stdio.h>
#include<stdlib.h>

int N,qtd,numero;
float valor = 0.0;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d %d",&numero,&qtd);
		if(numero == 1001){
			valor += 1.50 * qtd;
		}else if(numero == 1002){
			valor += 2.50 * qtd;
		}else if(numero == 1003){
			valor += 3.50 * qtd;
		}else if(numero == 1004){
			valor += 4.50 * qtd;
		}else if(numero == 1005){			
			valor += 5.50 * qtd;
		}
	}
	printf("%.2f\n",valor);

	return 0;
}
