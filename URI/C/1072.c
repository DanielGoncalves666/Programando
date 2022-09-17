#include<stdio.h>
#include<stdlib.h>

	int N, X, i, a=0, b=0;

void main(){
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&X);
		if(X>=10 && X<=20)
			a++;
		else
			b++;
	}
	printf("%d in\n",a);
	printf("%d out\n",b);
}
