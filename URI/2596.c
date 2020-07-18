#include<stdio.h>
#include<math.h>

int main(){
	int N,T;
	scanf("%d",&N);

	for(int i=0; i<N; i++){
		scanf("%d",&T);
		int aux = 1,total = T;
		for(int h=1; h<=T; h++){
			if(h == pow(aux,2)){
				total--;
				aux++;
			}
		}
		printf("%d\n",total);
	}

	return 0;
}