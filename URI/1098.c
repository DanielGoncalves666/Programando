#include<stdio.h>
#include<stdlib.h>

	float i,j;
	int h;

void main(){
	for(i=0.0;i<2.1;i+=0.2){
		h=0;
		for(j=i+1;h<3;j+=1){
			if(i>0.0 && i<1.0 || i>1.0 && i<2.0)
				printf("I=%.1lf J=%.1lf\n",i,j);
			else
				printf("I=%.0lf J=%.0lf\n",i,j);
			h++;
		}	
	}
}
