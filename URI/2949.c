#include<stdio.h>
#include<stdlib.h>

int N;
int hobbit = 0, humano = 0, anao = 0, elfo = 0, mago = 0;
char string[11], letra;

int main(){
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		scanf("%s %c",string,&letra);
		
		if(letra == 'X')
			hobbit++;
		if(letra == 'M')
			mago++;
		if(letra == 'H')
			humano++;
		if(letra == 'E')
			elfo++;
		if(letra == 'A')
			anao++;
	}
	
	printf("%d Hobbit(s)\n",hobbit);
	printf("%d Humano(s)\n",humano);
	printf("%d Elfo(s)\n",elfo);
	printf("%d Anao(s)\n",anao);
	printf("%d Mago(s)\n",mago);

	return 0;
}
