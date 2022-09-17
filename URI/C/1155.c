#include<stdio.h>
#include<stdlib.h>

	int i;
	float a=1;

void main(){
	for(i=2;i<=100;i++){
		a=(float)a+1.0/i;
	}
	printf("%.2f\n",a);
}
