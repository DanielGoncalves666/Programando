#include<stdio.h>
#include<stdlib.h>

int main(){
	int N,M;

	for(;;){
		scanf("%d %d",&N,&M);
		if(N+M == 0)
			break;

		int mat[N][M];
		int regras = 4;
		int soma_user, ok_soma_user = 1, um_problema = 1;
		int *qtd_resol = (int *) calloc(M,sizeof(int)), pelo_menos_um = 1, por_todos = 1;
		for(int i=0; i<N; i++){
			soma_user = 0;
			for(int h=0; h<M; h++){
				scanf("%d",&mat[i][h]);
				soma_user += mat[i][h];//soma quantos o competidor resolveu
				qtd_resol[h] += mat[i][h];//soma quantas vezes um problemas foi resolvido
			}
			
			if(soma_user == M && ok_soma_user == 1){//caso o competidor tiver resolvido todos
				regras--;
				ok_soma_user = 0;
			}

			if(soma_user == 0 && um_problema == 1){//caso houver um competidor que não resolveu nenhum 
				regras--;
				um_problema = 0;
			}
		}

		for(int h=0; h<M; h++){
			if(qtd_resol[h] == 0 && pelo_menos_um == 1){//caso algum problema n tenha sido resolvido por ninguem
				regras--;
				pelo_menos_um = 0;
			}

			if(qtd_resol[h] == N && por_todos == 1){//caso algum problema tenha sido resolvido por todos
				regras--;
				por_todos = 0;
			}
		}

		printf("%d\n", regras);

		free(qtd_resol);
	}

	return 0;
}