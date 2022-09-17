#include<stdio.h>

int main(){
	int L,D,K,P,pedagios = 0;

	scanf("%d %d",&L,&D);
	scanf("%d %d",&K,&P);

	pedagios = L / D;

	printf("%d\n",(L * K) + (pedagios*P));

	return 0;
}