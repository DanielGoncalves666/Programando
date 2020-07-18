#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int N;

	while(1){
		scanf("%d",&N);
		if(N == 0)
			break;

		printf("1");
		int sequency = 2;
		for(int i=2; i<=N; i++){
			if(i == pow(sequency,2)){
				printf(" %d", i);
				sequency++;
			}
		}
		printf("\n");

	}

	return 0;
}