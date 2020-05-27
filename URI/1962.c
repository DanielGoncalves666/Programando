#include<stdio.h>
#include<stdlib.h>

int N,ano;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&ano);
		ano = 2015 - ano;
		if(ano > 0)
			printf("%d D.C.\n",ano);
		else{
			ano = ano * -1;
			ano += 1;
			printf("%d A.C.\n",ano);
		}
		
	}

	return 0;
}
