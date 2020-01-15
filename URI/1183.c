#include<stdio.h>
#include<stdlib.h>

	int i=0,h,k=0,a;
	float M[12][12],soma=0.0,media;
	char c;

void main(){
	scanf("%c",&c);
	for(i=0;i<12;i++){
		for(h=0;h<12;h++){
			scanf("%f",&M[i][h]);
		}
	}
	for(i=0;i<12;i++){
		for(h=0;h<12;h++){
			if(h<=k)
				continue;
			soma+=M[i][h];
			a++;
		}
		k++;
	}
	if(c=='S'){
		printf("%.1f\n",soma);
	}
	if(c=='M'){
		media=(float)soma/a;
		printf("%.1f\n",media);
	}	
}
