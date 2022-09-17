#include<stdio.h>

int main(){
	int N,A;

	scanf("%d",&N);

	for(int i=0; i<N; i++){
		scanf("%d",&A);
		
		if(A % 2 == 0)
			printf("1\n");
		else
			printf("9\n");
	}

	return 0;
}