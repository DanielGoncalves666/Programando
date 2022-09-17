#include<stdio.h>
#include<stdlib.h>

int N,M;
int lin_eu, col_eu, lin_poke, col_poke;

int main(){
	while(scanf("%d %d",&N,&M) != EOF){
		int cidade[N][M];
		int qtd = 0;
		for(int i=0; i<N; i++){
			for(int h=0; h<M; h++){
				scanf("%d",&cidade[i][h]);
				if(cidade[i][h] == 1){
					lin_eu = i;
					col_eu = h;
				}
				if(cidade[i][h] == 2){
					lin_poke = i;
					col_poke = h;
				}
			}
		}
		while(lin_eu != lin_poke || col_eu != col_poke){
			if(lin_eu > lin_poke){
				lin_eu--;
				qtd++;
			}else if(lin_eu < lin_poke){
				lin_eu++;
				qtd++;
			}else if(lin_eu == lin_poke){
				if(col_eu > col_poke){
					col_eu--;
					qtd++;
				}else if(col_eu < col_poke){
					col_eu++;
					qtd++;
				}
			}
		}
		printf("%d\n",qtd);
	}
	
	return 0;
}
