#include<stdio.h>
#include<stdlib.h>

	int L,i,h;
	float M[12][12],soma=0.0,media;
	char c;

void main(){
	scanf("%d",&L);
	scanf(" %c",&c);
	for(i=0;i<12;i++){
		for(h=0;h<12;h++){
			scanf("%f",&M[i][h]);
		}
	}
	for(h=0;h<12;h++){
		soma+=(float)M[L][h];
	}
	if(c=='S'){
		printf("%.1f\n",soma);
	}
	if(c=='M'){
		media=(float)soma/12;
		printf("%.1f\n",media);
	}
	
}
