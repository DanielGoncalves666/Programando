#include<stdio.h>
#include<stdlib.h>

	int a;

void main(){

	for(;scanf("%d",&a)==1;){
		if(a==0)
			printf("vai ter copa!\n");
		else
			printf("vai ter duas!\n");
	}
}
