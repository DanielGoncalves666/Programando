#include<stdio.h>
#include<string.h>

int main(){
	int N;
	char string[10001];

	scanf("%d",&N);
	getchar();

	for(int i=0; i<N; i++){
		scanf("%s",string);
		printf("%.2f\n",strlen(string)*0.01);
	}

	return 0;
}