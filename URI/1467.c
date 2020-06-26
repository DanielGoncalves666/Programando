#include<stdio.h>

int main(){
	int A,B,C;

	while(scanf("%d %d %d",&A,&B,&C) != EOF){
		int soma = A+B+C;
		if(soma == 0 || soma == 3){
			printf("*\n");
		}else if(soma == 1){
			if(A == 1)
				printf("A\n");
			else if(B == 1)
				printf("B\n");
			else
				printf("C\n");
		}else if(soma == 2){
			if(A == 0)
				printf("A\n");
			else if(B == 0)
				printf("B\n");
			else
				printf("C\n");
		}
	}

	return 0;
}