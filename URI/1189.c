#include<stdio.h>
#include<stdlib.h>

	int i,h,k=0,j=11,a=0;
	float M[12][12],soma=0.0,media;
	char c;

void main(){
	scanf("%c",&c);
	for(i=0;i<12;i++){
		for(h=0;h<12;h++){
			scanf("%f",&M[i][h]);
		}
	}
	for(h=0;h<6;h++){
		for(i=0;i<12;i++){
			if(i<=k || i>=j)
				continue;
			soma+=M[i][h];
			a++;
		}
		k++;
		j--;
	}
	if(c=='S'){
		printf("%.1f\n",soma);
	}
	if(c=='M'){
		media=(float)soma/a;
		printf("%.1f\n",media);
	}	
}
