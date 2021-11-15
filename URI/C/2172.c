#include<stdio.h>

int main(){
	int X;
	unsigned int N;

	for(;;){
		scanf("%d %ud",&X,&N);

		if(X == 0 && N == 0)
			break;

		printf("%d\n",N*X);

	}

	return 0;
}