#include<stdio.h>

int main(){
	int V1, V2, E1, E2, S1, S2;

	scanf("%d %d %d %d %d %d", &V1, &E1, &S1, &V2, &E2, &S2);

	int um = V1*3 + E1, dois = V2*3 + E2;

	if(um > dois)
		printf("C\n");
	else if(um < dois)
		printf("F\n");
	else if(um == dois){
		if(S1 > S2)
			printf("C\n");
		else if(S1 < S2)
			printf("F\n");
		else if(S1 == S2)
			printf("=\n");
	}
	
	return 0;
}