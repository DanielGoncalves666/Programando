#include<stdio.h>
#include<stdlib.h>

int T,bonus;
int A1,A2,D1,D2,L1,L2;

int main(){
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		scanf("%d",&bonus);
		scanf("%d %d %d",&A1,&D1,&L1);
		scanf("%d %d %d",&A2,&D2,&L2);
		
		int golpe1 = (A1+D1)/2;
		int golpe2 = (A2+D2)/2;
		
		if(L1%2 == 0)
			golpe1 += bonus;
			
		if(L2%2 == 0)
			golpe2 += bonus;
			
		if(golpe1 == golpe2)
			printf("Empate\n");
		else if(golpe1 > golpe2)
			printf("Dabriel\n");
		else
			printf("Guarte\n");
	}

	return 0;
}
