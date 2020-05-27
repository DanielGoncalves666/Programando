#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N;
char string[102];

int main(){
	scanf("%d ",&N);
	for(int i=0; i<N; i++){
		fgets(string,102,stdin);
	}
	printf("Ciencia da Computacao\n");
	return 0;
}
