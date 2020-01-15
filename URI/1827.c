#include<stdio.h>
#include<stdlib.h>

int N;
int **mat;

int main(){
	for(;scanf("%d",&N) != -1;){
		mat = malloc(N*sizeof(int *));
		for(int a=0; a<N; a++){
			mat[a] = malloc(N*sizeof(int));
		}

		for(int a=0; a<N; a++){
			for(int b=0; b<N; b++){
				if(a >= N/3 && a < N - (N/3)){
					if(b >= N/3 && b < N - (N/3))
						mat[a][b] = 1;
				}else if(a == b)
					mat[a][b] = 2;
				else if(b == N - 1 - a)
					mat[a][b] = 3;
				else
					mat[a][b] = 0;
			}
		}
		mat[(N-1)/2][(N-1)/2] = 4;
		
		for(int a=0; a<N; a++){
			for(int b=0; b<N; b++){
				printf("%d",mat[a][b]);
			}
			printf("\n");
		}
		printf("\n");
		
	}
	return 0;
}
