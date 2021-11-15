#include<stdio.h>
#include<stdlib.h>

int N,qtd = 0, resp;

int main(){
	scanf("%d",&N);
	for(int i=0; i<5; i++){
		scanf("%d",&resp);
		
		if(N == resp)
			qtd++;
	}
	
	printf("%d\n",qtd);

	return 0;
}
