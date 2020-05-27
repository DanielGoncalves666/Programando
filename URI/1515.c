#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N;

int main(){
	for(;;){
		scanf("%d",&N);
		if(N == 0)
			break;
		
		char string[N][51];
		int ano, demora, chegou[N],primeiro = 0;
		for(int i=0; i<N; i++){
			scanf("%s",string[i]);
			scanf("%d %d",&ano,&demora);
			chegou[i] = ano - demora;
			
			if(i > 0){
				if(chegou[i] < chegou[primeiro])
					primeiro = i;
			}
		}
		printf("%s\n",string[primeiro]);
	
	}

	return 0;
}
