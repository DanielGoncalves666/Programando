#include<stdio.h>
#include<stdlib.h>

int p, J1, j2, r, a, ganhador;

int main(){
	scanf("%d %d %d %d %d",&p,&J1,&j2,&r,&a);
	if(p == 0 && (J1+j2)%2 == 1)
		ganhador = 1;
	else if(p == 0 && (J1+j2)%2 == 0)
		ganhador = 2;
	else if(p == 1 && (J1+j2)%2 == 0)
		ganhador = 1;
	else if(p == 1 && (J1+j2)%2 == 1)
		ganhador = 2;
		
	if(r == 1 && a == 0)
		ganhador = 1;
	else if(r == 1 && a == 1)
		ganhador = 2;
	else if(r == 0 && a == 1)
		ganhador = 1;
	
	printf("Jogador %d ganha!\n",ganhador);


	return 0;
}
