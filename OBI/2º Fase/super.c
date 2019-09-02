#include<stdio.h>
#include<stdlib.h>

int N;

int main(){
	scanf("%d",&N);
	float preco[N], resultado[N];
	int gramas[N], menor;
	
	for(int i=0; i<N; i++){
		scanf("%f %d",&preco[i],&gramas[i]);
		if(gramas[N] == 1000)
			resultado[i] = preco[i];
		else{
			resultado[i] = (preco[i]*1000)/gramas[i];
		}
		if(i == 0)
			menor = i;
		else if(resultado[menor] > resultado[i])
			menor = i;
	}
	printf("%.2f",resultado[menor]);
	
	
	
	return 0;
}
