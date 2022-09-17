#include<stdio.h>
#include<stdlib.h>

	int a, i;
	float x,y,z,media;

void main(){
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%f %f %f",&x,&y,&z);
		media=(2*x+3*y+5*z)/10;
		printf("%.1f\n",media);
	}
}
