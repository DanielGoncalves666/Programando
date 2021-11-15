#include<stdio.h>
#include<stdlib.h>

int N,M,a=0,b=0,cont;

int main(){
	scanf("%d %d",&N,&M);
	int vet[N][M];
	for(int i=0; i<N; i++){
		for(int h=0; h<M; h++){
			scanf("%d",&vet[i][h]);
		}
	}
	
	for(int i=1; i<N-1; i++){
		for(int h=1; h<M-1; h++){
			if(vet[i][h] == 42){
				cont = 0;
				for(int j=-1;j<2;j++){
					for(int l=-1;l<2;l++){
						if(i+j == i && h+l == h)
							continue;
						if(vet[i+j][h+l] == 7)
							cont++;
					}
				}
				if(cont == 8){
					a = i + 1;
					b = h + 1;
					goto aqui;
				}
			}
		}
	}
	aqui:
	printf("%d %d\n",a,b);

	return 0;
}
