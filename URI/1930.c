#include<stdio.h>

int soma=0, T;

int main(){
	for(int i=0;i<4;i++){
		scanf("%d ",&T);
		soma += T;
	}
	printf("%d\n",soma-3);

	return 0;
}
