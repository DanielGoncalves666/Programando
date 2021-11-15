#include<stdio.h>
#include<stdlib.h>

int N;
int **mat;

void imprimir(int **mat);
void preencheMatriz(int **mat, int aux);
int determinaQtdAlgarismos(int num);
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
			if(a == 0 && b == 0)
				mat[a][b] = 1;
			else if(a > 0 && b == 0)
				mat[a][b] = mat[a-1][b+1];
			else
				mat[a][b] = mat[a][b-1]*2;
		}
	}
	imprimir(mat);
}

void imprimir(int **mat){
	int T = determinaQtdAlgarismos(mat[N-1][N-1]);
	
	for(int a=0; a<N; a++){
		for(int b=0; b<N; b++){
			if(b == 0)
				printf("%*d",T,mat[a][b]);
			else
				printf(" %*d",T,mat[a][b]);
		}
		printf("\n");
	}
	printf("\n");

}

int determinaQtdAlgarismos(int num){
	float num_aux = num;
	int qtd = 1;
	
	for(;;){
		num_aux /= 10;
		if(num_aux >= 1.0)
			qtd++;
		else 
			return qtd;	
	}
}

void liberar(int **mat){
	for(int a=0; a<N; a++){
		free(mat[a]);
	}
	free(mat);

}
