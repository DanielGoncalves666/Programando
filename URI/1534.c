#include<stdio.h>
#include<stdlib.h>

int N,saida;
int **mat;

int main(){
	for(;;){
		saida = scanf("%d",&N);
		if(saida == -1)
			break;
		
		mat = malloc(N*sizeof(int *));
		for(int a=0; a<N; a++){
			mat[a] = malloc(N*sizeof(int));
		}	
		
		for(int a=0; a<N; a++){
			for(int b=0; b<N; b++){
				if(a == b)
					mat[a][b] = 1;
				else if(b == N - 1 - a)
					mat[a][b] = 2;
				else
					mat[a][b] = 3;
				
			}
		}
		if(N % 2 == 1)
			mat[((N-1)/2)][((N-1)/2)] = 2;
			
		for(int a=0; a<N; a++){
			for(int b=0; b<N; b++){
					printf("%d",mat[a][b]);
			}
			printf("\n");
		}
		
	}
}
