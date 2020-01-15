#include<stdio.h>
#include<stdlib.h>

int N;
int **mat;

void imprimir(int **mat);
void preencheMatriz(int **mat, int aux);
void liberar(int **mat);

int main(){

	for(;;){
		scanf("%d",&N);
		if(N == 0)
			break;
			
		mat = malloc(N*sizeof(int *));
		for(int i=0; i<N; i++){
			mat[i] = malloc(N*sizeof(int));
		}
		
		preencheMatriz(mat,1);
		liberar(mat);
	}


	return 0;
}

void preencheMatriz(int **mat, int aux){
	for(int a = 0; a < N; a++){
		for(int b = 0; b < N; b++){
			if(a == b){
				mat[a][b] = aux;
				for(int c = b + 1; c < N; c++)
					mat[a][c] = mat[a][c - 1] + 1;
				for(int c = b - 1; c >= 0; c--)
				 	mat[a][c] = mat[a][c + 1] + 1;
			}
		}
	}
	imprimir(mat);
}

void imprimir(int **mat){
	for(int a=0; a<N; a++){
		for(int b=0; b<N; b++){
			if(b == 0)
				printf("%3d",mat[a][b]);
			else
				printf(" %3d",mat[a][b]);
		}
		printf("\n");
	}
	printf("\n");

}

void liberar(int **mat){
	for(int a=0; a<N; a++){
		free(mat[a]);
	}
	free(mat);

}
