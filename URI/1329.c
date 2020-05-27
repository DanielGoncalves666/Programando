#include<stdio.h>
#include<stdlib.h>

int	main(){
	int N,R;
	int maria, joao;

	for(;;){
		maria = 0;
		joao = 0;
		
		scanf("%d",&N);
		if(N == 0)
			break;
			
		for(int i=0; i<N; i++){
			scanf("%d",&R);
			
			if(R == 0)
				maria++;		
			else
				joao++;
		}
		printf("Mary won %d times and John won %d times\n",maria,joao);
	}
}
