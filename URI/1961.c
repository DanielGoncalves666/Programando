#include<stdio.h>
#include<stdlib.h>

int pulo, canos, win=1;

int main(){
	scanf("%d %d",&pulo,&canos);
	int vet[canos];
	for(int i=0; i<canos;i++){
		scanf("%d",&vet[i]);
		if(i > 0){
			if(vet[i] - vet[i-1] > pulo || vet[i] - vet[i-1] < pulo*-1)
				win = 0;
		}
	}
	if(win == 0)
		printf("GAME OVER\n");
	else
		printf("YOU WIN\n");
	
	return 0;
}
