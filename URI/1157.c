#include<stdio.h>
#include<stdlib.h>

	int N,i;

void main(){
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		if(N%i==0)
			printf("%d\n",i);
	}
}
