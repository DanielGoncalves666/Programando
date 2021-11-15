#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int N,M,A,B;

	while(1){
		scanf("%d %d",&N,&M);
		if(N + M == 0)
			break;
		
		getchar();
		char str[N][M];

		for(int i=0; i<N; i++){
			for(int h=0; h<M; h++){
				scanf("%c",&str[i][h]);
			}
			getchar();
		}

		scanf("%d %d",&A,&B);

		for(int i=0; i<N; i++){
			for(int a=0; a<A/N; a++){
				for(int h=0; h<M; h++){
					for(int b=0; b<B/M; b++){
						printf("%c",str[i][h]);
					}
				}
				printf("\n");
			}
		}
		printf("\n");
	}

	return 0;
}