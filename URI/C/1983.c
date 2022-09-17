#include<stdio.h>
#include<stdlib.h>

int N,aluno,a;
float maior,b;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d %f",&a,&b);
		
		if(i == 0){
			aluno = a;
			maior = b;
		}else if(maior < b){
			aluno = a;
			maior = b;
		}
	}

	if(maior >= 8.0){
		printf("%d\n",aluno);
	}else{
		printf("Minimum note not reached\n");
	}

	return 0;
}
