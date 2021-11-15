#include<stdio.h>
#include<stdlib.h>

int main(){
	int M, A, B,total;
	char simbolo;

	scanf("%d",&M);
	scanf("%d %c %d",&A,&simbolo,&B);

	if(simbolo == '+')
		total = A + B;
	else if(simbolo == '*')
		total = A * B;

	if(M >= total)
		printf("OK\n");
	else
		printf("OVERFLOW\n");
	

	return 0;
}