#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char string[27];
int N;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%s",string);
		printf("Y\n");
	}

	return 0;
}
