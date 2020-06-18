#include<stdio.h>
#include<stdlib.h>

int N;
double dados[2][3] = {0,0,0,0,0,0},S,B,A;
char nome[10];

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%s",nome);
		scanf("%lf %lf %lf",&S,&B,&A);
		dados[0][0] += S;
		dados[0][1] += B;
		dados[0][2] += A;
		scanf("%lf %lf %lf",&S,&B,&A);
		dados[1][0] += S;
		dados[1][1] += B;
		dados[1][2] += A;
	}
	printf("Pontos de Saque: %.2f %%.\n",dados[1][0]/dados[0][0]*100);
	printf("Pontos de Bloqueio: %.2f %%.\n",dados[1][1]/dados[0][1]*100);
	printf("Pontos de Ataque: %.2f %%.\n",dados[1][2]/dados[0][2]*100);

	return 0;
}
