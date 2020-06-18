#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int N;

int main(){
	while(scanf("%d",&N) != EOF){
		if(N % 100 == 0)
			printf("%d\n",N/100);
		else
			printf("%d\n",(int) floor(N/100)+1);
	}

	return 0;
}
