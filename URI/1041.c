#include<stdio.h>
#include<stdlib.h>

	float x,y;

void main(){
	scanf("%f %f",&x,&y);
	if(x==0.0 && y==0.0)
		printf("Origem\n");
	if(x==0.0 && y!=0.0){
		printf("Eixo Y\n");
		exit(0);
	}
	if(x!=0.0 && y==0.0){
		printf("Eixo X\n");
		exit(0);
	}
	if(x>0.0){
		if(y>0.0)
			printf("Q1\n");	
		else
			printf("Q4\n");
	}else if(x<0.0){
		if(y>0.0)
			printf("Q2\n");
		else 
			printf("Q3\n");
	}
}
