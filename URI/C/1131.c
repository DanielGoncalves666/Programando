#include<stdio.h>
#include<stdlib.h>

int main(){
	int i, g, h, contgre=0, contint=0, empate=0;
	
	do{
		scanf("%d %d",&i,&g);
		if(i == g)
			empate++;
		else if(i > g)
			contint++;
		else
			contgre++;
			
		printf("Novo grenal (1-sim 2-nao)\n");
		scanf("%d",&h);
	}while(h == 1);
	
	printf("%d grenais\n",contgre+contint+empate);
	printf("Inter:%d\n",contint);
	printf("Gremio:%d\n",contgre);
	printf("Empates:%d\n",empate);
	if(contint > contgre)
		printf("Inter venceu mais\n");
	else if(contint < contgre)
		printf("Gremio venceu mais\n");
	else
		printf("Nao houve vencedor\n");
	
	return 0;
}
