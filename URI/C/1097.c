#include<stdio.h>
#include<stdlib.h>

	int i=1,j=7,h;

void main(){
	for(;;){
		for(h=0;h<3;h++){
			printf("I=%d J=%d\n",i,j);
			j--;
		}
		if(i==9 && j==12)
			break;
		i+=2;
		j=i+6;
	}
}
