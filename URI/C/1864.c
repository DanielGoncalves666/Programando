#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N;
char string[35] = "LIFE IS NOT A PROBLEM TO BE SOLVED";

int main(){
	scanf("%d",&N);

	for(int i=0;i<N;i++){
		printf("%c",string[i]);
	}
	printf("\n");

	return 0;
}
