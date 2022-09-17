#include<stdio.h>
#include<stdlib.h>

	int i,h,N;

void main(){
	scanf("%d",&N);
	for(i=0;i<1000;i++){
		if(i%N==0)
			h=0;
		printf("N[%d] = %d\n",i,h);
		h++;
	}
}
