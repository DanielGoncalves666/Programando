#include<stdio.h>
#include<stdlib.h>

int N,num,anterior,queda=0;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N;i++){
		scanf("%d",&num);
		if(i == 0)
			anterior = num;
		else{
			if(queda == 0 && anterior > num){
				queda = i + 1;
			}
			anterior = num;
		}
	}
	printf("%d\n",queda);

	return 0;
}
