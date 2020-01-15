#include<stdio.h>
#include<stdlib.h>

	int N,i,a,b,raio;

int main(){
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d",&a,&b);
		raio=a+b;
		printf("%d\n",raio);
	}

	return 0;
}
