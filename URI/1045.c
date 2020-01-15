#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double A, B, C;

int main(){
	scanf("%lf %lf %lf",&A,&B,&C);
	
	double vet[3] = {A,B,C};
	int fim;
	
	
	do{
		fim = 0;
		for(int n=0; n<2; n++){
			if(vet[n] < vet[n+1]){
				int aux = vet[n];
				vet[n] = vet[n+1];
				vet[n+1] = aux;
				fim = 1;
			}
		}
	}while(fim == 1);
	
	A = vet[0];
	B = vet[1];
	C = vet[2];
	
	
	if(A >= B + C)
		printf("NAO FORMA TRIANGULO\n");
	else{
		if(pow(A,2) == pow(B,2) + pow(C,2))
			printf("TRIANGULO RETANGULO\n");
		else if(pow(A,2) > pow(B,2) + pow(C,2))
			printf("TRIANGULO OBTUSANGULO\n");
		else if(pow(A,2) < pow(B,2) + pow(C,2))
			printf("TRIANGULO ACUTANGULO\n");
	
		if(A == B && B == C)
			printf("TRIANGULO EQUILATERO\n");
		else if(A == B || B == C || A == C)
			printf("TRIANGULO ISOSCELES\n");
	}

	return 0;
}
