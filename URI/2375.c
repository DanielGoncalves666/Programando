#include<stdio.h>

int main(){
	int N, A, B, C;

	scanf("%d",&N);
	scanf("%d %d %d",&A,&B,&C);

	if(A < N || B < N || C < N)
		printf("N\n");
	else
		printf("S\n");

	return 0;
}