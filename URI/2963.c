#include<stdio.h>
#include<stdlib.h>

int main(){
	int N,num;

	scanf("%d",&N);

	int Carlos = 0;
	for(int i=0; i<N; i++){
		scanf("%d",&num);

		if(Carlos == -1)
			continue;

		if(i == 0)
			Carlos = num;
		else if(Carlos < num){
			Carlos = -1;
			printf("N\n");
		}
	}

	if(Carlos != -1)
		printf("S\n");
		
	return 0;
}