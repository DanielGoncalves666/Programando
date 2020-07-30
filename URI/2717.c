#include<stdio.h>

int main(){
	int N, A, B;

	scanf("%d %d %d",&N,&A,&B);

	if(N >= A + B)
		printf("Farei hoje!\n");
	else
		printf("Deixa para amanha!\n");

	return 0;
}