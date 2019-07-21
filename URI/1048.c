#include<stdio.h>
#include<stdlib.h>

float N,fim,reajuste;
int p;

int main(){
	scanf("%f",&N);
	if(N>=0.0 && N<=400.00){
		reajuste=N*0.15;
		fim=N+reajuste;
		p=15;
	}else if(N>=400.01 && N<=800.00){
		reajuste=N*0.12;
		fim=N+reajuste;
		p=12;
	}else if(N>=800.01 && N<=1200.00){
		reajuste=N*0.10;
		fim=N+reajuste;
		p=10;
	}else if(N>=1200.01 && N<=2000.00){
		reajuste=N*0.07;
		fim=N+reajuste;
		p=7;
	}else if(N>2000.00){
		reajuste=N*0.04;
		fim=N+reajuste;
		p=4;
	}
	printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %d %%\n",fim,reajuste,p);
	return 0;
}
