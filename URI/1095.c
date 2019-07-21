#include<stdio.h>
#include<stdlib.h>

	int i=1,j=60;

void main(){
	for(;j>=0;){
		printf("I=%d J=%d\n",i,j);
		i+=3;
		j-=5;
	}
}
