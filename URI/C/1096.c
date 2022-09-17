#include<stdio.h>
#include<stdlib.h>

	int i=1,j=7,h,k;

void main(){
	for(h=0;;){
		printf("I=%d J=%d\n",i,j);
		h++;
		j--;
		if(i==9 && h==3)
			break;
		if(h==3){
			h=0;
			j=7;
			i+=2;
		}
	}
}
