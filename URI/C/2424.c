#include<stdio.h>

int main(){
	int A,B;

	scanf("%d %d",&A,&B);

	if(A >= 0 && A <= 432){
		if(B >= 0 && B <= 468){
			printf("dentro\n");
		}else
			printf("fora\n");
	}else{
		printf("fora\n");
	}


	return 0;
}