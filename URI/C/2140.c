#include<stdio.h>
#include<stdlib.h>

int N,M,troco,qtd;

int main(){
	for(;;){
		scanf("%d %d",&N,&M);
		if(N+M == 0)
			break;
		troco = M - N;
		qtd = 0;
		
		if(troco >= 100){
			troco -= 100;
			qtd++;
		}
		
		if(troco >= 50){
			troco -= 50;
			qtd++;
		}
		
		if(troco >= 20){
			troco -= 20;
			qtd++;
		}
		
		if(troco >= 10){
			troco -= 10;
			qtd++;
		}
		
		if(troco >= 5){
			troco -= 5;
			qtd++;
		}
		
		if(troco >= 2){
			troco -= 2;
			qtd++;
		}
		
		if(troco != 0)
			qtd = 0;
		
		if(qtd == 2)
			printf("possible\n");
		else
			printf("impossible\n");
	}

	return 0;
}
